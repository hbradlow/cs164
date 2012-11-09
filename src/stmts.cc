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

class Print_AST : public Println_AST {
protected:
    NODE_CONSTRUCTORS (Print_AST, Println_AST);
};

NODE_FACTORY (Print_AST, PRINT);

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
    Type_Ptr getType(){
        for_each_child(c,this){
            if(c->getReturnNode()!=NULL){
                return c->getReturnNode()->child(0)->getType();
            }
        } end_for;
        return NULL;
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
    void resolveSimpleIds (const Environ *env)
    {
        //child(0)->resolveSimpleTypeIds(env);
        //child(1)->resolveSimpleTypeIds(env);
        printf("\nin assignment_ast resolving\n");
        child(1)->print(cout,0);
        child(1)->resolveSimpleIds(env);
        child(1)->print(cout,0);
        child(0)->resolve_reference(env);
        child(1)->resolve_reference(env);
        child(0)->unifyWith(child(1));
    }
    NODE_CONSTRUCTORS (Assignment_AST, AST_Tree); 
};

NODE_FACTORY (Assignment_AST, ASSIGN);

/** Kevin : This entire class deals with parameter definitions */
class FormalsList_AST : public AST_Tree {
protected:

    NODE_CONSTRUCTORS (FormalsList_AST, AST_Tree);

    void collectDecls (Decl* enclosing)
    {
        for_each_child(c, this)
        {
            c->collectParams(enclosing, c_i_);
        } end_for;
    }

    void resolveSimpleIds (const Environ* env)
    {
        for_each_child(c,this)
        {
            c->resolveSimpleTypeIds(env); 
        } end_for; 
    }
};

NODE_FACTORY (FormalsList_AST, FORMALS_LIST);

/** Kevin : This deals with attributerefs */ 
class AttributeRef_AST : public AST_Tree {
protected:

    NODE_CONSTRUCTORS (AttributeRef_AST, AST_Tree);

    void resolveSimpleIds(const Environ *env) 
    {
        resolve_reference(env);
    }

    void collectDecls (Decl* enclosing) 
    {
    }

    void addTargetDecls (Decl* enclosing)
    {
    }

    void check_bound_methods (bool inside_call) 
    {
        if (inside_call)
            return; 
        Decl *classDecl = child(1)->getDecl();
        if (classDecl->isMethod())
            error(loc(), "Not calling bound method");
    }

    Type_Ptr getType()
    {
        return child(1)->getType();
    }

    void resolve_reference (const Environ *env)
    {
        child(0)->resolveSimpleIds(env);
        Decl *childDecl = env->find(child(0)->as_string());
        // If decl is a class, the rewrite will take care of it
        if (childDecl != NULL)
        {
            if (childDecl->isClass())
                return;
            Type_Ptr type = childDecl->getType()->binding();
            if (type->arity() == 0) 
            {
                error(loc(), "Attribute does not exit");
            }
            string str = type->child(0)->as_string();
            child(1)->create_attr_ref(env->find(str));
        } 
    }

    AST_Ptr replace_attribute_refs()
    {
        if (child(0)->getDecl(0)->isClass())
        {
            // In case of multiple layers of references 
            this->replace(1, child(1)->replace_attribute_refs());
            // Create the new node
            Decl *classDecl = child(0)->getDecl(0);
            Decl *referencedDecl = classDecl->getEnviron()->find_immediate(child(1)->as_string());
            NodePtr newNode = make_id(referencedDecl->getName().c_str(), this->loc());
            // Set the declaration of the new node to be the declaration that the reference 
            // is decorated with 
            newNode->addDecl(referencedDecl);
            return newNode;
        } else return this;
    }
};

NODE_FACTORY (AttributeRef_AST, ATTRIBUTEREF);

//hbradlow
class Return_AST: public AST_Tree {
protected:
    NODE_CONSTRUCTORS (Return_AST, AST_Tree);
    AST_Ptr getReturnNode(){
        return this;
    }
};
NODE_FACTORY (Return_AST, RETURN);

class Get_Item_AST: public AST_Tree
{
    NODE_CONSTRUCTORS (Get_Item_AST, AST_Tree);
protected:
    Type_Ptr getType()
    {
        return child(0)->getType();
    }
};
NODE_FACTORY(Get_Item_AST, SUBSCRIPTION);
