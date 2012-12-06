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
    void outerCodeGen (ostream& out, int i) {
        out << "#include \"runtime.h\"\n";
        out << "#include <fstream>\n";
        out << "#include <iostream>\n";

        for_each_child(c,this){
            c->classDefCodeGen(out,i);
        } end_for;
        for_each_child(c,this){
            c->forwardDefCodeGen(out,i);
        } end_for;
        for_each_child(c,this){
            c->classCodeGen(out,i);
        } end_for;
        for_each_child(c,this){
            c->defCodeGen(out,i);
        } end_for;

        out << "int main(int argc, char* argv[]) {\n";
        for_each_child(c, this)
        {
            c->generateInitialDef(out, i);
        }end_for;
        writeIndented(out,i+1);
        out << "Frame* frame_upper = new Frame(NULL);\n";
        writeIndented(out,i+1);
        out << "Frame* frame = new Frame(frame_upper);\n";

        writeIndented(out,i+1);
        out << "frame->setVar(\"argc\", new Integer(argc));\n";

        writeIndented(out,i+1);
        out << "vector<Object*> argv_vector;\n";
        writeIndented(out,i+1);
        out << "for(int i = 0; i< argc; i++){\n";
        writeIndented(out,i+2);
        out << "stringstream argv_ss;\n";
        writeIndented(out,i+2);
        out << "argv_ss << argv[i];\n";
        writeIndented(out,i+2);
        out << "argv_vector.push_back(new String(argv_ss.str()));\n";
        writeIndented(out,i+1);
        out << "}\n";

        writeIndented(out,i+1);
        out << "frame->setVar(\"argv\", new List(argv_vector));\n";

        writeIndented(out,i+1);
        out << "Frame* dyn_frame = new Frame(NULL);\n";
        for_each_child(c,this){
            c->closureCodeGen(out,i+1);
        } end_for;

        for_each_child(c,this){
            c->outerCodeGen(out,i+1);
        } end_for;

        out << "}\n";
    }

    NODE_CONSTRUCTORS (Module_AST, AST_Tree);

};

NODE_FACTORY (Module_AST, MODULE);

