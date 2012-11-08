/* -*- mode: C++; c-file-style: "stroustrup"; indent-tabs-mode: nil; -*- */

/* modules.cc: Describes programs or libraries.  Contains top-level routines. */

/* Authors:  YOUR NAMES HERE */

#include <iostream>
#include "apyc.h"
#include "ast.h"
#include "apyc-parser.hh"

using namespace std;

const Environ* outer_environ;

/*****   MODULE    *****/

/** A module, representing a complete source file. */
class Module_AST : public AST_Tree {
protected:

    int lineNumber () {
	return 0;
    }

    /** Top-level semantic processing for the program. */
    AST_Ptr doOuterSemantics () {
        //rewrites
        this->replace_none(); // 4.6
        this->append_init(); // 4.2

        /* Create the module declaration */ 
        Decl *mod_decl = makeModuleDecl("__main__"); 
        outer_environ = mod_decl->getEnviron();

        for_each_child_var(c, this)
        {
            c->collectDecls(mod_decl);   
            /* Do the nested stuff */ 
            c = c->doOuterSemantics(); 
        } end_for;

        for_each_child_var(c, this)
        {
            c->rewrite_types(mod_decl);
            c->rewrite_allocators(mod_decl);
        } end_for;

        /* Do the resolving */
        for_each_child_var(c, this)
        {
            c->resolveSimpleIds(mod_decl->getEnviron()); 
        } end_for;

        for_each_child_var(c, this) 
        {
            this->replace(c_i_, c->replace_attribute_refs());
        } end_for;

        return this;
    }
    
    NODE_CONSTRUCTORS (Module_AST, AST_Tree);

};

NODE_FACTORY (Module_AST, MODULE);

