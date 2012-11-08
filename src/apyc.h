/* -*- mode: C++; c-file-style: "stroustrup"; indent-tabs-mode: nil; -*- */

/* Interfaces for apyc. */

#ifndef _APYC_H_
#define _APYC_H_

#include <cstdio>
#include <string>
#include <stdexcept>
#include "ast.h"

class Decl;
class Environ;

class semantic_error : public std::runtime_error {
public:
    explicit semantic_error (const std::string& s) : std::runtime_error (s)
        { }
};

#define UNIMPLEMENTED(name) \
    throw logic_error ("unimplemented method: " #name)

/** Print an error message in standard Unix format:
 *      <filename>:<linenum>: <message>
 *  where <filename> and <linenum> denote the file and line number
 *  containing source location LOC, and <message> is composed from
 *  FORMAT and the trailing arguments as
 *  for the printf family. */
extern void error (const char* loc, const char* format, ...);
/** Print an error message (without file or line number indications)
 *  composed from FORMAT and the trailing arguments as for the printf
 *  family. */
extern void error_no_file (const char* format, ...);

/* Defined by Horn framework. */
extern std::string yyprinted_location (const char* loc);

extern void add_source_file (const std::string& name);

extern void parse_init ();
extern AST_Ptr parse ();

/** True iff parser should produce debugging output. */
extern bool debugParser;

/** The --phase argument. */
extern int maxPhase;

/* Decls */

/** A declaration node, containing semantic information about a 
 *  program entity.  Subtypes of Decl refer to local variables,
 *  parameters, global variables, defined functions, methods, constants,
 *  modules, and classes. */
class Decl {
public:

    Decl (const std::string& name, Decl* container, Environ* members = NULL);
        
    /** My index value (if I appear explicitly), and otherwise -1 to
     *  indicate that I am unindexed. */
    int getIndex () const { return _index; }

    const std::string& getName () const { return _name; }

    /** Print THIS on the standard output. */
    virtual void print () const;

    /** Get my container (null if none). */
    virtual Decl* getContainer () const { return _container; }

    /** Get the type of the entity I represent. */
    virtual Type_Ptr getType () const;

    /** Set my type to TYPE. */
    virtual void setType (Type_Ptr type);

    /** My associated AST, if any.  A Decl may be associated with a
     *  particular AST that corresponds to the declaration of the
     *  entity it declares.  */
    virtual AST_Ptr getAst () const;

    /** Set getAst() to AST. */
    virtual void setAst (AST_Ptr ast);

    /** True iff I represent a method. */
    virtual bool isMethod () const;

    /** Kevin : True iff I represent a function or method */
    virtual bool isFunc() const;

    /** Kevin : True iff I represent a class */
    virtual bool isClass() const;

    /** Kevin : True iff I can be redefined */
    virtual bool redefine() const;

    /** True iff I represent a type. */
    virtual bool isType () const;

    /** True iff I represent an internally generated type variable
     *  (which should not be included in the output list). */
    virtual bool isInternal () const;

    /** A Type representing me with ARITY (0 <= ARITY <=2) type parameters
     *  taken from T0 and T1.  Requires isType(). */
    virtual Type_Ptr asType (int arity = 0,
                             Type_Ptr t0 = NULL, Type_Ptr t1 = NULL) const;

    /** A Type representing me with parameters PARAMS[0 .. ARITY-1]. */
    virtual Type_Ptr asType (int arity, Type_Ptr* params) const;

    /** If I am type, returns the number of type arguments. */
    virtual int getTypeArity () const;

    /** Get my position (in a parameter list, indexed from 0). */
    virtual int getPosition () const;

    /** A view of all member Decls I contain (modules, classes). */
    virtual const Environ* getEnviron () const;

    /** Add DECL to the end of my list of member Decls. */
    virtual void addMember (Decl* new_member);

    /** Create a declaration of ID appropriate for a variable declaration to
     *  my members.  There must not already be one. Returns the
     *  resulting declaration */
    virtual Decl* addVarDecl (AST_Ptr id);

    /** Create a declaration of ID appropriate for a 'def' to my
     *  members.  There must not already be one.  Returns the
     *  resulting declaration. */
    virtual Decl* addDefDecl (AST_Ptr id);

    /** Will 
     * Identical to addDefDecl except it doesn't actually add the
     * decl to the enclosing env, just returns it. */
    virtual Decl* peekDefDecl (AST_Ptr id);

    /** Kevin: Create a parameter of ID for function definition */
    virtual Decl* addParamDecl (AST_Ptr id, int k);

    /** Kevin: Create a class declaration with ID */
    virtual Decl* addClassDecl (AST_Ptr id); 

    /** True iff the entity I represent can be assigned to or defined
     *  by assignment. */
    virtual bool assignable () const;

    /** True iff my type is currently "frozen", meaning that getType is
     *  not to freshen type variables in it.  Everything in a class is
     *  frozen until processing of the class definition is finished.
     *  Likewise for outer-level functions. */
    virtual bool isFrozen () const;

    /** If my freezing status is mutable, set it to FROZEN.
     *  Otherwise, does nothing. */
    virtual void setFrozen (bool frozen);

    virtual ~Decl ();

    /** Print my list of type parameters on the standard output,
     *  if applicable, and otherwise do nothing. */
    virtual void printTypeParams () const;

    /** Print my type on the standard output, if applicable, and
     *  otherwise do nothing. */
    virtual void printType () const;

    /** The name of this type of Decl for external printing purposes. */
    virtual const char* declTypeName () const;


protected:

    /** Print my container's index on the standard output, if
     *  applicable, and otherwise do nothing. */
    virtual void printContainer () const;

    /** Print my position in my container, if applicable, on the
     *  standard output, and otherwise do nothing. */
    virtual void printPosition () const;

    /** Print my index list of members or local definitions on the
     *  standard output, if applicable, and otherwise do nothing. */
    virtual void printMembersList () const;

protected:
    bool _frozen;

private:
    int _index;
    const std::string _name;
    Decl* _container;
    Environ* _members;
    AST_Ptr _ast;
};

/** Declaration of local or module-level variable NAME, defined
 *  immediately inside function or module CONTAINER and having type
 *  TYPE. */
extern Decl* makeVarDecl (const std::string& name,
                          Decl* container, AST_Ptr type);
/** Declaration of parameter #K (numbered from 0) named NAME in function FUNC
 *  and of type TYPE. */
extern Decl* makeParamDecl (const std::string& name,
                            Decl* func, int k, AST_Ptr type);
/** Declaration of an instance variable named NAME of type TYPE 
 *  in class CLAZZ. */
extern Decl* makeInstanceDecl (const std::string& name, Decl* clazz,
                               AST_Ptr type);
/** Declaration of type variable NAME, associated with type variable
 *  CANONICAL. */
extern Decl* makeTypeVarDecl (const std::string& name, AST_Ptr canonical);
/** Declaration of function NAME of type TYPE, nested inside the
 *  function or module CONTAINER. */
extern Decl* makeFuncDecl (const std::string& name,
                           Decl* container, AST_Ptr type);
/** Declaration for a class NAME with ARITY type parameters. */
extern Decl* makeClassDecl (const std::string& name, AST_Ptr params);
/** Declaraton for the module MAIN.  This always has sequence number 0. */
extern Decl* makeModuleDecl (const std::string& name);

/** True iff NAME may not be defined or set by assignment once it has
 *  been defined once. */
extern bool undefinable (const std::string& name);

/** Output all Decl nodes to standard output. */
extern void outputDecls ();

/** Decls for built-in types. */
extern Decl* intDecl;
extern Decl* listDecl;
extern Decl* tuple0Decl;
extern Decl* tuple1Decl;
extern Decl* tuple2Decl;
extern Decl* tuple3Decl;
extern Decl* strDecl;
extern Decl* dictDecl;
extern Decl* boolDecl;
extern Decl* fileDecl;
extern Decl* rangeDecl;

typedef std::vector<Decl*> Decl_Vector;

class Environ {
public:

    /** An initialiy empty environment enclosed in ENCLOSING. */
    Environ (const Environ* enclosing);

    /** An environment initialized to the (immediate) contents of 
     *  ENVIRON0, enclosed in enclosing. */
    Environ (const Environ* environ0, const Environ* enclosing);

    /** An entry for NAME, or NULL if none.  Does not search enclosing
     *  Environs. */
    Decl* find_immediate (const std::string& name) const;

    /** Set DEFNS to a list of all my entries for NAME  Does not search
     *  enclosing Environs. */
    void find_immediate (const std::string& name, Decl_Vector& defns) const;

    /** An entry for NAME in me or enclosing Environs, or NULL if
     *  none. */
    Decl* find (const std::string& name) const;

    /** Set DEFNS to all definitions of NAME in the innermost Environ
     *  in me or my enclosing Environs that has any.  DEFNS is set
     *  empty if it is nowhere defined. */
    void find(const std::string& name, Decl_Vector& defns) const;

    /** Define DECL in me by its name.  */
    void define (Decl* decl);

    /** The environment enclosing me (passed to my constructor), if
     *  any. */
    const Environ* get_enclosure () const;

    /** A view of my members (not including enclosing Environs). */
    const Decl_Vector& get_members () const;

private:

    Decl_Vector members;
    const Environ* enclosure;
};

/** The current outer (__main__) environment */
extern const Environ* outer_environ;

#endif

