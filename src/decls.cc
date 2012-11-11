/* Implementations of declaration and type-related classes */

/* Authors:  YOUR NAMES HERE */
/* From a skeleton by Paul N. Hilfinger */

#include <stdexcept>
#include "apyc.h"
#include "apyc-parser.hh"

using namespace std;

/** These must be filled in with declarations from the standard
 *  prelude.  They are used to supply the types of built-in
 *  constructs.  All are initially NULL. */
Decl* intDecl;
Decl* listDecl;
Decl* tuple0Decl;
Decl* tuple1Decl;
Decl* tuple2Decl;
Decl* tuple3Decl;
Decl* strDecl;
Decl* dictDecl;
Decl* boolDecl;
Decl* fileDecl;
Decl* rangeDecl;

/** List of declarations corresponding to the module and actual
 *  declarations in the program (as opposed to type variables
 *  introduced by freshen). */
static vector<Decl*> allDecls;

Decl::Decl (const std::string& name, Decl* container, Environ* members)
    : _frozen (true), _name (name), _container (container),
      _members (members) {
    _index = allDecls.size ();
    allDecls.push_back (this);
    /* Allow name.c_str() to be used in the future without reallocation. */
    name.c_str ();
    _built_in = false;
}
void 
Decl::set_built_in(bool b){
    _built_in = b;
}
bool
Decl::is_built_in(){
    return _built_in;
}
        
/* Print THIS on the standard output. */
void 
Decl::print () const
{
    printf ("(%s %d %s ", declTypeName (),
            getIndex (), getName().c_str ());
    printContainer ();
    printPosition ();
    printType ();
    printTypeParams ();
    printMembersList ();
    printf (")");
    fflush (stdout);
}

void
Decl::printContainer () const
{
    if (getContainer () != NULL) 
        printf ("%d ", getContainer ()->getIndex ());    
    else
        printf ("-1 ");
}

void
Decl:: printPosition () const {
}

void
Decl::printType () const {
}

void
Decl::printMembersList () const {
    if (_members != NULL) {
	printf (" (index_list");
	const vector<Decl*>& members = getEnviron ()->get_members ();
	for (size_t i = 0; i < members.size (); i += 1)
	    printf (" %d", members[i]->getIndex ());
	printf (")");
    }
}

void
Decl::printTypeParams () const {
}

Type_Ptr 
Decl::getType () const
{
    return NULL;
}

void
Decl::setType (Type_Ptr type)
{
}

int
Decl::getPosition () const
{
    return -1;
}

AST_Ptr
Decl::getAst () const
{
    return _ast;
}

void
Decl::setAst (AST_Ptr ast)
{
    _ast = ast;
}

bool
Decl::isType () const
{
    return false;
}

bool
Decl::isClass () const
{
    return false;
}

bool
Decl::redefine() const 
{
    return true;
}
bool
Decl::isInternal () const
{
    return false;
}

bool
Decl::isMethod () const
{
    return false;
}

bool
Decl::isFunc() const
{
    return false;
}

Type_Ptr
Decl::asType (int, Type_Ptr, Type_Ptr) const
{
    UNIMPLEMENTED (asType);
}

Type_Ptr
Decl::asType (int arity, Type_Ptr*) const
{
    UNIMPLEMENTED (asType);
}

int
Decl::getTypeArity () const
{
    return 0;
}

const Environ*
Decl::getEnviron () const
{
    if (_members == NULL)
	UNIMPLEMENTED (get_members);
    return _members;
}

void
Decl::addMember (Decl* new_member)
{
    if (_members == NULL)
	UNIMPLEMENTED (addMember);
    if (_members->find_immediate (new_member->getName ()) == NULL)
	_members->define (new_member);
}

void
Decl::addMemberDef (Decl* new_member, AST_Ptr id)
{
    // All I have to say is prepare yourself for a nightmare.
    // If it makes you feel any better I pitty whoever needs to read 
    // this almost as much as I hate myself for writing it. 
    // Anyway, here there be dragons. You have been warned. 
    if (_members == NULL) 
    UNIMPLEMENTED (addMemberDef);
    Decl_Vector dv = new_member->getContainer()->getEnviron()->find_overloadings (new_member->getName());
    _members->defineDef(new_member);
}

void
Decl::checkIfOverloaded(AST_Ptr id)
{
    Decl_Vector dv = this->getContainer()->getEnviron()->find_overloadings (this->getName());
    AST_Ptr current_sig = this->getSignature();
    int children = 0; 
    for_each_child(c, current_sig)
    {
        children++; 
    }end_for;
    for (Decl_Vector::const_iterator i = dv.begin();
            i != dv.end(); 
            i++)
    {
        AST_Ptr prev_sig = (*i)->getSignature(); 
        if (prev_sig == current_sig)
            continue;
        int old_children = 0;
        bool match = true;
        for_each_child(c, prev_sig)
        {
            old_children++;
            if (c_i_ >= children)
            {
                match = false; 
                break;
            }
            if (c->asType() == NULL && current_sig->child(c_i_)->asType() != NULL)
            {
                match = false; 
                break;
            }
            if (current_sig->child(c_i_)->asType() == NULL && c->asType() == NULL)
            {
                continue;
            }
            Unwind_Stack s;
            if (!current_sig->child(c_i_)->getType()->binding()->unify(c->getType()->binding(), s))
            {
                match = false;
            } 
        } end_for;
        if (match && old_children == children) 
        {
            prev_sig->print(cout, 0);
            printf("\n");
            printf("\n");
            current_sig->print(cout, 0);
            printf("\n");
            printf("\n");
            error(id->loc(), "Overloading to same signature");
            prev_sig->child(0)->getType()->binding()->print(cout, 0);
            printf("\n");
            printf("\n");
            current_sig->child(0)->getType()->binding()->print(cout, 0);
            printf("\n");
            printf("\n");
        }
    }
}

void 
Decl::addSignature (AST_Ptr new_sig)
{
    return;
}

AST_Ptr
Decl::getSignature()
{
    return NULL;
}

Decl*
Decl::addVarDecl (AST_Ptr) {
    UNIMPLEMENTED (addVarDecl);
}

Decl*
Decl::addDefDecl (AST_Ptr) {
    UNIMPLEMENTED (addDefDecl);
}

Decl*
Decl::peekDefDecl (AST_Ptr) {
    UNIMPLEMENTED (peekDefDecl);
}
Decl*
Decl::addClassDecl (AST_Ptr) 
{
    UNIMPLEMENTED (addClassDecl);
}

Decl*
Decl::addParamDecl (AST_Ptr, int)
{
    UNIMPLEMENTED(addParamDecl);
}

bool
Decl::assignable () const
{
    return false;
}

bool
Decl::isFrozen () const
{
    return _frozen;
}

void
Decl::setFrozen (bool freeze)
{
}

Decl::~Decl ()
{
}

const char*
Decl::declTypeName () const
{
    return "?";
}

/** The superclass of declarations that describe an entity with a type. */
class TypedDecl : public Decl {
protected:
    TypedDecl (const string& name, Decl* container, AST_Ptr type,
	       Environ* members = NULL) 
        :  Decl (name, container, members),
           _type (type == NULL ? NULL : type->asType ()) {
    }

public:

    Type_Ptr getType () const {
	if (isFrozen () || _type == NULL)
	    return _type;
	else
	    return _type->freshen ();
    }

    void setType (Type_Ptr type) {
        _type = type;
    }

protected:

    void printType () const {
        printf (" ");
        if (_type != NULL) {
            _type->binding ()->print (cout, 0);
        } else
            printf ("?");
    }

private:
    Type_Ptr _type;
};

class VarDecl : public TypedDecl {
public:

    VarDecl (const string& name, Decl* container, AST_Ptr type)
        :  TypedDecl (name, container, type) {
    }

protected:

    const char* declTypeName () const {
        return "vardecl";
    }

    bool assignable () const {
	return true;
    }
};

Decl*
makeVarDecl (const string& name, Decl* func, AST_Ptr type)
{
    return new VarDecl (name, func, type);
}


class ParamDecl : public TypedDecl {
public:

    ParamDecl (const string& name, Decl* func, int k,
              AST_Ptr type)
        :  TypedDecl (name, func, type), _posn (k) {
    }

    int getPosition () const {
        return _posn;
    }

protected:

    const char* declTypeName () const {
        return "paramdecl";
    }

    void printPosition () const {
        printf (" %d", getPosition ());
    }

    bool assignable () const {
	return true;
    }

private:

    int _posn;

};

Decl*
makeParamDecl (const string& name, Decl* func, int k, AST_Ptr type)
{
    return new ParamDecl (name, func, k, type);
}


class InstanceDecl : public TypedDecl {
public:

    InstanceDecl (const string& name, Decl* cls, AST_Ptr type)
        :  TypedDecl (name, cls, type) {
    }

protected:

    const char* declTypeName () const {
        return "instancedecl";
    }

    bool assignable () const {
	return true;
    }
    void setFrozen (bool freeze) {
        _frozen = freeze;
    }

};

Decl*
makeInstanceDecl (const string& name, Decl* cls, AST_Ptr type)
{
    return new InstanceDecl (name, cls, type);
}

class TypeVarDecl : public Decl {
public:

    TypeVarDecl (const string& name, AST_Ptr canonical)
        :  Decl (name, NULL) {
	setAst (canonical);
    }

protected:

    bool isInternal () const {
	return getAst () != NULL && getAst ()->arity () == 0;
    }

    void printContainer () const {
    }

    const char* declTypeName () const {
        return "typevardecl";
    }

};

Decl*
makeTypeVarDecl (const string& name, AST_Ptr typeVar)
{
    return new TypeVarDecl (name, typeVar);
}

class FuncDecl : public TypedDecl {
public:

    FuncDecl (const string& name, Decl* container, AST_Ptr type,
	Environ* env, AST_Ptr signature)
        :  TypedDecl (name, container, type, env) {
            _signature = signature;
    }

    /** Kevin */
    bool isFunc() const
    {
    return true;
    }

    bool redefine() const 
    {
    return false;
    }

    void addSignature(AST_Ptr new_sig)
    {
        _signature = new_sig;
    }

    AST_Ptr getSignature() 
    {
        return _signature;
    }

protected:

    const char* declTypeName () const {
        return "funcdecl";
    }

    void setFrozen (bool freeze) {
        _frozen = freeze;
    }

    Decl* addVarDecl (AST_Ptr id) {
	Decl* decl = makeVarDecl (id->as_string (), this, Type::makeVar ());
	addMember (decl);
	return decl;
    }

    Decl* addDefDecl (AST_Ptr id) {
        string def_name = id->child(0)->as_string();
        Decl* decl = makeFuncDecl (def_name, this, Type::makeVar(), id->child(1));
        addMemberDef (decl, id);
        return decl;
    }

    Decl* addParamDecl (AST_Ptr id, int k)
    {
        Decl *decl = makeParamDecl (id->as_string(), this, k, Type::makeVar());
        addMember(decl);
        return decl;
    }

    AST_Ptr _signature; 
};

Decl*
makeFuncDecl (const string& name, Decl* container, AST_Ptr type, AST_Ptr signature)
{
    return new FuncDecl (name, container, type,
			 new Environ (container->getEnviron ()), signature);
}

class MethodDecl : public FuncDecl {
public:

    MethodDecl (const string& name, Decl* container, AST_Ptr type, AST_Ptr signature)
        :  FuncDecl (name, container, type,
		     new Environ (container->getEnviron ()->get_enclosure ()), signature) {
    }

protected:

    bool isMethod () const {
	return true;
    }
    
    Decl* addParamDecl (AST_Ptr id, int k)
    {
        Decl *decl = makeParamDecl (id->as_string(), this, k, Type::makeVar());
        if (k == 0) 
        {
            // This is the first parameter, thus it should have the type self for static 
            // analysis 
            decl->setType(this->getContainer()->asType());
        }
        addMember(decl);
        return decl;
    }

private:

    mutable Type_Ptr _selectedType;

};

Decl*
makeMethodDecl (const string& name, Decl* cls, AST_Ptr type, AST_Ptr signature)
{
    return new MethodDecl (name, cls, type, signature);
}

class ClassDecl : public Decl {
public:

    ClassDecl (const string& name, AST_Ptr params)
        : Decl (name, NULL, new Environ (outer_environ)), _params (params) {
    }

    bool isClass() const 
    {
        return true;
    }

    bool redefine() const
    {
    return false;
    }

    void printTypeParams () const {
        printf (" (index_list");
	for_each_child (c, _params) {
	    Decl* decl = c->getDecl ();
	    if (decl == NULL)
		printf (" ?");
	    else
		printf (" %d", decl->getIndex ());
	} end_for;
	printf (")");
    }

protected:

    bool isType () const {
	return true;
    }
    void printContainer () const {
    }


    const char* declTypeName () const {
        return "classdecl";
    }

    Type_Ptr asType (int arity, Type_Ptr* params0) const {
        AST_Ptr* params = (AST_Ptr*) params0;
        if (getTypeArity () != -1 && getTypeArity () != arity) {
            throw range_error ("wrong number of type parameters");
        }
        for (int i = 0; i < arity; i += 1)
            if (params[i] == NULL)
                throw domain_error ("attempt to pass null type parameter");

	AST_Ptr id = make_id (getName ().c_str (), NULL);
	id->addDecl (const_cast<ClassDecl*> (this));

        return consTree (TYPE, id,
			 AST::make_tree (TYPE_LIST, params, params+arity))
            ->asType ();
    }

    Type_Ptr asType (int arity, Type_Ptr t0, Type_Ptr t1) const {
        vector<Type_Ptr> params;
        for(int i = 0; i<getTypeArity(); i++){
            params.push_back(Type::makeVar());
        }
        return asType (getTypeArity(), &params[0]);
    }

    Decl* addVarDecl (AST_Ptr id) {
	Decl* decl = makeInstanceDecl (id->as_string (), this, Type::makeVar ());
	addMember (decl);
	return decl;
    }

    Decl* addDefDecl (AST_Ptr id) {
    string name = id->child(0)->as_string();
	Decl* decl = makeMethodDecl (name, this, Type::makeVar(), id->child(1));
	addMemberDef (decl, id);
    int counter = 0;
    for_each_child(c, id->child(1))
    {
        counter++; 
    } end_for;
    if (counter==0)
        error(id->loc(), "Making static class method");
	return decl;
    }

    int getTypeArity () const {
	return _params->arity ();
    }

    AST_Ptr _params;
};
/** Kevin */
Decl*
makeClassDecl (const string& name, AST_Ptr params)
{
    return new ClassDecl (name, params);
}

class ModuleDecl : public Decl {
public:

    ModuleDecl (const string& name)
        :  Decl (name, NULL, new Environ (NULL)) {
    }

protected:

    const char* declTypeName () const {
        return "moduledecl";
    }

    void printContainer () const {
    }

    Decl* addVarDecl (AST_Ptr id) {
	Decl* decl = makeVarDecl (id->as_string (), this, Type::makeVar ());
	addMember (decl);
	return decl;
    }

    Decl* addDefDecl (AST_Ptr id) {
    string name = id->child(0)->as_string();
	Decl* decl = makeFuncDecl (name, this, Type::makeVar (), id->child(1));
	addMemberDef (decl, id);
	return decl;
    }

    /* Kevin */
    Decl* addClassDecl (AST_Ptr id) 
    {
    Decl *decl = makeClassDecl(id->child(0)->as_string(), id->child(1));
    addMember (decl);
    for_each_child(c, id->child(1))
    {
        Decl *typeDecl = makeTypeVarDecl(c->as_string(), c);
        c->addDecl(typeDecl);
    } end_for;
    return decl;
    }

};

Decl*
makeModuleDecl (const string& name)
{
    return new ModuleDecl (name);
}

bool
undefinable (const string& name)
{
    return name == "None";
}

void
outputDecls ()
{
    for (size_t i = 0; i < allDecls.size (); i += 1) {
	if (!allDecls[i]->isInternal ()) {
	    allDecls[i]->print ();
	    printf ("\n");
	}
    }
}
