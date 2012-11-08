/* -*- mode: C++; c-file-style: "stroustrup"; indent-tabs-mode: nil; -*- */

/* ast.cc: Basic AST subclasses. */

/* Authors:  YOUR NAMES HERE */

#include <iostream>
#include "apyc.h"
#include "ast.h"
#include "apyc-parser.hh"

using namespace std;

/* Definitions of methods in base class AST. */

int AST::current_mark = 0;

AST::AST ()
    : _mark (0)
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

Type_Ptr
AST::asType ()
{
    return NULL;
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
    return NULL;
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


/** Default does nothing. */
AST_Ptr
AST::doOuterSemantics ()
{
    for_each_child(c, this)
    {
        c->doOuterSemantics();
    } end_for;
    return this;
}

void
AST::collectDecls (Decl* enclosing)
{
    for_each_child (c, this) {
        c->collectDecls (enclosing);
    } end_for;
}

/** Kevin */
void 
AST::collectParams (Decl* enclosing, int k)
{
    for_each_child (c, this)
    {
        c->collectParams (enclosing, k); 
    } end_for;
}

void
AST::addTargetDecls (Decl* enclosing)
{
    for_each_child (c, this) {
        c->addTargetDecls (enclosing);
    } end_for;
}

void
AST::resolveSimpleIds (const Environ* env)
{
    for_each_child (c, this) {
        c->resolveSimpleIds (env);
    } end_for;
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
AST::resolveTypes (Decl* context, int& resolved, int& ambiguities,  bool& errors)
{
    printf("HERE\n");
    for_each_child_var (c, this) {
        c = c->resolveTypes (context, resolved, ambiguities, errors);
    } end_for;
    return this;
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

///////////////////////////////////////////////////////////////////////////////////
//OUR CODE FROM HERE
///////////////////////////////////////////////////////////////////////////////////

//hbradlow
void AST::unifyWith(AST_Ptr right){
    /* do nothing */
}

//rewrites
void
AST::rewrite_types(Decl* enclosing){
    for_each_child (c, this) {
        c->rewrite_types(enclosing);
    } end_for;
}
AST_Ptr
AST::rewrite_allocators(Decl* enclosing){
    for_each_child_var (c, this) {
        c = c->rewrite_allocators(enclosing);
    } end_for;
    return this;
}
void
AST::append_init(){
    for_each_child (c, this) {
        c->append_init();
    } end_for;
}

void
AST::resolve_reference (const Environ* env)
{
    // Do nothing
}

void
AST::create_attr_ref(Decl* enclosing)
{
    // Default should do nothing
    return;
}

void AST::replace_none(){
    int index = 0;
    for_each_child (c, this) {
        if(c->is_none()){
            this->assert_none_here(index); // check to make sure its legal to have a None here

            NodePtr i = AST::make_token(ID,8,"__None__",true);
            i->set_loc(this->loc());

            vector<NodePtr> expr_v;
            NodePtr expr = make_tree(EXPR_LIST,expr_v.begin(),expr_v.end());
            expr->set_loc(this->loc());

            vector<NodePtr> call_v;
            call_v.push_back(i);
            call_v.push_back(expr);
            NodePtr call = make_tree(CALL,call_v.begin(),call_v.end());

            this->replace(index,call);
        }
        index++;
        c->replace_none();
    } end_for;
}

AST_Ptr AST::replace_attribute_refs()
{
    for_each_child(c, this)
    {
        this->replace(c_i_, c->replace_attribute_refs());
    } end_for; 
    return this;
}
//checkers
//hbradlow
bool
AST::is_init(){
    return false;
}

//hbradlow
bool
AST::is_none(){
    return false;
}

//hbradlow
void
AST::assert_none_here(int k){
    /* do nothing */
}

//hbradlow
void
AST::check_defined(){
    for_each_child_var(c, this)
    {
        c->check_defined(); 
    } end_for;
}

//hbradlow
void
AST::assert_is_defined(){
    /* do nothing */
}
//hbradlow
void 
AST::attachDecl(Decl *enclosing){
}
//hbradlow
AST_Ptr
AST::getReturnNode(){
    return NULL;
}
