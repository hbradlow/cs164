/* -*- mode: C++; c-file-style: "stroustrup"; indent-tabs-mode: nil; -*- */

/* tokens.cc: Definitions related to AST_Token and its subclasses. */

/* Authors:  YOUR NAMES HERE */

#include <iostream>
#include <cerrno>
#include "apyc.h"
#include "ast.h"
#include "apyc-parser.hh"

using namespace std;

/** Default print for tokens. */
void
AST_Token::_print (ostream& out, int indent)
{
    out << "(<Token>)";
}

/** Default implementation. */
string
AST_Token::string_text () const
{
    throw logic_error ("unimplemented operation: string_text");
}

/** Default implementation. */
void
AST_Token::append_text(const string& s)
{
    throw logic_error ("unimplemented operation: append_text");
}


/** The supertype of tokens with a type. */
class Typed_Token : public AST_Token {
public:

    Type_Ptr getType () {
        if (_type == NULL)
            _type = computeType ();
        return _type;
    }

protected:

    void doTyping (Decl* context, bool& changed, bool& unresolved) {
        if (_type == NULL) {
            _type = computeType ();
            changed = true;
        }
    }

    /** Computes my type, which is then cached by getType(). */
    virtual Type_Ptr computeType () {
        return NULL;
    }

    Type_Ptr _type;

    TOKEN_BASE_CONSTRUCTORS (Typed_Token, AST_Token);

};    

/** Represents an integer literal. */
class Int_Token : public Typed_Token {
protected:

    void _print (ostream& out, int indent) {
	out << "(int_literal " << lineNumber () << " " << value
	    << ")";
    }

    Type_Ptr
    getType ()
    {
        return this->computeType();
    }

    TOKEN_CONSTRUCTORS(Int_Token, Typed_Token);

    Int_Token* post_make () {
        string text = as_string ();
        errno = 0;
        value = strtol (text.c_str (), (char**) NULL, 0);
        if (errno != 0 || value > (1L<<30)) {
            error (loc (), "literal value out of range: %s",
                   text.c_str ());
            value = 0;
        }
        return this;
    }

    Type_Ptr computeType () {
        if(intDecl==NULL)
        {
            error(loc(),"int not defined");
            return NULL;
        }
        return intDecl->asType ();
    }

    long value;

};

TOKEN_FACTORY(Int_Token, INT_LITERAL);

/** Represents an identifier. */
class Id_Token : public Typed_Token {
public:
    bool is_none(){
        return strcmp(this->as_string().c_str(),"None") == 0;
    }
protected:

    void _print (ostream& out, int indent) {
	out << "(id " << lineNumber () << " " << as_string ();
        if (getDecl () != NULL)
            out << " " << getDecl ()->getIndex ();
        out << ")";
    }

    TOKEN_CONSTRUCTORS (Id_Token, Typed_Token);

    int numDecls () {
        return _me.size ();
    }

    Decl* getDecl (int k = 0) {
        if (k >= (int) _me.size ())
            return NULL;
        else
            return _me[k];
    }

    Type_Ptr
    getType ()
    {
        this->assert_is_defined();
        if(this->getDecl()!=NULL)
            return this->getDecl()->getType();
        else
            return NULL;
    }

    void addDecl (Decl* decl) {
        _me.push_back (decl);
    }

    void removeDecl (int k) {
        assert (k >= 0 && k < (int) _me.size ());
        _me.erase (_me.begin () + k);
    }

    void addTargetDecls(Decl *enclosing)
    {
        Decl *decl = enclosing->getEnviron()->find_immediate(as_string());
        if (decl == NULL)
            decl = enclosing->addVarDecl(this);
        if (enclosing->isClass() && enclosing->getName() == as_string())
            error(loc(), "Redefinition of class variable");
        if (enclosing->isFunc() && enclosing->getName() == as_string())
            error(loc(), "Redefinition of function variable");
        addDecl(decl);
    }
    void collectDecls(Decl *enclosing)
    {
    }
   
    void create_attr_ref (Decl *enclosing)
    {
        Decl *decl = enclosing->getEnviron()->find(as_string());
        addDecl(decl);
    }

    void collectParams (Decl* enclosing, int k)
    {
        Decl *decl = enclosing->addParamDecl(this, k);
        addDecl(decl);
    }

    void unifyWith(AST_Ptr right){
        Unwind_Stack s;
        Type_Ptr t1 = this->getType();
        Type_Ptr t2 = right->getType();
        if(t2!=NULL)
        {
            int b = t1->unify(t2,s);
            if(b==0){
                error(loc(),"Incompatible types in tokens.cc");
            }
        }
        else{
            t2 = right->asType();
            if(t2!=NULL)
            {
                int b = t1->unify(t2,s);
                if(b==0){
                    error(loc(),"Incompatible types");
                }
            }
        }
    }
    void resolveSimpleIds (const Environ* env)
    {
        Decl *decl = env->find(as_string());
        if (decl == NULL && !numDecls())
        {
            string str = "Use of undeclared identifier '";
            str += as_string() + "'"; 
            error(loc(), str.c_str()); 
        }
        addDecl(decl);
    }

private:

    Decl_Vector _me;

};

TOKEN_FACTORY(Id_Token, ID);

/** Represents a string. */
class String_Token : public Typed_Token {
public:
    Type_Ptr
    getType ()
    {
        return this->computeType();
    }
private:
    
    String_Token* post_make () {
        if (syntax () == RAWSTRING) {
            literal_text = string (as_chars (), text_size ());
        } else {
            int v;
            const char* s = as_chars ();
            size_t i;
            i = 0;
            literal_text.clear ();
            while (i < text_size ()) {
                i += 1;
                if (s[i-1] == '\\') {
                    i += 1;
                    switch (s[i-1]) {
                    default: literal_text += '\\'; v = s[i-1]; break;
                    case '\n': continue;
                    case 'a': v = '\007'; break;
                    case 'b': v = '\b'; break;
                    case 'f': v = '\f'; break;
                    case 'n': v = '\n'; break;
                    case 'r': v = '\r'; break;
                    case 't': v = '\t'; break;
                    case 'v': v = '\v'; break;
                    case '\'': v = '\''; break;
                    case '"': case '\\': v = s[i-1]; break;
                    case '0': case '1': case '2': case '3': case '4':
                    case '5': case '6': case '7': 
                    { 
                        v = s[i-1] - '0';
                        for (int j = 0; j < 2; j += 1) {
                            if ('0' > s[i] || s[i] > '7')
                                break;
                            v = v*8 + (s[i] - '0');
                            i += 1;
                        }
                        break;
                    }
                    case 'x': {
                        if (i+2 > text_size () || 
                            !isxdigit (s[i]) || !isxdigit (s[i+1])) {
                            error (s, "bad hexadecimal escape sequence");
                            break;
                        }
                        sscanf (s+i, "%2x", &v);
                        i += 2;
                        break;
                    }
                    }
                } else
                    v = s[i-1];
                literal_text += (char) v;        
            }
        }
        return this;
    }

    void _print (ostream& out, int indent) {
        out << "(string_literal " << lineNumber () << " \"";
        for (size_t i = 0; i < literal_text.size (); i += 1) {
            char c = literal_text[i];
            if (c < 32 || c == '\\' || c == '"') {
                out << "\\" << oct << setw (3) << setfill('0') << (int) c
                    << setfill (' ') << dec;
            } else
                out << c;
        }
        out << "\")";
    }

    string string_text () const {
        return literal_text;
    }

    void append_text(const string& s) {
        literal_text += s;
    }

    Type_Ptr computeType () {
        return strDecl->asType ();
    }
        
    TOKEN_CONSTRUCTORS(String_Token, Typed_Token);
    static const String_Token raw_factory;

    string literal_text;
};

TOKEN_FACTORY(String_Token, STRING);

/** A dummy token whose creation registers String_Token as the class
 *  to use for RAWSTRING tokens produced by the lexer.  (The
 *  TOKEN_FACTORY macro above registers String_Token as the class for
 *  non-raw STRING tokens as well.)
 */ 
const String_Token String_Token::raw_factory (RAWSTRING);

