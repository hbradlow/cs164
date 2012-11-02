/* -*- mode: C++; c-file-style: "stroustrup"; indent-tabs-mode: nil; -*- */

/* stmts.cc: AST subclasses related to statements and modules. */

/* Authors:  YOUR NAMES HERE */

#include <iostream>
#include "apyc.h"
#include "ast.h"
#include "apyc-parser.hh"

using namespace std;

/*****   PRINTLN   *****/

/** A print statement without trailing comma. */
class Println_AST : public AST_Tree {
protected:

    NODE_CONSTRUCTORS (Println_AST, AST_Tree);

    const char* externalName () {
	return "println";
    }

};

NODE_FACTORY (Println_AST, PRINTLN);

/***** STMT_LIST *****/

/** A list of statements. */
class StmtList_AST : public AST_Tree {
protected:

    NODE_CONSTRUCTORS (StmtList_AST, AST_Tree);

    AST_Ptr doOuterSemantics () {
        for_each_child_var (c, this) {
            c = c->doOuterSemantics ();
        } end_for;
        return this;
    }

};

NODE_FACTORY (StmtList_AST, STMT_LIST);

/* A node for assignments */

class Assignment_AST : public AST_Tree 
{
public:
    void assert_none_here(int k){
        if(k==0)
            error(loc(),"Cannot assign to None");
    }

    void collectDecls(Decl *enclosing)
    {
        child(0)->addTargetDecls(enclosing);
    }

    NODE_CONSTRUCTORS (Assignment_AST, AST_Tree); 
};

NODE_FACTORY (Assignment_AST, ASSIGN);

class FormalsList_AST : public AST_Tree {
protected:

    NODE_CONSTRUCTORS (FormalsList_AST, AST_Tree);

    void collectDecls(Decl *enclosing)
    {
        for_each_child(c, this)
        {
            enclosing->addParamDecl(c, c_i_);
        } end_for; 
    }
};

NODE_FACTORY (FormalsList_AST, FORMALS_LIST);


