/* -*- mode: C++; c-file-style: "stroustrup"; indent-tabs-mode: nil; -*- */

/* modules.cc: Describes programs or libraries.  Contains top-level routines. */

/* Authors:  YOUR NAMES HERE */

#include <iostream>
#include "apyc.h"
#include "ast.h"
#include "apyc-parser.hh"

using namespace std;

const Environ* outerEnviron;
Decl* mainModule;

/*****   MODULE    *****/

/** A module, representing a complete source file. */
class Module_AST : public AST_Tree {
protected:

    int lineNumber () {
	return 0;
    }

    /** Top-level semantic processing for the program. */
    AST_Ptr doOuterSemantics () {
        mainModule = makeModuleDecl("__main__");
        outerEnviron = mainModule->getEnviron();
        for_each_child_var (c, this) {
            c = c->doOuterSemantics ();
        } end_for;
        return this;
    }

    /** Top-level code generation routine.  */
    // This is a placeholder!  Replace it.
    void outerCodeGen (ostream& out) {
        out << "#include \"runtime.h\"\n";

        for_each_child(c,this){
            c->classCodeGen(out);
        } end_for;
        for_each_child(c,this){
            c->defCodeGen(out);
        } end_for;

        out << "int main(int argc, char* argv[]) {\n";

        for_each_child(c,this){
            c->outerCodeGen(out);
        } end_for;

        out << "}\n";
    }

    NODE_CONSTRUCTORS (Module_AST, AST_Tree);

};

NODE_FACTORY (Module_AST, MODULE);

