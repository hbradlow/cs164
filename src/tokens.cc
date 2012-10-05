/* -*- mode: C++; c-file-style: "stroustrup"; indent-tabs-mode: nil; -*- */

/* tokens.cc: Definitions related to AST_Token and its subclasses. */

/* Authors:  Henry Bradlow, Will Skinner, Kevin Lindkvist */

#include <iostream>
#include <cmath>
#include "apyc.h"
#include "ast.h"
#include "apyc-parser.hh"

using namespace std;

/** Default print for tokens. */
void
AST_Token::print (ostream& out, int indent)
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

class Define_Token : public AST_Token {
private:

    void print (ostream& out, int indent) {
        out << "(define " << lineNumber () << " " << text << ")";
    }

    Define_Token* post_make () {
        text = string (as_chars (), text_size ());
        return this;
    }

    string text;

    TOKEN_CONSTRUCTORS(Define_Token, AST_Token);

};

TOKEN_FACTORY(Define_Token, DEF);



class Arglist_Token : public AST_Token {
private:

    void print (ostream& out, int indent) {
        out << "(arglist " << lineNumber () << " " << text << ")";
    }

    Arglist_Token* post_make () {
        text = string (as_chars (), text_size ());
        return this;
    }

    string text;

    TOKEN_CONSTRUCTORS(Arglist_Token, AST_Token);

};

TOKEN_FACTORY(Arglist_Token, ARGLIST);

class ISNOT_Token : public AST_Token {
private:
    void print (ostream& out, int indent) {
        out << "(id " << lineNumber () << " " << "isnot" << ")";
    }
    ISNOT_Token* post_make () {
        text = string (as_chars (), text_size ());
        return this;
    }
    string text;
    TOKEN_CONSTRUCTORS(ISNOT_Token, AST_Token);
};
TOKEN_FACTORY(ISNOT_Token, NIS);
class NOTIN_Token : public AST_Token {
private:
    void print (ostream& out, int indent) {
        out << "(id " << lineNumber () << " " << "notin" << ")";
    }
    NOTIN_Token* post_make () {
        text = string (as_chars (), text_size ());
        return this;
    }
    string text;
    TOKEN_CONSTRUCTORS(NOTIN_Token, AST_Token);
};
TOKEN_FACTORY(NOTIN_Token, NIN);

class ID_Token : public AST_Token {
private:
    void print (ostream& out, int indent) {
        out << "(id " << lineNumber () << " " << text << ")";
    }
    ID_Token* post_make () {
        text = string (as_chars (), text_size ());
        if (text == "as" || text == "assert" || text == "del" || text == "exec" 
                || text == "except" || text == "finally" || text == "future" 
                || text == "global" || text == "raise" || text == "try" || text == "with"
                || text == "yield")
            error(as_chars(), "Illegal identifier");
        return this;
    }
    string text;
    TOKEN_CONSTRUCTORS(ID_Token, AST_Token);
};

TOKEN_FACTORY(ID_Token, ID);

class Type_Token : public AST_Token {
private:
    void print (ostream& out, int indent) {
        out << "(type_var " << lineNumber () << " " << text.substr(2) << ")";
    }
    Type_Token* post_make () {
        text = string (as_chars (), text_size ());
        return this;
    }
    string text;
    TOKEN_CONSTRUCTORS(Type_Token, AST_Token);
};
TOKEN_FACTORY(Type_Token, TYPE_ID);

/** represents an integer literal. */
class Int_Token : public AST_Token {
private:

    void print (ostream& out, int indent) {
        out << "(int_literal " << lineNumber () << " " << value << ")";
    }

    /** initialize value from the text of the lexeme, checking that
     *  the literal is in range.  [the post_make method may be
     *  overridden to provide additional processing during the
     *  construction of a node or token.] */
    Int_Token* post_make () {
        value = atoi(as_chars());
        if (value > pow(2,30.0))
        {
            error(as_chars(), "Integer too large");
        }
        if (value == pow(2,30.0))
            value = -value;
        return this;
    }

    long value;

    TOKEN_CONSTRUCTORS(Int_Token, AST_Token);

};

TOKEN_FACTORY(Int_Token, NUMBER);

    
/** Represents a string. */
class String_Token : public AST_Token {
private:
    
    /** Set literal_text from the text of this lexeme, converting
     *  escape sequences as necessary. */
    String_Token* post_make () {
        if (syntax () == RAWSTRING) {
            literal_text = string (as_chars (), text_size ());
        } else {
            int v;
            const char* s = as_chars ();
            size_t i;
            i = 1;
            literal_text.clear ();
            while (i < text_size ()-1) {
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

    void print (ostream& out, int indent) {
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

    TOKEN_CONSTRUCTORS(String_Token, AST_Token);
    static const String_Token raw_factory;

    string literal_text;
};

TOKEN_FACTORY(String_Token, STRING);

/** A dummy token whose creation registers String_Token as the class
 *  to use for RAWSTRING tokens produced by the lexer.  (The
 *  TOKEN_FACTORY macro above registers String_Token as the class for
 *  non-raw the STRING tokens as well.)
 *  */ 
const String_Token String_Token::raw_factory (RAWSTRING);
