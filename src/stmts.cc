/* -*- mode: C++; c-file-style: "stroustrup"; indent-tabs-mode: nil; -*- */

/* stmts.cc: AST subclasses related to statements and modules. */

/* Authors:  YOUR NAMES HERE */

#include <iostream>
#include "apyc.h"
#include "ast.h"
#include "apyc-parser.hh"

using namespace std;

/*****   MODULE    *****/

/** A module, representing a complete source file. */
class Module_AST : public AST_Tree {
public:

    int lineNumber () {
        return 0;
    }

    NODE_CONSTRUCTORS (Module_AST, AST_Tree);

};

NODE_FACTORY (Module_AST, MODULE);


/*****   PRINTLN   *****/

/** A print statement without trailing comma. */
class Println_AST : public AST_Tree {
public:

    NODE_CONSTRUCTORS (Println_AST, AST_Tree);

};

NODE_FACTORY (Println_AST, PRINTLN);

class Tuple_AST : public AST_Tree {
private:
    bool isTarget;
    void convert_to_target()
    {
        isTarget = 1;
        for_each_child (c, this) {
            c->convert_child_to_target();
        } end_for;

    }
   Tuple_AST* post_make(){
       isTarget = 0;
       return this;
   }
    void print (ostream& out, int indent) {
        string nm = "tuple";
        if (isTarget)
           nm = string("target_list");
  
        out << "(" << nm << " " << lineNumber ();
        for_each_child (c, this) {
            out << endl << setw (indent + 4) << "";
            c->print (out, indent + 4);
        } end_for;
        out << ")";
    }

    NODE_CONSTRUCTORS(Tuple_AST, AST_Tree);
};
NODE_FACTORY(Tuple_AST, TUPLE);

class For_AST : public AST_Tree {
private:
  For_AST* post_make(){
        for_each_child (c, this) {
            if (c_i_ == 0)
                c->convert_to_target();
        } end_for;
        return this; 
   } 
    NODE_CONSTRUCTORS(For_AST, AST_Tree);
};
NODE_FACTORY(For_AST, FOR);

class Target_List_AST : public AST_Tree {
private:
    bool isTarget;
  Target_List_AST* post_make(){
        for_each_child (c, this) {
            c->convert_child_to_target();
        } end_for;
        return this; 
   } 
   void convert_to_target()
   {
         isTarget = 1;
        for_each_child (c, this) {
            c->convert_child_to_target();
        } end_for;
   }
    NODE_CONSTRUCTORS(Target_List_AST, AST_Tree);
};
NODE_FACTORY(Target_List_AST, TARGET_LIST);



class List_AST : public AST_Tree {
private:
    bool isTarget;
    void convert_to_target()
    {
        isTarget = 1;
        for_each_child (c, this) {
            c->convert_child_to_target();
        } end_for;

    }
   List_AST* post_make(){
       isTarget = 0;
       return this;
   }
    void print (ostream& out, int indent) {
        string nm = "list_display";
        if (isTarget)
           nm = string("target_list");
  
        out << "(" << nm << " " << lineNumber ();
        for_each_child (c, this) {
            out << endl << setw (indent + 4) << "";
            c->print (out, indent + 4);
        } end_for;
        out << ")";
    }

    NODE_CONSTRUCTORS(List_AST, AST_Tree);
};
NODE_FACTORY(List_AST, LIST);

class Assignment_AST : public AST_Tree {
private:
   Assignment_AST* post_make(){
        for_each_child (c, this) {
            if (c_i_ == 0)
                c->convert_to_target();
        } end_for;
        return this; 
   } 
    NODE_CONSTRUCTORS(Assignment_AST, AST_Tree);
};
NODE_FACTORY(Assignment_AST,ASSIGN);

class Typed_Id_AST : public AST_Tree {
private:
    
    void convert_to_target(){return;} 
    void convert_child_to_target(){return;} 
    NODE_CONSTRUCTORS(Typed_Id_AST, AST_Tree);
};
NODE_FACTORY(Typed_Id_AST,TYPED_ID);

class Slice_AST : public AST_Tree {
private:
    void convert_to_target(){return;} 
    void convert_child_to_target(){return;} 
    NODE_CONSTRUCTORS(Slice_AST, AST_Tree);
};

NODE_FACTORY(Slice_AST, SLICING);

class Sub_AST : public AST_Tree {
private:
    void convert_to_target(){return;} 
    void convert_child_to_target(){return;} 
    NODE_CONSTRUCTORS(Sub_AST, AST_Tree);
};

NODE_FACTORY(Sub_AST,SUBSCRIPT);

class Atr_Ref_AST : public AST_Tree {
private:
    void convert_to_target(){return;} 
    void convert_child_to_target(){return;} 
    NODE_CONSTRUCTORS(Atr_Ref_AST, AST_Tree);
};
NODE_FACTORY(Atr_Ref_AST,ATTRIBUTEREF);

