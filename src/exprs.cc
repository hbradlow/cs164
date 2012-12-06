/* -*- mode: C++; c-file-style: "stroustrup"; indent-tabs-mode: nil; -*- */

/* exprs.cc: AST subclasses related to expressions. */

/* Authors:  YOUR NAMES HERE */

#include <iostream>
#include <sstream>
#include "apyc.h"
#include "ast.h"
#include "apyc-parser.hh"

using namespace std;

static int inner_closure_index = 0;
/*****   Typed_Tree   *****/

Type_Ptr
Typed_Tree::getType ()
{
    if (_type == NULL)
        _type = computeType ();
    return _type;
}

bool
Typed_Tree::setType (Type_Ptr type)
{
    if (_type == NULL) {
        _type = type;
        return true;
    } else return _type->unify (type);
}

AST_Ptr
Typed_Tree::resolveTypes (Decl* context, int& resolved, int& ambiguities)
{
    AST_Tree::resolveTypes (context, resolved, ambiguities);
    getType ();
    return this;
}

Type_Ptr
Typed_Tree::computeType ()
{
    return Type::makeVar ();
}

/*****   EXPR_LIST    *****/

/** A list of expressions. */
class Expr_List_AST : public AST_Tree {
protected:

    NODE_CONSTRUCTORS (Expr_List_AST, AST_Tree);

    //hbradlow
    void innerCodeGen(ostream& out, int i){
        for_each_child(c,this){
            c->innerCodeGen(out,i);
        } end_for;
    }
    //hbradlow
    void outerCodeGen(ostream& out, int i){
        writeIndented(out,i);
        innerCodeGen(out,i);
        out << ";\n";
    }
};

NODE_FACTORY (Expr_List_AST, EXPR_LIST);


/*****   CALLS    *****/

/** The supertype of "callable" things, including ordinary calls,
 *  binary operators, unary operators, subscriptions, and slices. */

class Callable : public Typed_Tree {
protected:

    NODE_BASE_CONSTRUCTORS (Callable, Typed_Tree);
    
    /** Returns the expression representing the quantity that is
     *  called to evaluate this expression. */
    virtual AST_Ptr calledExpr () = 0;

    /** Returns the number of actual parameters in this call. */
    virtual int numActuals () = 0;

    /** Return the Kth actual parameter in this call. */
    virtual AST_Ptr actualParam (int k) = 0;

    /** Set the Kth actual parameter in this call to EXPR. */
    virtual void setActual (int k, AST_Ptr expr) = 0;

public:

    Type_Ptr computeType () {
        return calledExpr ()->getType ()->binding ()->returnType ();
    }

    AST_Ptr resolveTypes (Decl* context, int& resolved, int& ambiguities) {
        Typed_Tree::resolveTypes (context, resolved, ambiguities);
        Type_Ptr funcType;
        funcType = calledExpr ()->getType ()->binding ();

        if (!makeFuncType (numActuals (), funcType)) {
            error (this,
                   "called object is not a %d-parameter function",
                   numActuals ());
            return this;
        }

        if (!setType (computeType ())) {
            error (this, "inappropriate function return type");
            return this;
        }

        funcType = funcType->binding ();
        if (funcType->numParams () != numActuals ()) {
            error (this, "wrong number of parameters to function");
            return this;
        }
        for (int i = 0; i < numActuals (); i += 1) {
            if (!actualParam (i)->getType ()->unify (funcType->paramType (i))) {
                error (this, "non-matching parameter type (parameter #%d)",
                       i);
                break;
            }
        }
        return this;
    }

};

/** A function call. */
class Call_AST : public Callable {
public:
    static int global_count;
    int local_count;
protected:

    NODE_CONSTRUCTORS (Call_AST, Callable);

    AST_Ptr calledExpr () {
        return child (0);
    }

    int numActuals () {
        return child (1)->arity ();
    }

    AST_Ptr actualParam (int k) {
        return child (1)->child (k);
    }

    void setActual (int k, AST_Ptr expr) {
        child (1)->replace (k, expr);
    }

    AST_Ptr resolveAllocators (const Environ* env) {
        Callable::resolveAllocators (env);
        AST_Ptr callable = calledExpr ();
        if (callable->isType ()) {
            vector<AST_Ptr> initArgs;
            initArgs.push_back (consTree (NEW, callable));
            for (int i = 0; i < numActuals (); i += 1)
                initArgs.push_back (actualParam (i));
            
            AST_Ptr init = consTree(ATTRIBUTEREF, callable, 
                                    make_id ("__init__", loc ()));
            return consTree (CALL1, init,
                             AST::make_tree (EXPR_LIST,
                                             initArgs.begin (),
                                             initArgs.end ()));
        }
        return this;
    }

    AST_Ptr resolveTypes (Decl* context, int& resolved, int& ambiguities) {
        replace (0, child (0)->resolveTypes (context, resolved, ambiguities));
        AST_Ptr call = child (0)->convertMethodCall (child (1));
        if (call == NULL)
            return Callable::resolveTypes (context, resolved, ambiguities);
        else
            return dynamic_cast<Callable*>(call.data())
                ->Callable::resolveTypes (context, resolved, ambiguities);
    }

    //hbradlow
    void innerCodeGen(ostream& out, int i){
        if (!child(0)->isCall())
        {
        child(0)->innerCodeGen(out,i);
        out << "_PARAM" << 0 << "_" << local_count << child(0)->getDecl()->getIndex();
        }
        else 
        {
        child(0)->innerCodeGen(out, i);
        }
        /*
        child(0)->innerCodeGen(out,i);
        out << "__" << child(0)->getDecl()->getIndex();
        out << "(&";
        child(0)->innerCodeGen(out,i);
        out << "__" << child(0)->getDecl()->getIndex() << "_closure->frame";
        out << ")";
        */
    }
    //hbradlow
    void outerCodeGen(ostream& out, int i){
        writeComment(out,i,"------------------start------------------");
        writeComment(out,i,"Bare Call");
        memCodeGen(out,i);
        writeComment(out,i,"------------------end------------------");
    }
    bool isCall()
    {
        return true;
    }
    //hbradlow
    void memCodeGen(ostream& out, int i){
        if (!child(0)->isCall())
        {
            for_each_child(c,this){
                c->memCodeGen(out,i);
            } end_for;
            local_count = global_count++;
            stringstream ss;
            child(0)->print(ss,0);
            local_counts[ss.str()] = local_count;

            writeComment(out, i, "Generate the dynamic frame");
            writeIndented(out, i);
            out << "Frame* "; 
            child(0)->innerCodeGen(out,i);
            out << "_dyn_" << local_count << child(0)->getDecl()->getIndex();
            out << " = new Frame(";
            writeClosure(out,i,child(0));
            out << "->frame);\n";
            writeComment(out,i,"Generate an argument to the function call");

            writeComment(out,i,"Generate the args");
            for_each_child(c,child(1)){
                generateArgs(out, i, c_i_, c);
            } end_for;
            
            generateFunctionCall(out, i);
        } else 
        {
            ((Call_AST*)child(0))->nestedMemGen(out, i);
            ((Call_AST*)child(0))->nestedInnerGen(out, i);
        }
    }
    void nestedInnerGen(ostream& out, int i)
    {
        if(!child(0)->isCall())
        {
            writeIndented(out, i);
            out << "Frame *loc_" << global_count << " = new Frame(";
            innerCodeGen(out, i);
            out << "->frame);\n";
            writeIndented(out, i); 
            innerCodeGen(out, i);
            out << " = (Closure*)";
            innerCodeGen(out, i);
            out << "->call(loc_" << global_count << ");\n";
        } 
        else
        {
            ((Call_AST*)child(0))->nestedInnerGen(out, i );
            writeIndented(out, i);
            out << "Frame *loc_" << global_count << " = new Frame(";
            innerCodeGen(out, i);
            out << "->frame);\n";
            writeIndented(out, i); 
            for_each_child(c, child(1))
            {
                innerArgGen(out, i, c_i_, c);
            } end_for;
            writeIndented(out, i);
            innerCodeGen(out, i);
            out << " = (Closure*)(";
            child(0)->innerCodeGen(out, i);
            out << "->call(loc_" << global_count << "));\n";
        }
    }

    void innerArgGen(ostream& out, int i, int c_i_, AST_Ptr c)
    {
        writeComment(out,i,"Create a temp variable to store the value");
        writeIndented(out,i);
        c->getType()->binding()->innerCodeGen(out,i);
        if(c->getType()->binding()->needsPointer())
            out << "*";
        out << " ";
        child(0)->innerCodeGen(out,i);
        out << "_" << c_i_ << "_" << local_count << inner_closure_index;
        out << " = ";
        c->valueCodeGen(out,i);
        out << ";\n";

        writeComment(out,i,"Add it to the closures frame");
        writeIndented(out, i);
        innerCodeGen(out ,i);
        out << "->print(cout);";
        writeIndented(out,i);
         
        out << "loc_" << global_count << "->setVar(";
        innerCodeGen(out ,i);
        out << "->args[" << c_i_ << "]";
        out << ",";
        child(0)->innerCodeGen(out,i);
        out << "_" << c_i_ << "_" << local_count << inner_closure_index; 
        out << ");\n";
        inner_closure_index++;
        writeComment(out,i,"--------------------end------------------");
    }
    void nestedMemGen(ostream& out, int i)
    {
        if (child(0)->isCall())
        {
            ((Call_AST*)child(0))->nestedMemGen(out, i);
        }
        else 
        {
            memCodeGen(out, i);
        }
    }

    void valueCodeGen(ostream& out, int i) 
    {
        if (child(0)->isCall())
            child(0)->innerCodeGen(out, i);
        else
            innerCodeGen(out, i);
    }

    void generateFunctionCall(ostream& out, int i)
    {
        writeComment(out,i,"--------------------start----------------");
        writeComment(out,i,"Perform the function call");
        writeIndented(out,i);
        this->getType()->binding()->innerCodeGen(out,i);
        if(this->getType()->binding()->needsPointer())
            out << "*";
        out << " ";
        child(0)->innerCodeGen(out,i);
        out << "_PARAM" << 0 << "_" << local_count << child(0)->getDecl()->getIndex();
        out << " = ";
        out << "(";
        this->getType()->binding()->innerCodeGen(out,i);
        if(this->getType()->binding()->needsCastPointer())
            out << "*";
        out << ")";
        writeClosure(out,i,child(0));
        out << "->call" << "(";
        child(0)->innerCodeGen(out,i);
        out << "_dyn_" << local_count << child(0)->getDecl()->getIndex();
        out << ")";
        out << ";\n";

        writeComment(out,i,"Add it to the current frame");
        writeIndented(out,i);
        out << "frame->setVar(\"";
        child(0)->innerCodeGen(out,i);
        out << "_PARAM" << 0 << "_" << local_count << child(0)->getDecl()->getIndex() << "\"";
        out << ",";
        child(0)->innerCodeGen(out,i);
        out << "_PARAM" << 0 << "_" << local_count << child(0)->getDecl()->getIndex();
        out << ");\n";
        writeComment(out,i,"--------------------end------------------");
    }

    void generateArgs(ostream& out, int i, int c_i_, AST_Ptr c)
    {
        writeComment(out,i,"--------------------start----------------");

        writeComment(out,i,"Create a temp variable to store the value");
        writeIndented(out,i);
        c->getType()->binding()->innerCodeGen(out,i);
        if(c->getType()->binding()->needsPointer())
            out << "*";
        out << " ";
        child(0)->innerCodeGen(out,i);
        out << "_" << c_i_ << "_" << local_count << child(0)->getDecl()->getIndex();
        out << " = ";
        c->valueCodeGen(out,i);
        out << ";\n";

        writeComment(out,i,"Add it to the closures frame");
        writeIndented(out,i);
        child(0)->innerCodeGen(out,i);
        out << "_dyn_" << local_count << child(0)->getDecl()->getIndex();
        out << "->setVar(";
        writeClosure(out,i,child(0));
        out << "->args[" << c_i_ << "]";
        out << ",";
        child(0)->innerCodeGen(out,i);
        out << "_" << c_i_ << "_" << local_count << child(0)->getDecl()->getIndex();
        out << ");\n";
        writeComment(out,i,"--------------------end------------------");
    }
};

NODE_FACTORY (Call_AST, CALL);
int Call_AST::global_count;

/***** CALL1 *****/

/** __init__(new T, ...)      */
class Call1_AST : public Call_AST {
protected:

    NODE_CONSTRUCTORS (Call1_AST, Call_AST);

    Type_Ptr computeType () {
        return calledExpr ()->getType ()->binding ()->paramType (0);
    }
    
    //hbradlow
    void innerCodeGen(ostream& out, int i){
        out << "(";
        child(0)->innerCodeGen(out,i);
        child(0)->getDecl()->getEnviron()->find(child(0)->as_string());

        stringstream ss;
        child(0)->print(ss,0);

        out << "_0_" << local_counts.find(ss.str())->second << child(0)->getDecl()->getIndex();
        out << ")";
    }
    //hbradlow
    void outerCodeGen(ostream& out, int i){
        writeIndented(out,i);
        innerCodeGen(out,i);
        out << ";\n";
    }

    //hbradlow
    bool needsPointer(){
        return true;
    }
};

NODE_FACTORY (Call1_AST, CALL1);

/***** NEW *****/

/**  new T     */
class New_AST : public Typed_Tree {
protected:

    NODE_CONSTRUCTORS (New_AST, Typed_Tree);

    AST_Ptr resolveTypes (Decl* context, int& resolved, int& ambiguities) {
        if (!setType (child (0)->asType ())) {
            error (this, "inconsistent types");
        }
        return this;
    }
    //hbradlow
    void innerCodeGen(ostream& out,int i){
    }
    void valueCodeGen(ostream& out, int i){
        out << "new ";
        child(0)->innerCodeGen(out,i);
        out << "(frame)";
    }
    //hbradlow
    bool needsPointer(){
        return true;
    }
};

NODE_FACTORY (New_AST, NEW);


/** A binary operator. */
class Binop_AST : public Callable {
public:
    static int global_count;
    int local_count;
protected:

    NODE_CONSTRUCTORS (Binop_AST, Callable);

    AST_Ptr calledExpr () {
        return child (3);
    }

    int numActuals () {
        return 2;
    }

    AST_Ptr actualParam (int k) {
        return child(k * 2);
    }

    void setActual (int k, AST_Ptr expr) {
        replace (2*k, expr);
    }

    //hbradlow
    void innerCodeGen(ostream& out, int i){
        child(3)->innerCodeGen(out,i);
        out << "_" << 2 << "_" << local_count << child(3)->getDecl()->getIndex();

        /*
        child(3)->innerCodeGen(out,i);
        out << "__" << child(3)->getDecl()->getIndex();
        out << "(";
        child(3)->innerCodeGen(out,i);
        out << "__" << child(3)->getDecl()->getIndex() << "_closure->frame";
        out << ")";
        */
    }
    //hbradlow
    void outerCodeGen(ostream& out, int i){
        writeIndented(out,i);
        innerCodeGen(out,i);
        out << ";\n";
    }
    //hbradlow
    void memCodeGen(ostream& out, int i){
        for_each_child(c,this){
            c->memCodeGen(out,i);
        } end_for;
        out << "\n";

        local_count = global_count++;
        stringstream ss;
        child(0)->print(ss,0);
        local_counts[ss.str()] = local_count;
        generateArgs(out, i, 0, this);
        generateFunctionCall(out, i);
        
        out << "\n";
    }
    void generateArgs(ostream& out, int i, int c_i_, AST_Ptr c)
    {
        writeComment(out,i,"Generate the arguments to the call");
        writeComment(out,i,"Binops have two args");

        writeComment(out,i,"Create first dummy variable");
        writeIndented(out,i);
        child(0)->getType()->binding()->innerCodeGen(out,i);
        if(child(0)->getType()->binding()->needsPointer())
            out << "*";
        out << " ";
        child(3)->innerCodeGen(out,i);
        out << "_" << 0 << "_" << local_count << child(3)->getDecl()->getIndex();
        out << " = ";
        child(0)->valueCodeGen(out,i);
        out << ";\n";

        writeIndented(out,i);
        out << "((";
        child(3)->innerCodeGen(out,i);
        out << "__" << child(3)->getDecl()->getIndex() << "_CLOSURE*)";
        out << "(frame->getVar(\"";
        child(3)->innerCodeGen(out,i);
        out << "__" << child(3)->getDecl()->getIndex() << "_closure\")))->frame->setVar(";
        
        out << "((";
        child(3)->innerCodeGen(out,i);
        out << "__" << child(3)->getDecl()->getIndex() << "_CLOSURE*)";
        out << "(frame->getVar(\"";
        child(3)->innerCodeGen(out,i);
        out << "__" << child(3)->getDecl()->getIndex() << "_closure\")))->args";
        out << "[" << "0" << "]";
        out << ",";
        child(3)->innerCodeGen(out,i);
        out << "_" << 0 << "_" << local_count << child(3)->getDecl()->getIndex();
        out << ");\n";

        writeComment(out,i,"Create second dummy variable");
        writeIndented(out,i);
        child(2)->getType()->binding()->innerCodeGen(out,i);
        if(child(0)->getType()->binding()->needsPointer())
            out << "*";
        out << " ";
        child(3)->innerCodeGen(out,i);
        out << "_" << 1 << "_" << local_count << child(3)->getDecl()->getIndex();
        out << " = ";
        child(2)->valueCodeGen(out,i);
        out << ";\n";

        writeIndented(out,i);
        out << "((";
        child(3)->innerCodeGen(out,i);
        out << "__" << child(3)->getDecl()->getIndex() << "_CLOSURE*)";
        out << "(frame->getVar(\"";
        child(3)->innerCodeGen(out,i);
        out << "__" << child(3)->getDecl()->getIndex() << "_closure\")))->frame->setVar(";
        out << "((";
        child(3)->innerCodeGen(out,i);
        out << "__" << child(3)->getDecl()->getIndex() << "_CLOSURE*)";
        out << "(frame->getVar(\"";
        child(3)->innerCodeGen(out,i);
        out << "__" << child(3)->getDecl()->getIndex() << "_closure\")))->args";

        out << "[" << "1" << "]";
        out << ",";
        child(3)->innerCodeGen(out,i);
        out << "_" << 1 << "_" << local_count << child(3)->getDecl()->getIndex();
        out << ");\n";

        writeIndented(out,i);
        child(3)->getDecl()->getType()->binding()->child(0)->innerCodeGen(out,i);
        if(child(3)->getDecl()->getType()->binding()->child(0)->needsPointer())
            out << "*";
        out << " ";
        child(3)->innerCodeGen(out,i);
        out << "_" << 2 << "_" << local_count << child(3)->getDecl()->getIndex();
        out << " = (";
        child(3)->getDecl()->getType()->binding()->child(0)->innerCodeGen(out,i);
        if(child(3)->getDecl()->getType()->binding()->child(0)->needsPointer())
            out << "*";
        out << ")";
        writeClosure(out,i,child(3));
        out << "->fp(";

        out << "(((";
        child(3)->innerCodeGen(out,i);
        out << "__" << child(3)->getDecl()->getIndex() << "_CLOSURE*)";
        out << "(frame->getVar(\"";
        child(3)->innerCodeGen(out,i);
        out << "__" << child(3)->getDecl()->getIndex() << "_closure\")))->frame))";
        out << ";\n";
    }
    void generateFuctionCall(ostream& out, int i)
    {
        writeComment(out,i,"Perform Function Call");

        writeIndented(out,i);
        child(3)->getDecl()->getType()->binding()->child(0)->innerCodeGen(out,i);
        if(child(3)->getDecl()->getType()->binding()->child(0)->needsPointer())
            out << "*";
        out << " ";
        child(3)->innerCodeGen(out,i);
        out << "_PARAM" << 0 << "_" << local_count << child(3)->getDecl()->getIndex();
        out << " = ";
        child(3)->innerCodeGen(out,i);
        out << "__" << child(3)->getDecl()->getIndex() << "(";
        child(3)->innerCodeGen(out,i);
        out << "__" << child(3)->getDecl()->getIndex() << "_closure->frame)";
        out << ";\n";
    }

};    
int Binop_AST::global_count;

NODE_FACTORY (Binop_AST, BINOP);

/***** COMPARE *****/

/** A comparison yielding bool */
class Compare_AST : public Binop_AST {
protected:

    NODE_CONSTRUCTORS (Compare_AST, Binop_AST);
/*
    void outerCodeGeneration(ostream& out, int depth) {
      out << "(";
      child(0)->outerCodeGen(out, depth);
      out << ")";
    }
*/
    Type_Ptr computeType () {
        return boolDecl->asType ();
    }

    //hbradlow
    void valueCodeGen(ostream& out, int i){
        if( child(0)->isLeftCompare())
        {
            out << "((*(";
            child(0)->innerCodeGen(out,i);
            out << "))&&(*(";
            innerCodeGen(out,i);
            out << ")))";
        }
        else{
            innerCodeGen(out,i);
        }
    }
};

NODE_FACTORY (Compare_AST, COMPARE);



/***** LEFT_COMPARE *****/

/** A comparison yielding its second operand's type. */
class LeftCompare_AST : public Binop_AST {
protected:

    NODE_CONSTRUCTORS (LeftCompare_AST, Binop_AST);

    Type_Ptr computeType () {
        return actualParam (1)->getType ();
    }

    //hbradlow
    bool isLeftCompare(){
        return true;
    }
    //hbradlow
    void valueCodeGen(ostream& out, int i){
        child(2)->valueCodeGen(out,i);
    }
};

NODE_FACTORY (LeftCompare_AST, LEFT_COMPARE);


/** A unary operator. */
class Unop_AST : public Callable {
public:
    static int global_count;
    int local_count;

    NODE_CONSTRUCTORS (Unop_AST, Callable);

    AST_Ptr calledExpr () {
        return child (2);
    }

    int numActuals () {
        return 1;
    }

    AST_Ptr actualParam (int k) {
        return child(2*k + 1);
    }

    void setActual (int k, AST_Ptr expr) {
        replace (2*k + 1, expr);
    }
    //hbradlow
    void innerCodeGen(ostream& out, int i){
        child(2)->innerCodeGen(out,i);
        out << "_" << 2 << "_" << local_count << child(2)->getDecl()->getIndex();

        /*
        child(3)->innerCodeGen(out,i);
        out << "__" << child(3)->getDecl()->getIndex();
        out << "(";
        child(3)->innerCodeGen(out,i);
        out << "__" << child(3)->getDecl()->getIndex() << "_closure->frame";
        out << ")";
        */
    }
    //hbradlow
    void outerCodeGen(ostream& out, int i){
        writeIndented(out,i);
        innerCodeGen(out,i);
        out << ";\n";
    }
    //hbradlow
    void memCodeGen(ostream& out, int i){
        out << "\n";

        local_count = global_count++;
        stringstream ss;
        child(1)->print(ss,0);
        local_counts[ss.str()] = local_count;
        generateArgs(out, i, 0, this);
        generateFunctionCall(out, i);
        
        out << "\n";
    }
    void generateArgs(ostream& out, int i, int c_i_, AST_Ptr c)
    {
        writeComment(out,i,"Generate the arguments to the call");
        writeComment(out,i,"Unops have two args");

        writeComment(out,i,"Create first dummy variable");
        writeIndented(out,i);
        child(1)->getType()->binding()->innerCodeGen(out,i);
        if(child(1)->getType()->binding()->needsPointer())
            out << "*";
        out << " ";
        child(2)->innerCodeGen(out,i);
        out << "_" << 0 << "_" << local_count << child(2)->getDecl()->getIndex();
        out << " = ";
        child(1)->valueCodeGen(out,i);
        out << ";\n";

        writeIndented(out,i);
        out << "((";
        child(2)->innerCodeGen(out,i);
        out << "__" << child(2)->getDecl()->getIndex() << "_CLOSURE*)";
        out << "(frame->getVar(\"";
        child(2)->innerCodeGen(out,i);
        out << "__" << child(2)->getDecl()->getIndex() << "_closure\")))->frame->setVar(";
        
        out << "((";
        child(2)->innerCodeGen(out,i);
        out << "__" << child(2)->getDecl()->getIndex() << "_CLOSURE*)";
        out << "(frame->getVar(\"";
        child(2)->innerCodeGen(out,i);
        out << "__" << child(2)->getDecl()->getIndex() << "_closure\")))->args";
        out << "[" << "0" << "]";
        out << ",";
        child(2)->innerCodeGen(out,i);
        out << "_" << 0 << "_" << local_count << child(2)->getDecl()->getIndex();
        out << ");\n";

        writeIndented(out,i);
        child(2)->getDecl()->getType()->binding()->child(0)->innerCodeGen(out,i);
        if(child(2)->getDecl()->getType()->binding()->child(0)->needsPointer())
            out << "*";
        out << " ";
        child(2)->innerCodeGen(out,i);
        out << "_" << 2 << "_" << local_count << child(2)->getDecl()->getIndex();
        out << " = (";
        child(2)->getDecl()->getType()->binding()->child(0)->innerCodeGen(out,i);
        if(child(2)->getDecl()->getType()->binding()->child(0)->needsPointer())
            out << "*";
        out << ")";
        writeClosure(out,i,child(2));
        out << "->fp(";

        out << "(((";
        child(2)->innerCodeGen(out,i);
        out << "__" << child(2)->getDecl()->getIndex() << "_CLOSURE*)";
        out << "(frame->getVar(\"";
        child(2)->innerCodeGen(out,i);
        out << "__" << child(2)->getDecl()->getIndex() << "_closure\")))->frame))";
        out << ";\n";
    }
    void generateFuctionCall(ostream& out, int i)
    {
        writeComment(out,i,"Perform Function Call");

        writeIndented(out,i);
        child(2)->getDecl()->getType()->binding()->child(0)->innerCodeGen(out,i);
        if(child(2)->getDecl()->getType()->binding()->child(0)->needsPointer())
            out << "*";
        out << " ";
        child(2)->innerCodeGen(out,i);
        out << "_PARAM" << 0 << "_" << local_count << child(2)->getDecl()->getIndex();
        out << " = ";
        child(2)->innerCodeGen(out,i);
        out << "__" << child(2)->getDecl()->getIndex() << "(";
        child(2)->innerCodeGen(out,i);
        out << "__" << child(2)->getDecl()->getIndex() << "_closure->frame)";
        out << ";\n";
    }

};    

NODE_FACTORY (Unop_AST, UNOP);
int Unop_AST::global_count;


/***** SUBSCRIPTION *****/

/** E1[E2] */
class Subscription_AST : public Callable {
public:
    static int global_count;
    int local_count;
protected:

    NODE_CONSTRUCTORS (Subscription_AST, Callable);

    int numActuals () {
        return 2;
    }

    AST_Ptr actualParam (int k) {
        return child (k);
    }

    AST_Ptr calledExpr () {
        return child (2);
    }

    void setActual (int k, AST_Ptr expr) {
        replace (k, expr);
    }

    void addTargetDecls (Decl* enclosing) {
    }
    //hbradlow
    void innerCodeGen(ostream& out, int i){
        child(2)->innerCodeGen(out,i);
        out << "_" << 2 << "_" << local_count << child(2)->getDecl()->getIndex();
    }
    //hbradlow
    void outerCodeGen(ostream& out, int i){
        writeIndented(out,i);
        innerCodeGen(out,i);
        out << ";\n";
    }
    //hbradlow
    void memCodeGen(ostream& out, int i){
        out << "\n";

        local_count = global_count++;
        stringstream ss;
        child(1)->print(ss,0);
        local_counts[ss.str()] = local_count;
        generateArgs(out, i, 0, this);
        generateFunctionCall(out, i);
        
        out << "\n";
    }
    void generateArgs(ostream& out, int i, int c_i_, AST_Ptr c)
    {
        writeComment(out,i,"Generate the arguments to the call");

        writeComment(out,i,"Create first dummy variable");
        writeIndented(out,i);
        child(0)->getType()->binding()->innerCodeGen(out,i);
        if(child(0)->getType()->binding()->needsPointer())
            out << "*";
        out << " ";
        child(2)->innerCodeGen(out,i);
        out << "_" << 0 << "_" << local_count << child(2)->getDecl()->getIndex();
        out << " = ";
        child(0)->valueCodeGen(out,i);
        out << ";\n";

        writeIndented(out,i);
        out << "((";
        child(2)->innerCodeGen(out,i);
        out << "__" << child(2)->getDecl()->getIndex() << "_CLOSURE*)";
        out << "(frame->getVar(\"";
        child(2)->innerCodeGen(out,i);
        out << "__" << child(2)->getDecl()->getIndex() << "_closure\")))->frame->setVar(";
        
        out << "((";
        child(2)->innerCodeGen(out,i);
        out << "__" << child(2)->getDecl()->getIndex() << "_CLOSURE*)";
        out << "(frame->getVar(\"";
        child(2)->innerCodeGen(out,i);
        out << "__" << child(2)->getDecl()->getIndex() << "_closure\")))->args";
        out << "[" << "0" << "]";
        out << ",";
        child(2)->innerCodeGen(out,i);
        out << "_" << 0 << "_" << local_count << child(2)->getDecl()->getIndex();
        out << ");\n";

        writeComment(out,i,"Create first dummy variable");
        writeIndented(out,i);
        child(1)->getType()->binding()->innerCodeGen(out,i);
        if(child(1)->getType()->binding()->needsPointer())
            out << "*";
        out << " ";
        child(2)->innerCodeGen(out,i);
        out << "_" << 1 << "_" << local_count << child(2)->getDecl()->getIndex();
        out << " = ";
        child(1)->valueCodeGen(out,i);
        out << ";\n";

        writeIndented(out,i);
        out << "((";
        child(2)->innerCodeGen(out,i);
        out << "__" << child(2)->getDecl()->getIndex() << "_CLOSURE*)";
        out << "(frame->getVar(\"";
        child(2)->innerCodeGen(out,i);
        out << "__" << child(2)->getDecl()->getIndex() << "_closure\")))->frame->setVar(";
        
        out << "((";
        child(2)->innerCodeGen(out,i);
        out << "__" << child(2)->getDecl()->getIndex() << "_CLOSURE*)";
        out << "(frame->getVar(\"";
        child(2)->innerCodeGen(out,i);
        out << "__" << child(2)->getDecl()->getIndex() << "_closure\")))->args";
        out << "[" << "1" << "]";
        out << ",";
        child(2)->innerCodeGen(out,i);
        out << "_" << 1 << "_" << local_count << child(2)->getDecl()->getIndex();
        out << ");\n";

        writeIndented(out,i);
        child(2)->getDecl()->getType()->binding()->child(0)->innerCodeGen(out,i);
        if(child(2)->getDecl()->getType()->binding()->child(0)->needsPointer())
            out << "*";
        out << " ";
        child(2)->innerCodeGen(out,i);
        out << "_" << 2 << "_" << local_count << child(2)->getDecl()->getIndex();
        out << " = (";
        child(2)->getDecl()->getType()->binding()->child(0)->innerCodeGen(out,i);
        if(child(2)->getDecl()->getType()->binding()->child(0)->needsPointer())
            out << "*";
        out << ")";
        writeClosure(out,i,child(2));
        out << "->fp(";

        out << "(((";
        child(2)->innerCodeGen(out,i);
        out << "__" << child(2)->getDecl()->getIndex() << "_CLOSURE*)";
        out << "(frame->getVar(\"";
        child(2)->innerCodeGen(out,i);
        out << "__" << child(2)->getDecl()->getIndex() << "_closure\")))->frame))";
        out << ";\n";
    }
    void generateFuctionCall(ostream& out, int i)
    {
        writeComment(out,i,"Perform Function Call");

        writeIndented(out,i);
        child(2)->getDecl()->getType()->binding()->child(0)->innerCodeGen(out,i);
        if(child(2)->getDecl()->getType()->binding()->child(0)->needsPointer())
            out << "*";
        out << " ";
        child(2)->innerCodeGen(out,i);
        out << "_PARAM" << 0 << "_" << local_count << child(2)->getDecl()->getIndex();
        out << " = ";
        child(2)->innerCodeGen(out,i);
        out << "__" << child(2)->getDecl()->getIndex() << "(";
        child(2)->innerCodeGen(out,i);
        out << "__" << child(2)->getDecl()->getIndex() << "_closure->frame)";
        out << ";\n";
    }

};

NODE_FACTORY (Subscription_AST, SUBSCRIPTION);
int Subscription_AST::global_count;
    
    
/***** SLICING *****/

/** E1[E2:E3] */
class Slicing_AST : public Callable {
public:
    static int global_count;
    int local_count;
protected:

    NODE_CONSTRUCTORS (Slicing_AST, Callable);

    int numActuals () {
        return 3;
    }

    AST_Ptr actualParam (int k) {
        return child (k);
    }

    AST_Ptr calledExpr () {
        return child (3);
    }

    void setActual (int k, AST_Ptr expr) {
        replace (k, expr);
    }

    void addTargetDecls (Decl* enclosing) {
    }
    //hbradlow
    void innerCodeGen(ostream& out, int i){
        child(3)->innerCodeGen(out,i);
        out << "_" << 3 << "_" << local_count << child(3)->getDecl()->getIndex();
    }
    //hbradlow
    void outerCodeGen(ostream& out, int i){
        writeIndented(out,i);
        innerCodeGen(out,i);
        out << ";\n";
    }
    //hbradlow
    void memCodeGen(ostream& out, int i){
        out << "\n";

        local_count = global_count++;
        stringstream ss;
        child(1)->print(ss,0);
        local_counts[ss.str()] = local_count;
        generateArgs(out, i, 0, this);
        generateFunctionCall(out, i);
        
        out << "\n";
    }
    void generateArgs(ostream& out, int i, int c_i_, AST_Ptr c)
    {
        writeComment(out,i,"Generate the arguments to the call");

        writeComment(out,i,"Create first dummy variable");
        writeIndented(out,i);
        child(0)->getType()->binding()->innerCodeGen(out,i);
        if(child(0)->getType()->binding()->needsPointer())
            out << "*";
        out << " ";
        child(3)->innerCodeGen(out,i);
        out << "_" << 0 << "_" << local_count << child(3)->getDecl()->getIndex();
        out << " = ";
        child(0)->valueCodeGen(out,i);
        out << ";\n";

        writeIndented(out,i);
        out << "((";
        child(3)->innerCodeGen(out,i);
        out << "__" << child(3)->getDecl()->getIndex() << "_CLOSURE*)";
        out << "(frame->getVar(\"";
        child(3)->innerCodeGen(out,i);
        out << "__" << child(3)->getDecl()->getIndex() << "_closure\")))->frame->setVar(";
        
        out << "((";
        child(3)->innerCodeGen(out,i);
        out << "__" << child(3)->getDecl()->getIndex() << "_CLOSURE*)";
        out << "(frame->getVar(\"";
        child(3)->innerCodeGen(out,i);
        out << "__" << child(3)->getDecl()->getIndex() << "_closure\")))->args";
        out << "[" << "0" << "]";
        out << ",";
        child(3)->innerCodeGen(out,i);
        out << "_" << 0 << "_" << local_count << child(3)->getDecl()->getIndex();
        out << ");\n";

        writeComment(out,i,"Create second dummy variable");
        writeIndented(out,i);
        child(1)->getType()->binding()->innerCodeGen(out,i);
        if(child(1)->getType()->binding()->needsPointer())
            out << "*";
        out << " ";
        child(3)->innerCodeGen(out,i);
        out << "_" << 1 << "_" << local_count << child(3)->getDecl()->getIndex();
        out << " = ";
        child(1)->valueCodeGen(out,i);
        out << ";\n";

        writeIndented(out,i);
        out << "((";
        child(3)->innerCodeGen(out,i);
        out << "__" << child(3)->getDecl()->getIndex() << "_CLOSURE*)";
        out << "(frame->getVar(\"";
        child(3)->innerCodeGen(out,i);
        out << "__" << child(3)->getDecl()->getIndex() << "_closure\")))->frame->setVar(";
        
        out << "((";
        child(3)->innerCodeGen(out,i);
        out << "__" << child(3)->getDecl()->getIndex() << "_CLOSURE*)";
        out << "(frame->getVar(\"";
        child(3)->innerCodeGen(out,i);
        out << "__" << child(3)->getDecl()->getIndex() << "_closure\")))->args";
        out << "[" << "1" << "]";
        out << ",";
        child(3)->innerCodeGen(out,i);
        out << "_" << 1 << "_" << local_count << child(3)->getDecl()->getIndex();
        out << ");\n";

        writeComment(out,i,"Create third dummy variable");
        writeIndented(out,i);
        child(2)->getType()->binding()->innerCodeGen(out,i);
        if(child(2)->getType()->binding()->needsPointer())
            out << "*";
        out << " ";
        child(3)->innerCodeGen(out,i);
        out << "_" << 2 << "_" << local_count << child(3)->getDecl()->getIndex();
        out << " = ";
        child(2)->valueCodeGen(out,i);
        out << ";\n";

        writeIndented(out,i);
        out << "((";
        child(3)->innerCodeGen(out,i);
        out << "__" << child(3)->getDecl()->getIndex() << "_CLOSURE*)";
        out << "(frame->getVar(\"";
        child(3)->innerCodeGen(out,i);
        out << "__" << child(3)->getDecl()->getIndex() << "_closure\")))->frame->setVar(";
        
        out << "((";
        child(3)->innerCodeGen(out,i);
        out << "__" << child(3)->getDecl()->getIndex() << "_CLOSURE*)";
        out << "(frame->getVar(\"";
        child(3)->innerCodeGen(out,i);
        out << "__" << child(3)->getDecl()->getIndex() << "_closure\")))->args";
        out << "[" << "2" << "]";
        out << ",";
        child(3)->innerCodeGen(out,i);
        out << "_" << 2 << "_" << local_count << child(3)->getDecl()->getIndex();
        out << ");\n";

        writeIndented(out,i);
        child(3)->getDecl()->getType()->binding()->child(0)->innerCodeGen(out,i);
        if(child(3)->getDecl()->getType()->binding()->child(0)->needsPointer())
            out << "*";
        out << " ";
        child(3)->innerCodeGen(out,i);
        out << "_" << 3 << "_" << local_count << child(3)->getDecl()->getIndex();
        out << " = (";
        child(3)->getDecl()->getType()->binding()->child(0)->innerCodeGen(out,i);
        if(child(3)->getDecl()->getType()->binding()->child(0)->needsPointer())
            out << "*";
        out << ")";
        writeClosure(out,i,child(3));
        out << "->fp(";

        out << "(((";
        child(3)->innerCodeGen(out,i);
        out << "__" << child(3)->getDecl()->getIndex() << "_CLOSURE*)";
        out << "(frame->getVar(\"";
        child(3)->innerCodeGen(out,i);
        out << "__" << child(3)->getDecl()->getIndex() << "_closure\")))->frame))";
        out << ";\n";
    }
    void generateFuctionCall(ostream& out, int i)
    {
        writeComment(out,i,"Perform Function Call");

        writeIndented(out,i);
        child(3)->getDecl()->getType()->binding()->child(0)->innerCodeGen(out,i);
        if(child(3)->getDecl()->getType()->binding()->child(0)->needsPointer())
            out << "*";
        out << " ";
        child(3)->innerCodeGen(out,i);
        out << "_PARAM" << 0 << "_" << local_count << child(3)->getDecl()->getIndex();
        out << " = ";
        child(3)->innerCodeGen(out,i);
        out << "__" << child(3)->getDecl()->getIndex() << "(";
        child(3)->innerCodeGen(out,i);
        out << "__" << child(3)->getDecl()->getIndex() << "_closure->frame)";
        out << ";\n";
    }

};

NODE_FACTORY (Slicing_AST, SLICING);
int Slicing_AST::global_count;
    

/***** EMPTY_INTEGER *****/

/** Empty integer argument (to a slice) */
class EmptyInteger_AST : public Typed_Tree {
protected:

    NODE_CONSTRUCTORS (EmptyInteger_AST, Typed_Tree);

    /** Override AST_Tree::_print */
    void _print (ostream& out, int indent) {
        out << "()";
    }

    bool isMissing () {
        return true;
    }

    Type_Ptr computeType () {
        return intDecl->asType ();
    }

};

NODE_FACTORY (EmptyInteger_AST, EMPTY_INTEGER);




/***** ATTRIBUTEREF *****/

/** E.ID */
class AttributeRef_AST : public Typed_Tree {
protected:

    NODE_CONSTRUCTORS (AttributeRef_AST, Typed_Tree);

    AST_Ptr getId () {
        return child (1);
    }

    Decl* getDecl (int k = 0) {
        return getId ()->getDecl (k);
    }

    int numDecls () {
        return getId ()->numDecls ();
    }

    void addTargetDecls (Decl* enclosing) {
    }

    AST_Ptr resolveStaticSelections (const Environ* env) {
        AST_Ptr left = child (0)->resolveStaticSelections (env);
        if (!left->isType ())
            return this;
        AST_Ptr id = getId ();
        if (id->getDecl () != NULL)
            return id;
        string name = id->as_string ();
        const Environ* members = left->getDecl ()->getEnviron ();
        Decl_Vector defns;
        members->find_immediate (name, defns);
        if (defns.empty ()) {
            error (this, "no definition of %s in type", name.c_str ());
            id->addDecl (makeUnknownDecl (name, false));
        }
        for (size_t i = 0; i < defns.size (); i += 1)
            id->addDecl (defns[i]);
        return id;
    }

    AST_Ptr resolveTypes (Decl* context, int& resolved, int& ambiguities) {
        AST_Ptr id = getId ();
        string name = id->as_string ();
        int errs0 = numErrors ();
        replace (0, child (0)->resolveTypes (context));
        if (errs0 == numErrors ()) {
            id->resolveSelectedType (child (0)->getType (),
                                     resolved, ambiguities);
        } else if (id->numDecls () == 0) {
            id->addDecl (makeUnknownDecl (name, false));
        }

        if (!setType (id->getType ()))
            error (this,
                   "attribute %s has no definition that fits the context.",
                   name.c_str ());
        return this;
    }

    AST_Ptr convertMethodCall (AST_Ptr args) {
        AST_Ptr id = getId ();
        if (id->numDecls () > 0 && id->getDecl ()->isMethod ())
            return consTree (CALL, id, args->insert (0, child (0)));
        else
            return NULL;
    }

    AST_Ptr resolveSimpleIds (const Environ* env) {
        replace (0, child (0)->resolveSimpleIds (env));
        return this;
    }

    void checkNoBoundMethodValues () {
        child (0)->checkNoBoundMethodValues ();
        if (getDecl () != NULL && getDecl ()->isMethod ())
            error (this, "bound method value outside a call");
    }    

    //hbradlow
    void stringCodeGen(ostream& out, int i){
        out << "\"";
        child(1)->innerCodeGen(out,i);
        out << "\"";
    }
    void lhsFrameCodeGen (std::ostream& out, int i){
        out << "((";
        child(0)->getType()->binding()->innerCodeGen(out,i);
        out << "*)(frame->getVar(\"";
        child(0)->innerCodeGen(out,i);
        out << "\")))";
    }
    //hbradlow
    void innerCodeGen(ostream& out, int i){
        /*
        child(0)->innerCodeGen(out,i);
        out << "->";
        child(1)->innerCodeGen(out,i);
        */
        out << "(";
        child(1)->getType()->binding()->innerCodeGen(out,i);
        out << "*)(((";
        child(0)->getType()->binding()->innerCodeGen(out,i);
        out << "*)(frame->getVar(\"";
        child(0)->innerCodeGen(out,i);
        out << "\")))->frame->getVar(\"";
        child(1)->innerCodeGen(out,i);
        out << "\"))";
        /*
        out << "*(";
        child(1)->getType()->binding()->innerCodeGen(out,i);
        out << "*)";
        out << "(classVariables.find(\"";
        child(0)->getType()->binding()->innerCodeGen(out,i);
        out << ".";
        child(1)->innerCodeGen(out,i);
        out << "\")->second)";
        */
    }
    //hbradlow
    void outerCodeGen(ostream& out, int i){
        writeIndented(out,i);
        innerCodeGen(out,i);
        out << ";\n";
    }
};

NODE_FACTORY (AttributeRef_AST, ATTRIBUTEREF);

/***** TUPLE *****/

/** (E1, ...)  */
class Tuple_AST : public Typed_Tree {
protected:

    NODE_CONSTRUCTORS (Tuple_AST, Typed_Tree);

    AST_Ptr resolveTypes (Decl* context, int& resolved, int& ambiguities) {
        Typed_Tree::resolveTypes (context, resolved, ambiguities);
        if (arity () > 3)
            error (this, "tuple has too many elements (max 3)");
        Type_Ptr componentTypes[3];
        for (size_t i = 0; i < arity (); i += 1)
            componentTypes[i] = child (i)->getType ();
        Type_Ptr tupleType =
            tupleDecl[arity ()]->asType (arity (), componentTypes);
        if (!setType (tupleType))
            error (this, "type mismatch on tuple");
        return this;
    }        

    //hbradlow
    void innerCodeGen(ostream& out,int i){
        out << "new Tuple" << arity();
        if (arity())
        {
            out << "<";
            for_each_child(c,this){
                if(c_i_!=0)
                    out << ",";
                c->getType()->binding()->innerCodeGen(out, i);
            } end_for;
            out << ">";
        }
        out  << "(";
        for_each_child(c,this){
            if(c_i_!=0)
                out << ",";
            c->valueCodeGen(out,i);
        } end_for;
        out << ")";
    }
    //hbradlow
    void outerCodeGen(ostream& out,int i){
        writeIndented(out,i);
        innerCodeGen(out,i);
        out << ";\n";
    }

};

NODE_FACTORY (Tuple_AST, TUPLE);

/***** TARGET_LIST *****/

/** (TARGET, ...) on left-hand side of assignment, for. */
class TargetList_AST : public Tuple_AST {
protected:

    NODE_CONSTRUCTORS (TargetList_AST, Tuple_AST);

    void addTargetDecls (Decl* enclosing) {
        for_each_child (c, this) {
            c->addTargetDecls (enclosing);
        } end_for;
    }

    AST_Ptr convertNone (bool) {
        for_each_child_var (c, this) {
            c = c->convertNone (true);
        } end_for;
        return this;
    }

    void assignCodeGen(ostream& out, int i, AST_Ptr c,string lhs){
        for_each_child(ch,this){
            stringstream ss;
            ss << "(";
            c->valueCodeGen(ss,i);
            ss << ")->getItem(new Integer(" << ch_i_ << "))";
            ch->assignCodeGen(out,i,ss.str(),lhs);
        } end_for;
    }
};

NODE_FACTORY (TargetList_AST, TARGET_LIST);


/***** LIST_DISPLAY *****/

/** [E1, ...]  */
class ListDisplay_AST : public Typed_Tree {
public:
    static int global_count;
    int local_count;
protected:

    NODE_CONSTRUCTORS (ListDisplay_AST, Typed_Tree);

    AST_Ptr resolveTypes (Decl* context, int& resolved, int& ambiguities) {
        Typed_Tree::resolveTypes (context, resolved, ambiguities);
        Type_Ptr componentType;
        if (arity () == 0)
            componentType = Type::makeVar ();
        else
            componentType = child (0)->getType ();
        for (size_t i = 1; i < arity (); i += 1)
            if (!componentType->unify (child (i)->getType ())) {
                error (child (i), "type mismatch in list display");
                break;
            }
        Type_Ptr listType =
            listDecl->asType (1, componentType);
        if (!setType (listType))
            error (this, "type mismatch on list display");
        return this;
    }    
    //hbradlow
    void memCodeGen(ostream& out,int i){
        local_count = global_count++;

        writeIndented(out,i);
        out << "vector";
        out << "<";
        out << "Object*";
        out << "> ";
        out << "list_vector" << local_count << ";\n";

        for_each_child(c,this){
            writeIndented(out,i);
            out << "list_vector" << local_count << ".push_back(";
            c->valueCodeGen(out,i);
            out << ");\n";
        } end_for;
    }
    //hbradlow
    void innerCodeGen(ostream& out,int i){
        out << "new List";
        out  << "(";
        out << "list_vector" << local_count;
        out << ")";
    }
    //hbradlow
    void outerCodeGen(ostream& out,int i){
        writeIndented(out,i);
        innerCodeGen(out,i);
        out << ";\n";
    }

};

NODE_FACTORY (ListDisplay_AST, LIST_DISPLAY);
int ListDisplay_AST::global_count;


/***** DICT_DISPLAY *****/

/**       */
class DictDisplay_AST : public Typed_Tree {
public:
    static int global_count;
    int local_count;
protected:

    NODE_CONSTRUCTORS (DictDisplay_AST, Typed_Tree);

    AST_Ptr resolveTypes (Decl* context, int& resolved, int& ambiguities) {
        Typed_Tree::resolveTypes (context, resolved, ambiguities);
        Type_Ptr keyType, valType;
        if (arity () == 0) {
            keyType = Type::makeVar ();
            valType = Type::makeVar ();
        } else  {
            keyType = child (0)->child (0)->getType ();
            valType = child (0)->child (1)->getType ();
        }
        for (size_t i = 1; i < arity (); i += 1) {
            if (!keyType->unify (child (i)->child (0)->getType ())) {
                error (child (i), "key type mismatch in dict display");
                break;
            }
            if (!valType->unify (child (i)->child (1)->getType ())) {
                error (child (i), "value type mismatch in dict display");
                break;
            }
        }
        Type_Ptr dictType =
            dictDecl->asType (2, keyType, valType);
        if (!setType (dictType))
            error (this, "type mismatch on dict display");
        return this;
    }

    //hbradlow
    void memCodeGen(ostream& out,int i){
        local_count = global_count++;

        writeIndented(out,i);
        out << "map";
        out << "<";
        out << "string";
        out << ",Object*";
        out << "> ";
        out << "dict_map" << local_count << ";\n";

        for_each_child(c,this){
            writeIndented(out,i);
            out << "dict_map" << local_count << "[(";
            c->child(0)->valueCodeGen(out,i);
            out << ")->getValue()] = ";
            c->child(1)->valueCodeGen(out,i);
            out << ";\n";
        } end_for;
    }
    //hbradlow
    void innerCodeGen(ostream& out,int i){
        out << "new Dict";
        out  << "(";
        out << "dict_map" << local_count;
        out << ")";
    }
    //hbradlow
    void outerCodeGen(ostream& out,int i){
        writeIndented(out,i);
        innerCodeGen(out,i);
        out << ";\n";
    }

};

NODE_FACTORY (DictDisplay_AST, DICT_DISPLAY);
int DictDisplay_AST::global_count;



/** A class of expression in which its subexpressions must agree as to
 *  type and its value's type is that of its subexpressios. */
class BalancedExpr : public Typed_Tree {
protected:

    NODE_BASE_CONSTRUCTORS (BalancedExpr, Typed_Tree);

    AST_Ptr resolveTypes (Decl* context, int& resolved, int& ambiguities) {
        int k = arity ();
        Typed_Tree::resolveTypes (context, resolved, ambiguities);
        if (!child (k - 2)->getType ()->unify (child (k - 1)->getType ()))
            error (this, "types of alternatives do not match");
        if (!setType (child (k - 1)->getType ()))
            error (loc (), "inconsistent types");
        return this;
    }

};

/***** IF_EXPR *****/

/**  E1 if Cond else E2  */
class IfExpr_AST : public BalancedExpr {
public:
    static int global_count;
    int local_count;
protected:

    NODE_CONSTRUCTORS (IfExpr_AST, BalancedExpr);

    void defCodeGen(ostream& out,int i){
        local_count = global_count++;
        writeComment(out,i,"----------------------------start--------------------");
        writeComment(out,i,"IFEXPR Function stuff");

        writeIndented(out,i);
        out << "void*";
        out << " IFEXPR1_" << local_count;
        out << "(";
        out << "Frame* frame";
        out << "){\n";
        child(1)->memCodeGen(out,i+1);
        writeIndented(out,i+1);
        out << "return ";
        child(1)->innerCodeGen(out,i+1);
        out << ";\n";
        writeIndented(out,i);
        out << "}\n";

        writeIndented(out,i);
        out << "void*";
        out << " IFEXPR2_" << local_count;
        out << "(";
        out << "Frame* frame";
        out << "){";
        child(2)->memCodeGen(out,i+1);
        writeIndented(out,i+1);
        out << "return ";
        child(2)->innerCodeGen(out,i+1);
        out << ";\n";
        out << "}\n";
        writeComment(out,i,"----------------------------end----------------------");

    }
    //hbradlow
    void memCodeGen(ostream& out, int i){
        child(0)->memCodeGen(out,i);
    }
    //hbradlow
    void innerCodeGen(ostream& out, int i){
        out << "(Object*)(((*";
        child(0)->valueCodeGen(out,i);
        out << ")==true) ? ";
        out << "IFEXPR1_" << local_count << "(frame)";
        out << " : ";
        out << "IFEXPR2_" << local_count << "(frame)";
        out << ")";
    }
    //hbradlow
    void outerCodeGen(ostream& out, int i){
        writeIndented(out,i);
        innerCodeGen(out,i);
        out << ";\n";
    }
}; 
NODE_FACTORY (IfExpr_AST, IF_EXPR);
int IfExpr_AST::global_count;

/***** AND *****/

/** E1 and E2 */
class And_AST : public BalancedExpr {
protected:
    
    void innerCodeGen(ostream& out, int depth) {
        child(0)->innerCodeGen(out, depth);
        out << " && ";
        child(1)->innerCodeGen(out, depth);
    }
    void outerCodeGen(ostream& out, int depth) {
        writeIndented(out,depth);
        innerCodeGen(out,depth);
        out << ";\n";
    }
    NODE_CONSTRUCTORS (And_AST, BalancedExpr);
    void valueCodeGen(ostream& out, int i){
        out << "(*(";
        child(0)->valueCodeGen(out, i);
        out << ")";
        out << " && ";
        out << "*(";
        child(1)->valueCodeGen(out, i);
        out << "))";
    }
    
};

NODE_FACTORY (And_AST, AND);

/***** OR *****/

/** E1 or E2 */
class Or_AST : public BalancedExpr {
protected:

    NODE_CONSTRUCTORS (Or_AST, BalancedExpr);

    void innerCodeGen(ostream& out, int depth) {
        child(0)->innerCodeGen(out, depth);
        out << " || ";
        child(1)->innerCodeGen(out, depth);
    }
    void outerCodeGen(ostream& out, int depth) {
        writeIndented(out,depth);
        innerCodeGen(out,depth);
        out << ";\n";
    }
    void valueCodeGen(ostream& out, int i){
        out << "(*(";
        child(0)->valueCodeGen(out, i);
        out << ")";
        out << " || ";
        out << "*(";
        child(1)->valueCodeGen(out, i);
        out << "))";
    }
};

NODE_FACTORY (Or_AST, OR);


class Break_AST : public AST_Tree{
protected:

    NODE_CONSTRUCTORS (Break_AST, AST_Tree);

    void innerCodeGen(ostream& out, int depth) {
        out << "break";
    }
    void outerCodeGen(ostream& out, int depth) {
        writeIndented(out,depth);
        innerCodeGen(out,depth);
        out << ";\n";
    }
};

NODE_FACTORY (Break_AST, BREAK);

