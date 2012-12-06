/* -*- mode: C++; c-file-style: "stroustrup"; indent-tabs-mode: nil; -*- */

/* ast.cc: Basic AST subclasses. */

/* Authors:  YOUR NAMES HERE */

#include <iostream>
#include "apyc.h"
#include "ast.h"
#include "apyc-parser.hh"

using namespace std;

//hbradlow
std::string strReplace(std::string &s,
                        std::string toReplace,
                        std::string replaceWith)
{
        return(s.replace(s.find(toReplace), toReplace.length(), replaceWith));
}
/* Write the line to out, preceded by i tabs.
 */
void 
writeClosure(ostream& out, int i, AST_Ptr c){
    out << "((";
    out << "Closure";
    /*
    c->innerCodeGen(out,i);
    out << "__" << c->getDecl()->getIndex() << "_CLOSURE";
    */
    out << "*)(frame->getVar(\"";
    c->innerCodeGen(out,i);
    out << "__" << c->getDecl()->getIndex();
    out << "_closure\")))";
}
/* Write the line to out, preceded by i tabs.
 */
void 
writeComment(ostream& out, int i, std::string c) {
  while (i > 0) {
    out << "    ";
    i--;
  }
  out << "//" << c << "\n";
}
/* Write the line to out, preceded by i tabs.
 */
void 
writeIndented(ostream& out, int i) {
  while (i > 0) {
    out << "    ";
    i--;
  }
}

/* Definitions of methods in base class AST. */

int AST::current_mark = 0;

AST::AST ()
    : _mark (0), _erroneous (false)
{
}

bool
AST::mark ()
{
    if (_mark == current_mark)
        return false;
    _mark = current_mark;
    return true;
}

void
AST::unmark ()
{
    _mark = 0;
}

void
AST::print (ostream& out, int indent)
{
    current_mark += 1;
    print(this, out, indent);
}

void
AST::print (AST_Ptr tree, std::ostream& out, int indent)
{
    if (tree->mark ())
        tree->_print (out, indent);
    else
        out << "...";
    tree->unmark ();
}

//hbradlow
bool 
AST::isLeftCompare(){
    return false;
}
//hbradlow
bool 
AST::isFunction(){
    return false;
}

bool
AST::isCall() 
{
    return false;
}

Type_Ptr
AST::asType ()
{
    return NULL;
}

bool
AST::isType ()
{
    return false;
}

AST_Ptr
AST::getId ()
{
    UNIMPLEMENTED (getId);
}

int
AST::numDecls ()
{
    return 0;
}

Decl*
AST::getDecl (int k)
{
    throw logic_error ("node does not represent a named entity");
}

void
AST::addDecl (Decl*)
{
    throw logic_error ("node does not represent a named entity");
}

void
AST::removeDecl (int k)
{ 
    throw logic_error ("node does not represent a named entity");
}

Type_Ptr
AST::getType ()
{
    throw logic_error ("node does not represent something with a type");
}

bool
AST::setType (Type_Ptr type)
{
    throw logic_error ("node does not represent something with a type");
}

bool
AST::isMissing ()
{
    return false;
}

bool
AST::isBoundMethod ()
{
    return false;
}

extern void DBcheck(const char*, const AST_Ptr&);

/** Default collects declarations and resolves in the current
 *  module. */
AST_Ptr
AST::doOuterSemantics ()
{
    AST_Ptr tree;
    tree = this;
    tree = tree->convertNone (false);
    tree->collectDecls (mainModule);
    tree->resolveSimpleTypeIds (outerEnviron);
    tree = tree->resolveSimpleIds (outerEnviron);
    tree = tree->resolveAllocators (outerEnviron);
    tree = tree->resolveStaticSelections (outerEnviron);
    tree = tree->resolveTypesOuter (mainModule);
    tree->checkResolved ();
    tree->checkNoBoundMethodValues ();
    return tree;
}

void
AST::collectDecls (Decl* enclosing)
{
    for_each_child (c, this) {
        c->collectDecls (enclosing);
    } end_for;
}

void
AST::collectTypeVarDecls (Decl*)
{
}

void
AST::addTargetDecls (Decl* enclosing)
{
    UNIMPLEMENTED (addTargetDecls);
}

AST_Ptr
AST::resolveSimpleIds (const Environ* env)
{
    for_each_child_var (c, this) {
        c = c->resolveSimpleIds (env);
    } end_for;
    return this;
}

void
AST::resolveSimpleTypeIds (const Environ* env)
{
    for_each_child (c, this) {
        c->resolveSimpleTypeIds (env);
    } end_for;
}
    
AST_Ptr
AST::resolveAllocators (const Environ* env)
{
    for_each_child_var (c, this) {
        c = c->resolveAllocators (env);
    } end_for;
    return this;
}

AST_Ptr
AST::resolveStaticSelections (const Environ* env)
{
    for_each_child_var (c, this) {
        c = c->resolveStaticSelections (env);
    } end_for;
    return this;
}

void
AST::freezeDecls (bool frozen)
{
    for_each_child (c, this) {
        c->freezeDecls (frozen);
    } end_for;
}

AST_Ptr
AST::convertMethodCall (AST_Ptr args)
{
    return NULL;
}

AST_Ptr
AST::resolveTypes (Decl* context, int& resolved, int& ambiguities)
{
    for_each_child_var (c, this) {
        c = c->resolveTypes (context, resolved, ambiguities);
    } end_for;
    return this;
}

void
AST::resolveSelectedType (Type_Ptr, int&, int&)
{
    UNIMPLEMENTED (resolveSelectedType);
}

void
AST::checkNoBoundMethodValues ()
{
    for_each_child (c, this) {
        c->checkNoBoundMethodValues ();
    } end_for;
}

void
AST::checkResolved ()
{
    for_each_child (c, this) {
        c->checkResolved ();
    } end_for;
}

AST_Ptr
AST::convertNone (bool)
{
    for_each_child_var (c, this) {
        c = c->convertNone (false);
    } end_for;
    return this;
}

//hbradlow
void 
AST::assignCodeGen (std::ostream& out,int i,string c, std::string lhs){
    writeIndented(out,i);
    if(strcmp("",lhs.c_str())==0)
        this->lhsFrameCodeGen(out,i);
    else
        out << lhs;
    out << "->frame->setVar(";
    this->stringCodeGen(out, i);
    out << ",";
    out << "(";
    out << c;
    out << "))";
    out << ";\n";
}
//hbradlow
void 
AST::assignCodeGen (std::ostream& out,int i,AST_Ptr c, std::string lhs){
    c->memCodeGen(out,i);
    writeIndented(out,i);
    if(strcmp("",lhs.c_str())==0)
        this->lhsFrameCodeGen(out,i);
    else
        out << lhs;
    out << "->frame->setVar(";
    this->stringCodeGen(out, i);
    out << ",";
    out << "(";
    c->valueCodeGen(out,i);
    out << "))";
    out << ";\n";

    if(c->getType()->binding()->isFunction()){
        writeIndented(out,i);
        out << "frame->setVar(\"";
        this->innerCodeGen(out,i);
        out << "__" << this->getDecl()->getIndex() << "_closure";
        out << "\", ";
        out << "frame->getVar(\"";
        c->innerCodeGen(out, i);
        out << "__" << c->getDecl()->getIndex() << "_closure";
        out << "\"));\n";
    }
}
//hbradlow
void 
AST::setFunctionCalledBefore(bool b){
}
//hbradlow
bool 
AST::functionCalledBefore(){
    return false;
}
//hbradlow
void 
AST::stringCodeGen (std::ostream& out, int i)
{
    out << "\"";
    innerCodeGen(out,i);
    out << "\"";
}
//outerCodeGen called on statements that are on their own lines
void
AST::outerCodeGen (ostream& out,int i)
{
}
//hbradlow
//innerCodeGen called on statements that are within outer statements
//Example:
//a = x+2
//The assignment is the outer statement, (id a), (binop) etc are inner statements
void
AST::innerCodeGen (ostream& out,int i)
{
}
//hbradlow
void 
AST::valueCodeGen (std::ostream& out,int i)
{
    innerCodeGen(out,i);
}
//hbradlow
void 
AST::lhsFrameCodeGen (std::ostream& out, int i)
{
    out << "frame";
}
//hbradlow
void
AST::closureCodeGen (ostream& out,int i,std::string closure)
{
    for_each_child(c,this){
        c->closureCodeGen(out,i,closure);
    } end_for;
}
//hbradlow
void
AST::memCodeGen (ostream& out,int i)
{
    for_each_child(c, this){
        c->memCodeGen(out,i);
    } end_for;
}
//hbradlow
void 
AST::forwardDefCodeGen(std::ostream& out,int i){
    for_each_child(c,this){
        c->forwardDefCodeGen(out,i);
    } end_for;
}
//hbradlow
void
AST::defCodeGen (ostream& out, int i)
{
    for_each_child(c, this){
        c->defCodeGen(out,i);
    } end_for;
}
//hbradlow
void
AST::classDefCodeGen(ostream& out,int i){
}
//hbradlow
void
AST::classCodeGen (std::ostream& out,int i)
{
}
//hbradlow
void 
AST::outerClassCodeGen (std::ostream& out,int i,AST_Ptr c)
{
}
//hbradlow
void 
AST::innerClassCodeGen (std::ostream& out,int i,AST_Ptr c)
{
}

void 
AST::generateFunctionCall(std::ostream& out, int i){}
void 
AST::generateArgs(std::ostream& out, int i, int c_i_, AST_Ptr c){}

//hbradlow
bool 
AST::needsPointer(){
    return false;
}
//hbradlow
bool 
AST::needsCastPointer(){
    return true;
}
//kevin
void 
AST::addToStaticFrame(std::ostream& out, int i)
{
    writeIndented(out,i);
    out << "frame->setVar(\"";
    child(0)->innerCodeGen(out,i);
    out << "__" << child(0)->getDecl()->getIndex() << "_closure";
    out << "\", ";
    out << "";
    child(0)->innerCodeGen(out, i);
    out << "__" << child(0)->getDecl()->getIndex() << "_closure";
    out << ");\n";
}

bool
AST::errorReported ()
{
    return _erroneous;
}

void
AST::recordError ()
{
    _erroneous = true;
}

/* Definitions of methods in base class AST_Tree. */

void
AST_Tree::_print (ostream& out, int indent)
{
    out << "(" << externalName () << " " << lineNumber ();
    for_each_child (c, this) {
        out << endl << setw (indent + 4) << "";
        print (c, out, indent + 4);
    } end_for;
    out << ")";
}

const char*
AST_Tree::externalName ()
{
    static string result;

    int syntax = oper ()->syntax ();
    const char* name;
    name = yyexternal_token_name (syntax);
    if (name == NULL)
        return "?";
    if (name[0] != '"')
        return name;
    name += 1;
    while (*name == '@')
        name += 1;
    
    if (name[0] == '\0')
        return "?";

    result = string (name, strlen (name)-1);
    return result.c_str();
}

AST_Ptr
make_id (const char* text, const char* loc) 
{
    AST_Ptr result = AST::make_token (ID, strlen (text), text, false);
    result->set_loc (loc);
    return result;
}

AST_Ptr
consTree (int syntax)
{
    AST_Ptr args[1];
    return AST::make_tree (syntax, args, args);
}

AST_Ptr
consTree (int syntax, const AST_Ptr& c0)
{
    AST_Ptr args[] = { c0 };
    return AST::make_tree (syntax,
                           args, args + sizeof (args) / sizeof(args[0]));
}

AST_Ptr
consTree (int syntax, const AST_Ptr& c0, const AST_Ptr& c1)
{
    AST_Ptr args[] = { c0, c1 };
    return AST::make_tree (syntax,
                           args, args + sizeof (args) / sizeof(args[0]));
}

AST_Ptr
consTree (int syntax, const AST_Ptr& c0, const AST_Ptr& c1,
          const AST_Ptr& c2)
{
    AST_Ptr args[] = { c0, c1, c2 };
    return AST::make_tree (syntax,
                           args, args + sizeof (args) / sizeof(args[0]));
}

AST_Ptr
consTree (int syntax, const AST_Ptr& c0, const AST_Ptr& c1,
          const AST_Ptr& c2, const AST_Ptr& c3)
{
    AST_Ptr args[] = { c0, c1, c2, c3 };
    return AST::make_tree (syntax,
                           args, args + sizeof (args) / sizeof(args[0]));
}

/* The Horn framework has a provision (the NODE_FACTORY macro) that
 * allows AST subclasses to "register" themselves with the parser and
 * associate themselves with a particular syntactic category so that
 * the parser will create instances of the appropriate subclass when
 * asked to produce an AST node with a particular operator.  The
 * NODE_..._CONSTRUCTOR... macros set up the necessary constructors
 * and factory declarations in any given class.  To associate a
 * class with a given operator token, pass the (int) value of that
 * token's syntactic category to the NODE_FACTORY macro (for
 * one-character tokens, the character itself is usually the syntactic
 * category; for other tokens, use the name declared in the Horn
 * source file (those definitions appear in apyc-parser.hh, included above).
 */

/** A node representing a missing element in the AST (e.g., a missing 
 *  >>FILE argument in a print node.) */
class Empty_AST : public AST_Tree {

protected:

    /** Override AST_Tree::_print */
    void _print (ostream& out, int indent) {
        out << "()";
    }

    bool isMissing () {
        return true;
    }

    NODE_CONSTRUCTORS (Empty_AST, AST_Tree);

};

NODE_FACTORY (Empty_AST, EMPTY);
