/* -*- mode: C++; c-file-style: "stroustrup"; indent-tabs-mode: nil; -*- */

/* exprs.cc: AST subclasses related to expressions. */

/* Authors:  YOUR NAMES HERE */

#include <iostream>
#include "apyc.h"
#include "ast.h"
#include "apyc-parser.hh"

using namespace std;

/*****   EXPR_LIST    *****/

/** A list of expressions. */
class Expr_List_AST : public AST_Tree {
protected:

    NODE_CONSTRUCTORS (Expr_List_AST, AST_Tree);

};

NODE_FACTORY (Expr_List_AST, EXPR_LIST);


/* The following is an EXAMPLE of a potentially useful AST class
 * structure, showing the macros you can use to set up base classes
 * and their subtypes. */

/*****   CALLS    *****/

/** The supertype of "callable" things, including ordinary calls,
 *  binary operators, unary operators, subscriptions, and slices. */

class Callable : public AST_Tree {
protected:

    NODE_BASE_CONSTRUCTORS (Callable, AST_Tree);
    
    /** Returns the expression representing the quantity that is
     *  called to evaluate this expression. */
    virtual AST_Ptr calledExpr () = 0;

    /** Returns the number of actual parameters in this call. */
    virtual int numActuals () = 0;

    /** Return the Kth actual parameter in this call. */
    virtual AST_Ptr actualParam (int k) = 0;

    /** Set the Kth actual parameter in this call to EXPR. */
    virtual void setActual (int k, AST_Ptr expr) = 0;


};

/** A function call. */
class Call_AST : public Callable {
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

    // PUT COMMON CODE DEALING WITH TYPE-CHECKING or SCOPE RULES HERE.
    // USE THE METHODS ABOVE TO ADAPT IT TO PARTICULAR TYPES OF NODE.

};

NODE_FACTORY (Call_AST, CALL);

/** A binary operator. */
class Binop_AST : public Callable {

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
        child (1)->replace (2*k, expr);
    }

};    

NODE_FACTORY (Binop_AST, BINOP);

/** A unary operator. */
class Unop_AST : public Callable {

    NODE_CONSTRUCTORS (Unop_AST, Callable);

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
        child (1)->replace (2*k, expr);
    }

};    

NODE_FACTORY (Unop_AST, UNOP);


class Function_AST: public AST_Tree {
public:
    bool is_init(){
        return strcmp(this->child(0)->as_string().c_str(),"__init__") == 0;
    }
protected:

    NODE_CONSTRUCTORS (Function_AST, AST_Tree);
};

NODE_FACTORY (Function_AST, METHOD);

class Class_AST: public AST_Tree{
public:
    void append_init()
    {
        for_each_child (c, this) {
            if(c->is_init()){
                return;
            }
        } end_for;

        NodePtr i = AST::make_token(ID,8,"__init__",true);
        NodePtr s = AST::make_token(ID,4,"self",true);

        std::vector<NodePtr> formals_v;
        formals_v.push_back(s);
        NodePtr formals = make_tree(FORMALS_LIST,formals_v.begin(),formals_v.end());

        std::vector<NodePtr> empty_v;
        NodePtr empty = make_tree(EMPTY,empty_v.begin(),empty_v.end());

        std::vector<NodePtr> stmt_v;
        NodePtr stmt = make_tree(STMT_LIST,stmt_v.begin(),stmt_v.end());

        std::vector<NodePtr> block_v;
        block_v.push_back(stmt);
        NodePtr block = make_tree(BLOCK,block_v.begin(),block_v.end());

        std::vector<NodePtr> def_v;
        def_v.push_back(i);
        def_v.push_back(formals);
        def_v.push_back(empty);
        def_v.push_back(block);
        NodePtr def = make_tree(DEF,def_v.begin(),def_v.end());
        this->insert(0,def);
    }
protected:

    NODE_CONSTRUCTORS (Class_AST, AST_Tree);

    Decl* getDecl () {
        return child (0)->getDecl ();
    }

    void addDecl (Decl* decl) {
        child (0)->addDecl (decl);
    }

};

NODE_FACTORY (Class_AST, CLASS_BLOCK);
