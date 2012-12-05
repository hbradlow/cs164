/* -*- mode: C++; c-file-style: "stroustrup"; indent-tabs-mode: nil; -*- */

/* stmts.cc: AST subclasses related to statements and modules. */

/* Authors:  YOUR NAMES HERE */

#include <iostream>
#include <sstream>
#include "apyc.h"
#include "ast.h"
#include "apyc-parser.hh"

using namespace std;



/***** WHILE ******/
/* while Cond E1
 */
//wskinner
class While_AST : public AST_Tree {
  protected:
  
    NODE_CONSTRUCTORS(While_AST, AST_Tree);
    
    void outerCodeGen(ostream& out, int depth) {
        writeIndented(out, depth);
        out << "while(true){\n";
        child(0)->memCodeGen(out,depth);
        writeIndented(out, depth);
        out << "if((*";
        child(0)->valueCodeGen(out, depth);
        out << ")==false){" << endl;
        writeIndented(out, depth);
        out << "break;" << endl;
        writeIndented(out, depth+1);
        out << "}\n";
        child(1)->outerCodeGen(out, depth);
        writeIndented(out, depth);
        out << "}" << endl;
    }
};
NODE_FACTORY (While_AST, WHILE);

/***** IF *****/

/* if Cond: E1, else : E2
 */
//wskinner
class If_AST : public AST_Tree {
protected:

    NODE_CONSTRUCTORS (If_AST, AST_Tree);
    
    //wskinner
    void innerCodeGen(ostream& out, int depth) {
        child(0)->memCodeGen(out,depth);
        writeIndented(out,depth);
        out << "if ((*";
        child(0)->valueCodeGen(out, depth);
        out << ")==true) {" << endl;
        child(1)->outerCodeGen(out, depth);
        writeIndented(out, depth);
        out << "}" << endl;
        writeIndented(out, depth);
        out << "else {" << endl;
        child(2)->outerCodeGen(out, depth);
        writeIndented(out, depth);
        out << "}" << endl;
    }
    void outerCodeGen(ostream& out, int depth){
        writeIndented(out, depth);
        innerCodeGen(out,depth);
    }
};
NODE_FACTORY (If_AST, IF);

/***** PRINT *****/

/**********/
class Print_AST : public AST_Tree {
protected:

    NODE_CONSTRUCTORS (Print_AST, AST_Tree);

    AST_Ptr resolveTypes (Decl* context, int& resolved, int& ambiguities) {
        AST_Tree::resolveTypes (context, resolved, ambiguities);
        if (!child (0)->isMissing ()) {
            if (!child (0)->getType ()->unify (fileDecl->asType ())) {
                error (this, "target argument in print must be file");
            }
        }
        return this;
    }

    //hbradlow
    void outerCodeGen(ostream& out,int i){
        writeIndented(out,i);
        for_each_child(c,child(1)){
            if (!c->isCall())
            {
            c->valueCodeGen(out,i);
            out << ".print(cout);\n";
            out << "cout << endl;"; 
            }else 
            {
            c->outerCodeGen(out, i);
            }
        } end_for;
    }
};
NODE_FACTORY (Print_AST, PRINT);




/*****   PRINTLN   *****/

/** A print statement without trailing comma. */
class Println_AST : public Print_AST {
protected:

    NODE_CONSTRUCTORS (Println_AST, Print_AST);

    const char* externalName () {
	return "println";
    }

    //hbradlow
    void outerCodeGen(ostream& out,int i){
        for_each_child(c,child(1)){
            c->memCodeGen(out,i);
        } end_for;
        writeIndented(out,i);
        for_each_child(c,child(1)){
            if(c_i_!=0)
                out << "cout << ' ';";
            out << "(";
            if (c->isCall())
            {
            out << "(";
            c->getType()->binding()->innerCodeGen(out,i);
            if(c->getType()->binding()->needsPointer())
                out << "*";
            out << ")";
            }
            c->valueCodeGen(out,i);
            out << ")->print(cout); ";
        } end_for;
        out << "cout << endl;\n"; 
    }

};

NODE_FACTORY (Println_AST, PRINTLN);

/***** STMT_LIST *****/

/** A list of statements. */
class StmtList_AST : public AST_Tree {
protected:

    NODE_CONSTRUCTORS (StmtList_AST, AST_Tree);
  
    //wskinner
    void outerCodeGen(ostream& out, int depth) {
      writeIndented(out, depth);
      for_each_child(c, this) {
        c->outerCodeGen(out, depth);
      } end_for;
    }

    AST_Ptr doOuterSemantics () {
        for_each_child_var (c, this) {
            c = c->doOuterSemantics ();
        } end_for;
        return this;
    }

};

NODE_FACTORY (StmtList_AST, STMT_LIST);


/***** DEF *****/

/** def ID(...): ... */
class Def_AST : public AST_Tree {
protected:

    NODE_CONSTRUCTORS (Def_AST, AST_Tree);

    Decl* getDecl (int k = 0) {
        return child (0)->getDecl ();
    }

    void freezeDecls (bool frozen) {
        Decl* me = getDecl ();
        if (me != NULL)
            me->setFrozen (frozen);
        child (3)->freezeDecls (frozen);
    }

    void collectDecls (Decl* enclosing) {
        AST_Ptr id = child (0);
        AST_Ptr params = child (1);
        AST_Ptr returnType = child (2);
        AST_Ptr body = child (3);
        string name = id->as_string ();
        if (undefinable (name)) {
            error (this, "may not define %s as a function", name.c_str ());
        }
        Decl* me = enclosing->addDefDecl(child(0), params->arity ());
        id->addDecl (me);
        params->collectDecls (me);
        params->collectTypeVarDecls (me);
        returnType->collectTypeVarDecls (me);
        body->collectDecls (me);
    }

    AST_Ptr resolveSimpleIds (const Environ* env) {
        child (3)->resolveSimpleIds (getDecl ()->getEnviron ());
        return this;
    }

    AST_Ptr convertNone (bool) {
        replace (3, child (3)->convertNone (false));
        return this;
    }

    AST_Ptr resolveTypes (Decl* context, int& resolved, int& ambiguities) {
        Decl* me = getDecl ();
        Type_Ptr funcType = me->getType ()->binding ();
        AST_Ptr returnType = child (2);
        AST_Ptr body = child (3);
        AST_Ptr formals = child (1);
        formals->resolveTypes (me, resolved, ambiguities);
        if (!returnType->isMissing ()) {
            if (!funcType->returnType ()->unify (returnType->asType ())) 
                error (this, "inconsistent return type");
        }
        for (size_t i = 0; i < formals->arity (); i += 1) {
            if (!formals->child (i)->getType ()
                ->unify (funcType->paramType (i))) {
                error (this, "inconsistent parameter type");
            }
        }
        body->resolveTypes (me, resolved, ambiguities);
        assert ((int) me->getType ()->binding ()->numParams () ==
                (int) formals->arity ());
        return this;
    }

    //hbradlow
    void closureCodeGen(ostream& out, int i,string closure){
        writeComment(out,i,"-------------start----------------");
        writeComment(out,i,"Create the closure for a function");

        writeComment(out,i,"Create the vector of argument names");
        writeIndented(out,i);
        out << "vector<string> ";
        child(0)->innerCodeGen(out, i); 
        out << child(0)->getDecl()->getIndex() << "__VECTOR = vector<string>();\n";
        for_each_child(c,child(1)){
            writeIndented(out,i);
            child(0)->innerCodeGen(out, i); 
            out << child(0)->getDecl()->getIndex() << "__VECTOR.push_back(\"";
            c->innerCodeGen(out,i);
            out << "\");\n";
        } end_for;

        writeComment(out,i,"Create the closure");

        writeIndented(out,i);
        child(0)->innerCodeGen(out,i);
        out << "__" << child(0)->getDecl()->getIndex();
        out << "_CLOSURE* ";

        child(0)->innerCodeGen(out, i); 
        out << "__" << child(0)->getDecl()->getIndex();
        out << "_closure = new ";

        child(0)->innerCodeGen(out,i);
        out << "__" << child(0)->getDecl()->getIndex();
        out << "_CLOSURE (";

        out << "new Frame(";
        out << closure;
        out << "frame),";
        child(0)->innerCodeGen(out, i);
        out << child(0)->getDecl()->getIndex() << "__VECTOR);\n";
        addToStaticFrame(out, i);
        writeComment(out,i,"-------------end----------------");

        for_each_child(c,this){
            stringstream ss;
            child(0)->innerCodeGen(ss, i); 
            ss << "__" << child(0)->getDecl()->getIndex();
            ss << "_closure->";
            c->closureCodeGen(out,i+1,ss.str());
        } end_for;
    }
    //hbradlow
    void forwardDefCodeGen(ostream& out,int i){
        for_each_child(c,this){
            c->forwardDefCodeGen(out,i);
        } end_for;

        writeIndented(out,i);
        /*getDecl()->getType()->child(0)->asType()->binding()->innerCodeGen(out,i);
        if(getDecl()->getType()->child(0)->asType()->binding()->needsPointer())
            out << "*";
        */
        out << "void*";
        out << " ";
        child(0)->innerCodeGen(out,i);
        out << "__" << child(0)->getDecl()->getIndex();
        out << "(";
        out << "Frame* frame";
        out << ");\n";

        writeIndented(out,i);
        out << "class ";
        child(0)->innerCodeGen(out,i);
        out << "__" << child(0)->getDecl()->getIndex();
        out << "_CLOSURE : public Closure{\n";
        writeIndented(out,i);
        out << "public:\n";
        writeIndented(out,i+1);
        child(0)->innerCodeGen(out,i);
        out << "__" << child(0)->getDecl()->getIndex();
        out << "_CLOSURE(";
        out << "Frame* frame,vector<string> args){\n";
        writeIndented(out,i+2);
        out << "fp = ";
        child(0)->innerCodeGen(out,i);
        out << "__" << child(0)->getDecl()->getIndex();
        out << ";\n";
        writeIndented(out,i+2);
        out << "this->frame = frame;\n";
        writeIndented(out,i+2);
        out << "this->args = args;\n";
        writeIndented(out,i+1);
        out << "}\n";

        writeIndented(out,i);
        out << "};\n";
    }
    //hbradlow
    void defCodeGen(ostream& out,int i){
        for_each_child(c,this){
            c->defCodeGen(out,i);
        } end_for;

        writeComment(out,i,"----------------------------start--------------------");
        writeComment(out,i,"Function stuff");

        writeIndented(out,i);
        /*
        getDecl()->getType()->child(0)->asType()->binding()->innerCodeGen(out,i);
        if(getDecl()->getType()->child(0)->asType()->binding()->needsPointer())
            out << "*";
        */
        out << "void*";
        out << " ";
        child(0)->innerCodeGen(out,i);
        out << "__" << child(0)->getDecl()->getIndex();
        out << "(";
        out << "Frame* frame";
        out << "){\n";
        for_each_child(c,child(3)){
            c->outerCodeGen(out,i+1);
        } end_for;
        writeIndented(out,i);
        out << "}\n";
        writeComment(out,i,"----------------------------end----------------------");

    }
};

NODE_FACTORY (Def_AST, DEF);

/***** METHOD *****/

/**  def ID(...): ... (in class)     */
class Method_AST : public Def_AST {
protected:

    NODE_CONSTRUCTORS (Method_AST, Def_AST);

    void collectDecls (Decl* enclosing) {
        AST_Ptr params = child (1);
        if (params->arity () == 0) {
            error (this, "method must have at least one parameter");
            params->insert (0, make_id ("__self__", loc ()));
        }
        Def_AST::collectDecls (enclosing);
    }


};

NODE_FACTORY (Method_AST, METHOD);


    

/***** FORMALS_LIST *****/

/** ... (E1, ...)  */
class FormalsList_AST : public AST_Tree {
protected:

    NODE_CONSTRUCTORS (FormalsList_AST, AST_Tree);

    void collectDecls (Decl* enclosing) {
        for_each_child (c, this) {
            AST_Ptr id = c->getId ();
            string name = id->as_string ();
            if (undefinable (name))
                error (this, "may not use %s as a parameter", name.c_str ());
            c->addDecl (enclosing->addParamDecl(id, c_i_));
        } end_for;

        for_each_child (c, this) {
            c->collectTypeVarDecls (enclosing);
        } end_for;
    }
    
    //hbradlow
    void innerCodeGen(ostream& out,int i){
        for_each_child(c,this){
            if(c_i_!=0){
                out << ",";
            }
            c->getType()->binding()->innerCodeGen(out,i);
            if(c->getType()->binding()->needsPointer())
                out << "*";
            out << " ";
            c->innerCodeGen(out,i);
        } end_for;
    }
    //hbradlow
    void outerCodeGen(ostream& out,int i){
        writeIndented(out,i);
        innerCodeGen(out,i);
        out << ";\n";
    }

};

NODE_FACTORY (FormalsList_AST, FORMALS_LIST);





/***** CLASS *****/

/** class ID of [...]: ...  */
class Class_AST : public AST_Tree {
protected:

    NODE_CONSTRUCTORS (Class_AST, AST_Tree);

    Decl* getDecl (int k = 0) {
        return child (0)->getDecl ();
    }

    void collectDecls (Decl* enclosing) {
        AST_Ptr id = child (0);
        string name = id->as_string ();
        AST_Ptr params = child (1);
        AST_Ptr body = child (2);
        const Environ* env = enclosing->getEnviron ();

        if (undefinable (name)) {
            error (this, "may not define %s as a function", name.c_str ());
        }

        Decl* me = makeClassDecl (name, params);

        if (env->find_immediate (name) != NULL) {
            error (id, "attempt to redefine %s", name.c_str ());
        } else {
            enclosing->addMember (me);
        }

        setBuiltinDecl (me);

        id->addDecl (me);
        params->collectDecls (me);
        body->collectDecls (me);

        if (me->getEnviron ()->find_immediate ("__init__") == NULL)
            addInit ();
    }

    AST_Ptr resolveSimpleIds (const Environ* env) {
        child (2)->resolveSimpleIds (getDecl ()->getEnviron ());
        return this;
    }

    AST_Ptr convertNone (bool) {
        replace (2, child (2)->convertNone (false));
        return this;
    }

    AST_Ptr resolveTypes (Decl* context, int& resolved, int& ambiguities) {
        replace (2, child (2)->resolveTypes (getDecl (), resolved, ambiguities));
        return this;
    }
    //hbradlow
    void outerClassCodeGen(ostream& out,int i,AST_Ptr c){
        for_each_child(c,child(2)){
            c->closureCodeGen(out,i);
        } end_for;
        /*
        for_each_child(c,child(2)){
            c->innerClassCodeGen(out,i,this);
        } end_for;
        */
    }
    //hbradlow
    void classDefCodeGen(ostream& out,int i){
        if(child(1)->arity()){
            writeIndented(out,i);
            out << "template<";
            for_each_child(c,child(1)){
                if(c_i_!=0)
                    out << ",";
                out << "typename " << c->as_string();
            } end_for;
            out << ">\n";
        }
        if(strcmp(getDecl()->getName().c_str(),"int")==0)
            return;
        if(strcmp(getDecl()->getName().c_str(),"bool")==0)
            return;
        writeIndented(out,i);
        out << "class ";
        child(0)->innerCodeGen(out,i);
        out << ";\n";
    }
    //hbradlow
    void classCodeGen(ostream& out,int i){
        if(strcmp(getDecl()->getName().c_str(),"int")==0)
            return;
        if(strcmp(getDecl()->getName().c_str(),"bool")==0)
            return;
        if(strcmp(getDecl()->getName().c_str(),"tuple0")==0)
            return;
        if(strcmp(getDecl()->getName().c_str(),"tuple1")==0)
            return;
        if(strcmp(getDecl()->getName().c_str(),"tuple2")==0)
            return;
        if(strcmp(getDecl()->getName().c_str(),"tuple3")==0)
            return;
        if(child(1)->arity()){
            writeIndented(out,i);
            out << "template<";
            for_each_child(c,child(1)){
                if(c_i_!=0)
                    out << ",";
                out << "typename " << c->as_string();
            } end_for;
            out << ">\n";
        }
        writeIndented(out,i);
        out << "class ";
        child(0)->innerCodeGen(out,i);
        writeIndented(out,i);
        out << ": public Object{\n";
        writeIndented(out,i);
        out << "public:\n";
        writeIndented(out,i+1);
        out << "Frame* frame;\n";

        writeIndented(out,i+1);
        child(0)->innerCodeGen(out,i);
        out << "(Frame* frame){\n";
        writeIndented(out,i+2);
        out << "this->frame = new Frame(NULL);\n";

        for_each_child(c,child(2)){
            c->innerClassCodeGen(out,i,this);
        } end_for;

        writeIndented(out,i+1);
        out << "}\n";

        writeIndented(out,i);
        out << "};\n";
    }

private:
    /** Add declaration of method init to me. */
    void addInit () {
        Decl* me = getDecl (0);
        AST_Ptr newDef =
            consTree (METHOD, make_id ("__init__", loc ()),
                      consTree (FORMALS_LIST, make_id ("self", loc ())),
                      consTree (EMPTY),
                      consTree (BLOCK));
        newDef->collectDecls (me);
        child (2)->insert (0, newDef);
    }
};

NODE_FACTORY (Class_AST, CLASS);

/***** TYPE_FORMALS_LIST *****/

/** of [$T, ...]      */
class TypeFormalsList_AST : public AST_Tree {
protected:

    NODE_CONSTRUCTORS (TypeFormalsList_AST, AST_Tree);

    void collectDecls (Decl* enclosing) {
        const Environ* env = enclosing->getEnviron ();
        for_each_child (c, this) {
            string name = c->as_string ();
            if (env->find_immediate (name) != NULL) {
                error (c, "duplicate type parameter: %s",
                       name.c_str ());
            } else {
                c->addDecl (enclosing->addTypeVarDecl (c));
            }
        } end_for;
    }

};

NODE_FACTORY (TypeFormalsList_AST, TYPE_FORMALS_LIST);

/***** TYPED_ID *****/

/** ID::TYPE */
class TypedId_AST : public AST_Tree {
protected:

    NODE_CONSTRUCTORS (TypedId_AST, AST_Tree);

    AST_Ptr getId () {
        return child (0);
    }

    Decl* getDecl (int k = 0) {
        return getId ()->getDecl (k);
    }

    Type_Ptr getType () {
        return child (1)->asType ();
    }

    void addTargetDecls (Decl* enclosing) {
        getId ()->addTargetDecls (enclosing);
    }
    
    void collectTypeVarDecls (Decl* enclosing) {
        child (1)->collectTypeVarDecls (enclosing);
    }

    void addDecl (Decl* decl) {
        getId ()->addDecl (decl);
    }

    
    AST_Ptr resolveTypes (Decl* context, int& resolved, int& ambiguities) {
        getId ()->resolveTypes (context, resolved, ambiguities);
        if (!getId ()->setType (child (1)->asType ())) 
            error (this, "incompatible type assignment");
        return this;
    }

    //hbradlow
    void stringCodeGen(ostream& out,int i){
        out << "\"";
        innerCodeGen(out,i);
        out << "\"";
    }
    //hbradlow
    void valueCodeGen(ostream& out,int i){
        out << "*(";
        getType()->binding()->innerCodeGen(out,i);
        out << "*)frame->getVar(\"";
        innerCodeGen(out,i);
        out << "\")";
    }
    //hbradlow
    void innerCodeGen(ostream& out,int i){
        //hbradlow: NOT COMPLETE! I just copied from ID
        child(0)->innerCodeGen(out,i);
    }
    //hbradlow
    void outerCodeGen(ostream& out,int i){
        writeIndented(out,i);
        innerCodeGen(out,i);
        out << ";\n";
    }

};

NODE_FACTORY (TypedId_AST, TYPED_ID);


/***** ASSIGN *****/

/** TARGET(s) = EXPR */
class Assign_AST : public Typed_Tree {
protected:

    NODE_CONSTRUCTORS (Assign_AST, Typed_Tree);

    void collectDecls (Decl* enclosing) {
        child(1)->collectDecls (enclosing);
        child(0)->addTargetDecls (enclosing);
    }

    AST_Ptr resolveTypes (Decl* context, int& resolved, int& ambiguities) {
        int errs0 = numErrors ();
        AST_Tree::resolveTypes (context, resolved, ambiguities);
        if (!child (0)->getType ()->unify (child (1)->getType ())
            && errs0 == numErrors ())
            error (this, "type mismatch in assignment");
        if (!setType (child (1)->getType ()) && errs0 == numErrors ())
            error (this, "type mismatch in assignment");
        return this;
    }
    
    AST_Ptr convertNone (bool) {
        child (0)->convertNone (true);
        replace (1, child (1)->convertNone (false));
        return this;
    }

    //hbradlow
    void innerCodeGen(ostream& out,int i){
        child(0)->getType()->binding()->innerCodeGen(out,i);
        if(child(1)->needsPointer())
            out << "*";
        out << " ";
        child(0)->innerCodeGen(out, i);
        out << " = ";
        child(1)->innerCodeGen(out,i);
    }
    //hbradlow
    void outerCodeGen(ostream& out,int i){
        child(0)->assignCodeGen(out,i,child(1));
    }
    //hbradlow
    void innerClassCodeGen(ostream& out,int i, AST_Ptr c){
        child(0)->assignCodeGen(out,i,child(1),"this->frame");
    }
};

NODE_FACTORY (Assign_AST, ASSIGN);

/***** FOR *****/

/**  for target in exprs: body [ else: body ]     */
class For_AST : public AST_Tree {
public:
    static int global_count;
    int local_count;
protected:

    NODE_CONSTRUCTORS (For_AST, AST_Tree);

    //wskinner
    void outerCodeGen(ostream& out, int depth) {
        local_count = global_count++;
        writeIndented(out,depth);
        child(1)->memCodeGen(out,0);
        out << "List* for_list" << local_count;
        out << " = ";
        child(1)->valueCodeGen(out,0);
        out << ";\n";
        writeIndented(out,depth);
        out << "for(vector<Object*>::iterator it = ";
        out << "for_list" << local_count;
        out << "->items.begin() ; it != ";
        out << "for_list" << local_count;
        out << "->items.end(); ++it){\n";
        writeIndented(out,depth+1);
        out << "frame->frame->setVar(\"";
        child(0)->innerCodeGen(out,0);
        out << "\",*it);\n";
        for_each_child(c,child(2)){
            c->outerCodeGen(out,depth+1);
        } end_for;
        writeIndented(out,depth);
        out << "}\n";
    }

    AST_Ptr resolveTypes (Decl* context, int& resolved, int& ambiguities) {
        int errs0 = numErrors ();
        AST_Tree::resolveTypes (context, resolved, ambiguities);
        if (errs0 != numErrors ())
            return this;
        Type_Ptr seqType = child (1)->getType ()->binding ();

        if (seqType->isTypeVariable ()) {
            ambiguities += 1;
            return this;
        }

        Type_Ptr eltType;
        if (seqType->unifies (strDecl->asType ()))
            eltType = strDecl->asType ();
        else if (seqType->unifies (rangeDecl->asType ()))
            eltType = intDecl->asType ();
        else {
            eltType = Type::makeVar ();
            if (!seqType->unify (listDecl->asType (1, eltType)))
                error (this, "value cannot be iterated over");
        }
        if (!eltType->unify (child (0)->getType ())) {
            error (this, "for loop target does not match element type");
        } 

        return this;
    }
        
    void collectDecls (Decl* enclosing) {
        AST_Ptr target = child (0);
        for (size_t i = 1; i < arity (); i += 1)
            child (i)->collectDecls (enclosing);
        target->addTargetDecls (enclosing);
    }

};

NODE_FACTORY (For_AST, FOR);
int For_AST::global_count;


/***** RETURN *****/

/**  return EXPR */
class Return_AST : public AST_Tree {
protected:

    NODE_CONSTRUCTORS (Return_AST, AST_Tree);

    AST_Ptr resolveTypes (Decl* context, int& resolved, int& ambiguities) {
        AST_Tree::resolveTypes (context, resolved, ambiguities);
        AST_Ptr expr = child (0);
        if (! expr->isMissing ()) {
            Type_Ptr returnType = context->getType ()->returnType ();
            if (!returnType->unify (expr->getType ()))
                error (this, "inconsistent return type");
        }
        return this;
    }

    //hbradlow
    void innerCodeGen(ostream& out,int i){
        out << "return ";
        child(0)->valueCodeGen(out,i);
    }
    //hbradlow
    void outerCodeGen(ostream& out,int i){
        child(0)->memCodeGen(out,i);
        writeIndented(out,i);
        innerCodeGen(out,i);
        out << ";\n";
    }
};

NODE_FACTORY (Return_AST, RETURN);


/**  return EXPR */
class Native_AST : public AST_Tree {
protected:

    NODE_CONSTRUCTORS (Native_AST, AST_Tree);
    //hbradlow
    void innerCodeGen(ostream& out,int i){
        out << "NATIVE";
        out << child(0)->as_string();
    }
    //hbradlow
    void outerCodeGen(ostream& out,int i){
        writeIndented(out,i);
        innerCodeGen(out,i);
        out << ";\n";
    }

};

NODE_FACTORY (Native_AST, NATIVE);
