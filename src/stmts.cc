/* -*- mode: C++; c-file-style: "stroustrup"; indent-tabs-mode: nil; -*- */

/* stmts.cc: AST subclasses related to statements and modules. */

/* Authors:  YOUR NAMES HERE */

#include <iostream>
#include "apyc.h"
#include "ast.h"
#include "apyc-parser.hh"

using namespace std;

/***** IF *****/

/* if Cond: E1, else : E2
 */
class If_AST : public AST_Tree {
protected:

    NODE_CONSTRUCTORS (If_AST, AST_Tree);
    
    //wskinner
    void outerCodeGen(ostream& out, int depth) {
      out << "if ";
      child(0)->outerCodeGen(out, depth);
      out << " {" << endl;
      child(1)->outerCodeGen(out, depth+1);
      out << "}" << endl;
      out << "else {" << endl;
      child(2)->outerCodeGen(out, depth+1);
      out << "}" << endl;
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
        out << "cout ";
        int first = 1;
        for_each_child(c,child(1)){
            out << " << ";
            if(!first){
                out << "\" \" << ";
            }
            first = 0;
            c->outerCodeGen(out,i);
        } end_for;
        out << ";\n";
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
        writeIndented(out,i);
        out << "cout << ";
        int first = 1;
        for_each_child(c,child(1)){
            if(!first){
                out << "\" \" << ";
            }
            first = 0;
            c->outerCodeGen(out,i);
            out << " << ";
        } end_for;
        out << "endl;\n";
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
    void defCodeGen(ostream& out,int i){
        writeIndented(out,i);
        getDecl()->getType()->child(0)->asType()->binding()->outerCodeGen(out,i);
        out << " ";
        child(0)->outerCodeGen(out,i);
        out << "(";
        child(1)->outerCodeGen(out,i);
        out << "){\n";
        for_each_child(c,child(3)){
            c->outerCodeGen(out,i+1);
        } end_for;
        writeIndented(out,i);
        out << "}\n";
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
    void outerCodeGen(ostream& out,int i){
        for_each_child(c,this){
            if(c_i_!=0){
                out << ",";
            }
            c->getType()->outerCodeGen(out,i);
            out << " ";
            c->outerCodeGen(out,i);
        } end_for;
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

    void classCodeGen(ostream& out,int i){
        if(strcmp(getDecl()->getName().c_str(),"int")==0)
            return;
        if(strcmp(getDecl()->getName().c_str(),"dict")==0)
            return;
        if(strcmp(getDecl()->getName().c_str(),"bool")==0)
            return;
        writeIndented(out,i);
        out << "class ";
        child(0)->outerCodeGen(out,i);
        out << "{\n";
        out << "public:\n";
        for_each_child(c,child(2)){
            c->outerCodeGen(out,i+1);
        } end_for;
        for_each_child(c,child(2)){
            c->defCodeGen(out,i+1);
        } end_for;
        out << "};\n";
    }

private:
    /** Add declaration of method init to me. */
    void addInit () {
        Decl* me = getDecl (0);
        AST_Ptr newDef =
            consTree (DEF, make_id ("__init__", loc ()),
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
    void outerCodeGen(ostream& out,int i){
        //hbradlow: NOT COMPLETE! I just copied from ID
        child(0)->outerCodeGen(out,i);
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
    void outerCodeGen(ostream& out,int i){
        writeIndented(out,i);
        child(0)->getType()->binding()->outerCodeGen(out,i);
        if(child(1)->needsPointer())
            out << "*";
        out << " ";
        child(0)->outerCodeGen(out,i);
        out << " = ";
        child(1)->outerCodeGen(out,i);
        out << ";\n";
    }
};

NODE_FACTORY (Assign_AST, ASSIGN);

/***** FOR *****/

/**  for target in exprs: body [ else: body ]     */
class For_AST : public AST_Tree {
protected:

    NODE_CONSTRUCTORS (For_AST, AST_Tree);

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

    void outerCodeGen(ostream& out,int i){
        writeIndented(out,i);
        out << "return ";
        child(0)->outerCodeGen(out,i);
        out << ";\n";
    }

};

NODE_FACTORY (Return_AST, RETURN);


/**  return EXPR */
class Native_AST : public AST_Tree {
protected:

    NODE_CONSTRUCTORS (Native_AST, AST_Tree);
    void outerCodeGen(ostream& out,int i){
        writeIndented(out,i);
        out << "NATIVE";
        out << child(0)->as_string();
        out << ";\n";
    }

};

NODE_FACTORY (Native_AST, NATIVE);
