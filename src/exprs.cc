/* -*- mode: C++; c-file-style: "stroustrup"; indent-tabs-mode: nil; -*- */

/* exprs.cc: AST subclasses related to expressions. */

/* Authors:  YOUR NAMES HERE */

#include <iostream>
#include "apyc.h"
#include "ast.h"
#include "apyc-parser.hh"
#include <algorithm>

using namespace std;

//hbradlow
class TargetList_AST : public AST_Tree {
protected:
    NODE_CONSTRUCTORS (TargetList_AST, AST_Tree);

    void unifyWith(AST_Ptr right){
        for_each_child(c,this){
            c->unifyWith(right->getType()->binding()->child(1)->child(c_i_));
        } end_for;
    }

    void addTargetDecls(Decl* enclosing)
    {
        for_each_child(c,this)
        {
            c->addTargetDecls(enclosing);
        } end_for; 
    }
};

NODE_FACTORY (TargetList_AST, TARGET_LIST);

/*****   EXPR_LIST    *****/

/** A list of expressions. */
class Expr_List_AST : public AST_Tree {
protected:

    NODE_CONSTRUCTORS (Expr_List_AST, AST_Tree);

    void check_defined(){
        for_each_child(c, this)
        {
            c->assert_is_defined();
            c->check_defined();
        } end_for;
    }
    void resolveSimpleIds (const Environ* env)
    {
        for_each_child(c, this)
        {
            c->resolveSimpleIds(env);
        } end_for;
    }
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

    void check_bound_methods (bool inside_call)
    {
        for_each_child(c,this)
        {
            c->check_bound_methods(true);
        } end_for;
    }

    //hbradlow - 4.1
    void rewrite_types(Decl* enclosing){
        for_each_child(c,this){
            c->rewrite_types(enclosing);
        } end_for;

        Decl *decl = enclosing->getEnviron()->find_immediate(child(0)->as_string());
        if(decl!=NULL && decl->isType()){
            vector<NodePtr> dummy;
            vector<NodePtr> type_v;
            type_v.push_back(child(0));
            type_v.push_back(make_tree(TYPE_LIST,dummy.begin(),dummy.end()));
            NodePtr type = make_tree(TYPE,type_v.begin(),type_v.end());
            type->collectDecls(enclosing);
            this->replace(0,type);
        }
    }
    //hbradlow - 4.3
    AST_Ptr rewrite_allocators(Decl* enclosing){
        for_each_child(c,this){
            c->rewrite_allocators(enclosing);
        } end_for;

        if(child(0)->asType()!=NULL) 
        {
            NodePtr t = child(0);
            if(t->child(0)->getDecl()->is_built_in()){
                error(loc(),"Cannot allocate with a built in type");
            }
            NodePtr i = AST::make_token(ID,8,"__init__",true);

            Decl *tdecl = enclosing->getEnviron()->find_immediate(t->child(0)->as_string());
            Decl *decl = tdecl->getEnviron()->find_immediate("__init__");

            i->addDecl(decl);
            NodePtr expr_list = child(1);

            std::vector<NodePtr> new_v;
            new_v.push_back(t->child(0));
            NodePtr n = make_tree(NEW,new_v.begin(),new_v.end());
            expr_list->insert(0,n);

            std::vector<NodePtr> call_v;
            call_v.push_back(i);
            call_v.push_back(expr_list);
            AST_Ptr tree = make_tree(CALL1,call_v.begin(),call_v.end());
            return tree;
        }
        return this;
    }

    void insertActual (int k, AST_Ptr expr) {
        child (1)->insert (k, expr);
    }
    void setActual (int k, AST_Ptr expr) {
        child (1)->replace (k, expr);
    }

    //hbradlow
    void checkCalls ()
    {
        //hbradlow: Hack to check the types of calls that are not assigned to anything
        this->getType();
    }
    //hbradlow
    Type_Ptr
    getType ()
    {
        vector<Type_Ptr> actual_types;
        if(child(0)->is_attribute_ref()){
            actual_types.push_back(child(0)->child(0)->getType()->binding());
        }
        for(int i = 0; i<this->numActuals(); i++)
        {
            Type_Ptr t1 = this->actualParam(i)->getType();
            actual_types.push_back(t1);
        }

        Type_Ptr func_type = child(0)->getType();
        if(func_type==NULL){
            error(loc(),"Function not defined");
            return NULL;
        }
        func_type = func_type->binding()->freshen();

        if(func_type->child(1)->arity()!=actual_types.size()){
            error(loc(),"Incorrect number of arguments");
            Type_Ptr t = func_type->returnType();
            return t;
        }
        for(int i = 0; i<actual_types.size(); i++)
        {
            Type_Ptr t1 = actual_types[i];
            Type_Ptr t2 = func_type->child(1)->child(i)->asType();

            Unwind_Stack s;
            int b = t1->unify(t2,s);
            if(b==0){
                error(loc(),"Invalid types to function call");
            }
        }
        Type_Ptr t = func_type->returnType();
        return t;
    }

    Decl* getDecl(int k)
    {
        return NULL;
    }
};

NODE_FACTORY (Call_AST, CALL);


/** A function call. */
//hbradow - 4.3
class Call1_AST : public Call_AST {
protected:
    NODE_CONSTRUCTORS (Call1_AST, Call_AST);

    //hbradow - 4.3
    Type_Ptr getType ()
    {
        //return the first element of the expression list
        std::vector<NodePtr> tl_v;
        AST_Ptr tl = make_tree(TYPE_LIST,tl_v.begin(),tl_v.end());
        std::vector<NodePtr> t_v;
        t_v.push_back(child(1)->child(0)->child(0));
        t_v.push_back(tl);
        Type_Ptr t = make_tree(TYPE,t_v.begin(),t_v.end())->asType();
        return t;
    }

    Decl* getDecl(int k)
    {
        return child(0)->getDecl(0);
    }

};
NODE_FACTORY (Call1_AST, CALL1);

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
    
    /** Kevin: Prevent operator from being checked during resolve */
    void resolveSimpleIds(const Environ *env)
    {
        child(0)->resolveSimpleIds(env);
        child(2)->resolveSimpleIds(env);
        child(0)->unifyWith(child(2)); //hbradlow
    }

    //hbradlow
    Type_Ptr getType(){
        //FIXME
        return child(0)->getType();
    }

};    
NODE_FACTORY (Binop_AST, BINOP);

/** Kevin : A compare. */
class Compare_AST : public Callable{
public:
    NODE_CONSTRUCTORS (Compare_AST, Callable);

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
    
    /** Kevin: Prevent operator from being checked during resolve */
    void resolveSimpleIds(const Environ *env)
    {
        child(0)->resolveSimpleIds(env);
        child(2)->resolveSimpleIds(env);
        child(0)->unifyWith(child(2)); //hbradlow
    }
    //hbradlow
    Type_Ptr getType(){
        return this->computeType();
    }
    Type_Ptr computeType () {
        if(boolDecl==NULL)
        {
            error(loc(),"bool not defined");
            return NULL;
        }
        return boolDecl->asType ();
    }

};    
NODE_FACTORY (Compare_AST, COMPARE);

class LeftCompare_AST : public Compare_AST {
public:
    NODE_CONSTRUCTORS (LeftCompare_AST, Compare_AST);
};
NODE_FACTORY (LeftCompare_AST, LEFT_COMPARE);

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
    /** Kevin: unop has different identifiers than normal call*/
    void resolveSimpleIds(const Environ *env)
    {
        child(1)->resolveSimpleIds(env);
    }
    Type_Ptr getType(){
        return child(1)->getType();
    }

};    
NODE_FACTORY (Unop_AST, UNOP);


class Def_AST: public AST_Tree {
public:
    bool is_init(){
        return strcmp(this->child(0)->as_string().c_str(),"__init__") == 0;
    }
    bool assert_none_here(int k){
        error(loc(), "Cannot use None as a method name");
        return false;
    }

    void collectDecls(Decl *enclosing)
    {
        Decl *decl = enclosing->getEnviron()->find_immediate(child(0)->as_string());
        if (decl != NULL ) {
            if (!decl->isFunc())
                error(loc(), "Trying to assign function to pre-defined variable");
            child(0)->addDecl(decl);
            decl->addSignature(child(1));
        }
        else {
            decl = enclosing->addDefDecl(this); 
            child(0)->addDecl(decl);
            decl->addSignature(child(1));
        }
        child(2)->resolveSimpleIds(enclosing->getEnviron());
    }
    Type_Ptr getType(){
        return child(2)->asType();
    }

    void collectParams (Decl* enclosing, int k) 
    {
        child(1)->collectParams(getDecl(), 0); 
        child(3)->collectParams(enclosing, 0); 
    }
    void resolveSimpleIds(const Environ *env)
    {
        Unwind_Stack s;

        AST_Ptr type = child(2);
        //hbradlow: this figures out the supposed type of the function based off of its return statement
        if(child(3)->getType()!=NULL)
        {
            if(type->asType()==NULL)
            {
                type = child(3)->getType();
            }
            else{
                int b = type->asType()->unify(child(3)->getType(),s);
                if(b==0){
                    error(loc(),"Return types do not match");
                }
            }
        }
        else{
            if(type->asType()==NULL)
            {
                type = Type::makeVar();
            }
        }

        std::vector<AST_Ptr> types;
        for_each_child(c,child(1)){
            c->resolveSimpleIds(env);
            types.push_back(c->getType());
        } end_for;
        AST_Ptr type_list = make_tree(TYPE_LIST,types.begin(),types.end());

        std::vector<AST_Ptr> ft_vec;
        ft_vec.push_back(type);
        ft_vec.push_back(type_list);
        AST_Ptr function_type = make_tree(FUNCTION_TYPE,ft_vec.begin(),ft_vec.end());

        //This makes sure the return type is the same as the explicit type of the function def
        int b = child(0)->getType()->unify(function_type->asType(),s);
        if(b==0){
            // This needs to be commented out until we deal with overloading
              //error(loc(),"Identifier already defined as a different type");
        }
    }

    AST_Ptr doOuterSemantics()
    {
        /* Do the first collecting */
        Decl *decl = child(0)->getDecl(0);
        for_each_child(c, this)
        {
           c->collectDecls(decl);
        } end_for;
        /* Do the internal stuff */
        for_each_child(c, this)
        {
            c->doOuterSemantics();
        }end_for;
        /* Do the resolving */
        for_each_child(c, this)
        {
            if (c_i_ == 0) 
                continue;
            c->resolveSimpleIds(decl->getEnviron());
        } end_for;
        return this;
    }

private: 

    Decl_Vector _me;
    
protected:

    NODE_CONSTRUCTORS (Def_AST, AST_Tree);
};
NODE_FACTORY (Def_AST, DEF);

/* Method is just a subtype of Def */
class Method_AST: public Def_AST {
protected:
    NODE_CONSTRUCTORS (Method_AST, Def_AST);
};
NODE_FACTORY (Method_AST, METHOD);

class Class_AST: public AST_Tree {
public:
    bool assert_none_here(int k){
        error(loc(), "Cannot use None as a class name");
        return false;
    }

    // Resolve my type
    AST_Ptr 
    resolveTypes(Decl* context, int& resolved, int& ambiguities, 
    		 bool& errors) {
    	context->print();
        return NULL;
    }
 
    void collectDecls(Decl *enclosing)
    {
        Decl *decl = enclosing->getEnviron()->find_immediate(child(0)->as_string());
        if (decl != NULL)
            error(loc(), "Trying to assign class to pre-defined variable");
        decl = enclosing->addClassDecl(this);
        child(0)->addDecl(decl);

        decl->set_built_in(true);
        if(decl->getName().compare("int")==0){
            intDecl = decl;
        }
        else if(decl->getName().compare("str")==0){
            strDecl = decl;
        }
        else if(decl->getName().compare("bool")==0){
            boolDecl = decl;
        }
        else if(decl->getName().compare("list")==0){
            listDecl = decl;
        }
        else if(decl->getName().compare("tuple0")==0){
            tuple0Decl = decl;
        }
        else if(decl->getName().compare("tuple1")==0){
            tuple1Decl = decl;
        }
        else if(decl->getName().compare("tuple2")==0){
            tuple2Decl = decl;
        }
        else if(decl->getName().compare("tuple3")==0){
            tuple3Decl = decl;
        }
        else if(decl->getName().compare("dict")==0){
            dictDecl = decl;
        }
        else if(decl->getName().compare("file")==0){
            fileDecl = decl;
        }
        else if(decl->getName().compare("range")==0){
            rangeDecl = decl;
        }
        else{
            decl->set_built_in(false);
        }
    }
   
    AST_Ptr doOuterSemantics()
    {
        Decl *decl = child(0)->getDecl();
        for_each_child(c, this)
        {
           c->collectDecls(decl);
        } end_for;
        for_each_child(c, this)
        {
            c->doOuterSemantics();
        }end_for;
        
        return this;
    }

protected:
    NODE_CONSTRUCTORS (Class_AST, AST_Tree);
};
NODE_FACTORY (Class_AST, CLASS);

class ClassBlock_AST: public AST_Tree{
public:
    
    void append_init()
    {
        for_each_child (c,this) {
            if(c->is_init()){
                return;
            }
        } end_for;

        NodePtr i = make_token(ID,8,"__init__",true);
        NodePtr s = make_token(ID,4,"self",true);
        
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

    NODE_CONSTRUCTORS (ClassBlock_AST, AST_Tree);

    Decl* getDecl (int k = 0) {
        return child (0)->getDecl (k);
    }

    void addDecl (Decl* decl) {
        child (0)->addDecl (decl);
    }

};
NODE_FACTORY (ClassBlock_AST, CLASS_BLOCK);

//hbradlow
class Block_AST: public AST_Tree {
protected:
    NODE_CONSTRUCTORS (Block_AST, AST_Tree);
    Type_Ptr getType(){
        for_each_child(c,this){
            if(c->getType()!=NULL){
                return c->getType();
            }
            if(c->getReturnNode()!=NULL){
                return c->getReturnNode()->child(0)->getType();
            }
        } end_for;
        return NULL;
    }
};
NODE_FACTORY (Block_AST, BLOCK);

//hbradlow
class If_AST: public AST_Tree {
protected:
    NODE_CONSTRUCTORS (If_AST, AST_Tree);
    Type_Ptr getType(){
        for_each_child(c,this){
            if(c_i_ !=0 && c->getType()!=NULL){
                return c->getType();
            }
        } end_for;
        return NULL;
    }
};
NODE_FACTORY (If_AST, IF);

//hbradlow
class Tuple_AST: public AST_Tree {
protected:
    NODE_CONSTRUCTORS (Tuple_AST, AST_Tree);
    Type_Ptr getType(){
        return this->computeType();
    }
    Type_Ptr computeType () {
        int arity = this->arity();
        Type_Ptr t;
        if(arity==0)
            t = tuple0Decl->asType ();
        else if(arity==1)
            t = tuple1Decl->asType ();
        else if(arity==2)
            t = tuple2Decl->asType ();
        else if(arity==3)
            t = tuple3Decl->asType ();
        else
        {
            error(loc(),"Maximum tuple size is 3 - truncating tuple...");
            t = tuple3Decl->asType ();
        }
        for_each_child(c,t->child(1)){
            Unwind_Stack s;
            this->child(c_i_)->getType()->unify(c->asType(),s);
        } end_for;
        return t;
    }
};
NODE_FACTORY (Tuple_AST, TUPLE);

//hbradlow
class ListDisplay_AST: public AST_Tree {
public:
    static bool i_less_than_j (NodePtr i,NodePtr j) 
    {
        int index_i = i->getDecl()->getIndex();
        int index_j = j->getDecl()->getIndex();
        return (index_i<index_j); 
    }
protected:
    NODE_CONSTRUCTORS (ListDisplay_AST, AST_Tree);

    Type_Ptr getType(){
        vector<NodePtr> type_v;
        vector<NodePtr> typelist_v;
        set<int> typelist_set;

        Type_Ptr type = listDecl->asType()->freshen();
        Type_Ptr first_type = Type::makeVar();
        if(arity()>0)
            first_type = child(0)->getType();
        Unwind_Stack s;
        first_type->unify(type->child(1)->child(0)->asType(),s);
        for_each_child(c,this){
            if(!first_type->unifies(c->getType()))
                error(loc(),"Lists must be homogeneous");
        } end_for;

        return type;
        /*
        vector<NodePtr> type_v;
        vector<NodePtr> typelist_v;
        set<int> typelist_set;

        NodePtr i = listDecl->asType()->child(0);

        // hbradlow
        // only add each type to the list once
        // I use the set to make sure that duplicate types are not added
        for_each_child(c,this){
            Type_Ptr ty = c->getType();
            int index = ty->binding()->getDecl()->getIndex();
            if(typelist_set.count(index)==0)
            {
                typelist_set.insert(index);
                typelist_v.push_back(c->getType()->binding());
            }
        } end_for;

        sort(typelist_v.begin(),typelist_v.end(),ListDisplay_AST::i_less_than_j);
        if(typelist_v.size()==0)
            typelist_v.push_back(Type::makeVar());
        NodePtr type_list = make_tree(TYPE_LIST,typelist_v.begin(),typelist_v.end());
        
        type_v.push_back(i);
        type_v.push_back(type_list);
        Type_Ptr type = make_tree(TYPE,type_v.begin(),type_v.end())->asType();
        
        return type;
        */
    }
};
NODE_FACTORY (ListDisplay_AST, LIST_DISPLAY);

//hbradlow

class DictDisplay_AST: public AST_Tree {
protected:
    NODE_CONSTRUCTORS (DictDisplay_AST, AST_Tree);

    Type_Ptr getType(){
        vector<NodePtr> type_v;
        vector<NodePtr> typelist_v;
        set<int> typelist_set;

        Type_Ptr type = dictDecl->asType()->freshen();
        Unwind_Stack s;
        child(0)->child(0)->getType()->unify(type->child(1)->child(0)->asType(),s);
        child(0)->child(1)->getType()->unify(type->child(1)->child(1)->asType(),s);

        return type;
    }
};
NODE_FACTORY (DictDisplay_AST, DICT_DISPLAY);
