/* -*- mode: C++; c-file-style: "stroustrup"; indent-tabs-mode: nil; -*- */

/* stmts.cc: AST subclasses related to statements and modules. */

/* Authors:  YOUR NAMES HERE */

#include <iostream>
#include <sstream>
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
    bool assert_none_here(int k){
        if(k==0)
        {
            error(loc(),"Cannot assign to None");
            return false;
        }
        return true;
    }

    void collectDecls(Decl *enclosing)
    {
        child(0)->addTargetDecls(enclosing);
    }
    void resolveSimpleIds (const Environ *env)
    {
        child(0)->resolveSimpleIds(env);
        child(1)->resolveSimpleIds(env);
        child(0)->unifyWith(child(1));
    }

    NODE_CONSTRUCTORS (Assignment_AST, AST_Tree); 
};

NODE_FACTORY (Assignment_AST, ASSIGN);

/** Kevin : This entire class deals with parameter definitions */
class FormalsList_AST : public AST_Tree {
protected:

    NODE_CONSTRUCTORS (FormalsList_AST, AST_Tree);

    bool assert_none_here(int k){
        error(loc(), "Cannot use None as a method parameter");
        return false;
    }

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
        child(0)->resolveSimpleIds(env);
        resolve_reference(env);
    }
    bool is_attribute_ref(){
        return true;
    }

    void collectDecls (Decl* enclosing) 
    {

    }

    void addTargetDecls (Decl* enclosing)
    {
    }

    void unifyWith(AST_Ptr right){
        Unwind_Stack s;
        Type_Ptr t1 = this->getType();
        if (t1 == NULL)
        {
            string str = "Attribute '" + this->child(1)->as_string() + "' does not exist.";
            error(loc(), str.c_str());
            return;
        }
        Type_Ptr t2 = right->getType();
        if(t2!=NULL)
        {
            int b = t1->unify(t2,s);
            if(b==0){
                error(loc(),"Incompatible types");
            }
        }
    }

    void check_bound_methods (bool inside_call) 
    {
        if (inside_call)
            return; 
        Decl *varDecl = child(1)->getDecl();
        if (varDecl->isMethod())
            error(loc(), "Not calling bound method");
    }

    Type_Ptr getType()
    {
        Decl *classDecl = child(0)->getDecl(0); 
        if (classDecl == NULL)
        {
            return NULL;
        }
        const Environ *innerEnv;
        if (classDecl->isClass())
        {
           innerEnv = classDecl->getEnviron(); 
        }
        else innerEnv = classDecl->getContainer()->getEnviron();
        child(1)->resolveSimpleIds(innerEnv);
        return child(1)->getType();
    }

    void resolve_reference (const Environ *env)
    {
        Decl *childDecl = env->find(child(0)->as_string());
        // If decl is a class, the rewrite will take care of it
        if (childDecl != NULL)
        {
            if (childDecl->isClass())
                return;
            Type_Ptr type = childDecl->getType()->binding();
            if (type->arity() == 0) 
            {
                string str = "Attribute '" + childDecl->getName() + "' does not exist.";
                error(loc(), str.c_str());
            }
            string str = type->child(0)->as_string();
            child(1)->create_attr_ref(env->find(str));
        } 
    }

    AST_Ptr replace_attribute_refs()
    {
        if (child(0)->getDecl(0) == NULL)
        {
            // This is a A().x type, so it doesn't get replaced. 
            return this;
        }
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
    Decl* getDecl(int k) 
    {
        Decl *decl = child(1)->getDecl(0);
        if (decl) 
            return decl;
        return child(0)->getDecl(0)->getContainer()->getEnviron()->find(child(1)->as_string()); 
    }
    void addDecl(Decl* decl) 
    {
        child(1)->addDecl(decl);
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
public:
    NODE_CONSTRUCTORS (Get_Item_AST, AST_Tree);
protected:
    Type_Ptr getType()
    {
        string id = child(0)->getType()->binding()->child(0)->as_string();
        if(strcmp("dict",id.c_str())==0)
        {
            return child(0)->getType()->binding()->child(1)->child(1)->asType();
        }
        else if(strcmp("str",id.c_str())==0)
        {
            return child(0)->getType()->binding();
        }
        else if(strcmp("list",id.c_str())==0)
        {
            return child(0)->getType()->binding()->child(1)->child(0)->asType();
        }
        else{
            error(loc(),"Cannot use __getitem__ on something other than str, dict, list");
            return NULL;
        }
    }

    void unifyWith(AST_Ptr right){
        Type_Ptr t1 = right->getType();
        if(t1!=NULL)
        {
            Unwind_Stack s;
            int b = this->getType()->unify(right->getType(),s);
            if(b==0){
                error(loc(),"Incompatible types");
            }
        }
    }
};
NODE_FACTORY(Get_Item_AST, SUBSCRIPTION);

class Slice_Item_AST: public Get_Item_AST
{
    NODE_CONSTRUCTORS (Slice_Item_AST, Get_Item_AST);
    Type_Ptr getType()
    {
        return child(0)->getType()->binding();
    }
};
NODE_FACTORY(Slice_Item_AST, SLICING);


class Block_Scope: public AST_Tree
{
public: 
    NODE_CONSTRUCTORS(Block_Scope, AST_Tree);
    void collectDeclsTransparent(Decl* enclosing)
    {
        this->collectDecls(enclosing);
    }
    void resolveSimpleIds(const Environ* env)
    {
        for_each_child(c,this)
        {
            c->resolveSimpleIds(_mydecl->getEnviron());
        } end_for;
    }
    Decl* _mydecl;
};

class For_Stmt_AST: public Block_Scope
{
    NODE_CONSTRUCTORS (For_Stmt_AST, Block_Scope);
public: 
    void collectDecls(Decl* enclosing)
    {
        string name;
        stringstream out;
        out << lineNumber();
        name = "___for___" + out.str();
        _mydecl = makeFuncDecl(name, enclosing, Type::makeVar(), NULL);
        enclosing->addMember(_mydecl);
        child(0)->addTargetDecls(_mydecl);
    }
};

NODE_FACTORY(For_Stmt_AST, FOR);

class While_AST: public Block_Scope
{
    NODE_CONSTRUCTORS (While_AST, Block_Scope);    
    void collectDecls(Decl* enclosing)
    {
        string name;
        stringstream out;
        out << lineNumber();
        name = "___while___" + out.str();
        _mydecl = makeFuncDecl(name, enclosing, Type::makeVar(), NULL);
        enclosing->addMember(_mydecl);
        for_each_child(c, this)
        {
            c->collectDeclsTransparent(_mydecl);
        } end_for;
    }
};

NODE_FACTORY(While_AST, WHILE);

class If_AST: public Block_Scope
{
    NODE_CONSTRUCTORS (If_AST, Block_Scope);
    void collectDecls(Decl* enclosing)
    {
        string name;
        stringstream out;
        out << lineNumber();
        name = "___if___" + out.str();
        _mydecl = makeFuncDecl(name, enclosing, Type::makeVar(), NULL);
        enclosing->addMember(_mydecl);
        for_each_child(c, this)
        {
            c->collectDeclsTransparent(_mydecl);
        } end_for;
    }
    Type_Ptr getType(){
        for_each_child(c,this){
            if(c_i_ !=0 && c->getType()!=NULL){
                return c->getType();
            }
        } end_for;
        return NULL;
    }
};
NODE_FACTORY(If_AST, IF);
