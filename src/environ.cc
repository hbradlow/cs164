/* -*- mode: C++; c-file-style: "stroustrup"; -*- */

/* environ.cc: Environments. */

/* Author:  Paul N. Hilfinger */

#include <cassert>
#include "apyc.h"

using namespace std;

Environ::Environ (const Environ* enclosing)
    : enclosure (enclosing) 
{
}

Environ::Environ (const Environ* environ0, const Environ* enclosing) 
    : members (environ0->members), enclosure (enclosing)
{
}
Decl*
Environ::find_overloaded(const string& name, vector<Type_Ptr> arg_types) const {
    Decl* d = find_overloaded_immediate (name, arg_types);
    if (d != NULL)
        return d;
    else if (enclosure == NULL) {
      printf("Returned a null decl\n");
	return NULL;
    }
    else
        return enclosure->find_overloaded(name, arg_types);
}

Decl*
Environ::find_overloaded_immediate(const string& name, vector<Type_Ptr> arg_types) const {
    for (Decl_Vector::const_iterator i = members.begin (); 
	 i != members.end (); 
	 i++) 
    {
	if (name == (*i)->getName ()) {
	  bool match = true;
	  int j = -1;
	  (*i)->print();
	  (*i)->getParamTypes()->print(cout,0);
	  for_each_child(c, (*i)->getParamTypes()) {
	    j++;
	    if (!c->asType()->unifies(arg_types[j])) {
              match = false;
            }
            else {
              break;
            }
          } end_for;
          if (match)
            return *i;
        }
    }
    return NULL;
}

Decl* 
Environ::find_immediate (const string& name) const
{
    for (Decl_Vector::const_iterator i = members.begin (); 
	 i != members.end (); 
	 i++) 
    {
	if (name == (*i)->getName ())
	    return *i;
    }
    return NULL;
}

void
Environ::find_immediate (const string& name, Decl_Vector& defns) const
{
    defns.clear ();
    for (Decl_Vector::const_iterator i = members.begin (); 
	 i != members.end (); 
	 i++) 
    {
	if (name == (*i)->getName ())
	    defns.push_back (*i);
    }
}
    

Decl*
Environ::find (const string& name) const
{
    Decl* d = find_immediate (name);
    if (d != NULL)
        return d;
    else if (enclosure == NULL)
	return NULL;
    else
        return enclosure->find (name);
}

void
Environ::find(const string& name, Decl_Vector& defns) const
{
    find_immediate(name, defns);
    if (!defns.empty () || enclosure == NULL)
	return;
    enclosure->find(name, defns);
}

void 
Environ::define (Decl* decl)
{
    //Will commented out for overloading. May need to uncomment later
    //assert (find_immediate (decl->getName ()) == NULL);
    members.push_back (decl);
}

const Environ* 
Environ::get_enclosure () const
{
    return enclosure;
}

const Decl_Vector&
Environ::get_members () const
{
    return members;
}

void 
Environ::printMembers() 
{
  for (int i = 0; i < get_members().size(); i++) {
    printf("%d\n", i);
    get_members()[i]->print();
    printf("\n");
  }
}

/* DEBUGGING */

void
DB (const Environ* env)
{
    if (env == NULL) {
        fprintf (stderr, "NULL\n");
    } else {
        const char* label;
        label = "Immediate";
        while (env != NULL) {
            const Decl_Vector& members = env->get_members ();
            fprintf (stderr, "%s:\n", label);
            for (size_t i = 0; i < members.size (); i += 1) {
                fprintf (stderr, "   %s @%p\n", members[i]->getName ().c_str (),
                         members[i]);
            }
            env = env->get_enclosure ();
            label = "Enclosed by";
        }
    }
}

