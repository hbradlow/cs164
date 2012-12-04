/* APYC Runtime Librar*((int*)frame->getVar("y") Headers */

/* Authors:  YOUR NAMES HERE */

#ifndef _RUNTIME_H_
#define _RUNTIME_H_

#include <sstream>
#include <string>
#include <vector>
#include <stdint.h>

#define NATIVE__donotcall__
#define NATIVE__None__              return NULL
#define NATIVE__truth__             return (*((Integer*)frame->getVar("x")))==Integer(0)
#define NATIVE__not__               return (*((Integer*)frame->getVar("x")))!=Integer(0)
#define NATIVE__xrange__
#define NATIVE__len__range__
#define NATIVE__add__int__          return (*(Integer*)frame->getVar("x"))+(*(Integer*)frame->getVar("y"))
#define NATIVE__sub__int__          return (*(Integer*)frame->getVar("x"))-(*(Integer*)frame->getVar("y"))
#define NATIVE__mul__int__          return (*(Integer*)frame->getVar("x"))*(*(Integer*)frame->getVar("y"))
#define NATIVE__floordiv__int__     return (*(Integer*)frame->getVar("x"))/(*(Integer*)frame->getVar("y"))
#define NATIVE__mod__int__          return (*(Integer*)frame->getVar("x"))%(*(Integer*)frame->getVar("y"))
#define NATIVE__pow__int__
#define NATIVE__neg__int__          
#define NATIVE__pos__int__          
#define NATIVE__lt__int__           return (*(Integer*)frame->getVar("x"))<(*(Integer*)frame->getVar("y"))
#define NATIVE__gt__int__           return (*(Integer*)frame->getVar("x"))>(*(Integer*)frame->getVar("y"))
#define NATIVE__le__int__           
#define NATIVE__ge__int__           
#define NATIVE__eq__int__           return (*((Integer*)frame->getVar("x")))==(*((Integer*)frame->getVar("y")))
#define NATIVE__ne__int__           
#define NATIVE__toint__str__
#define NATIVE__add__str__
#define NATIVE__lmul__str__         std::stringstream ss; \
                                    for(int i = 0; i<*((int*)frame->getVar("y")); i++) \
                                        ss << *((string*)frame->getVar("x")); \
                                    String* s = new String(ss.str());\
                                    return s
#define NATIVE__rmul__str__         std::stringstream ss; \
                                    for(int i = 0; i<*((int*)frame->getVar("x")); i++) \
                                        ss << *((string*)frame->getVar("y")); \
                                    String* s = new String(ss.str());\
                                    return s
#define NATIVE__lt__str__
#define NATIVE__gt__str__
#define NATIVE__le__str__
#define NATIVE__ge__str__
#define NATIVE__eq__str__
#define NATIVE__ne__str__
#define NATIVE__getitem__str__
#define NATIVE__getslice__str__
#define NATIVE__len__str__
#define NATIVE__tostr__
#define NATIVE__getitem__list__
#define NATIVE__getslice__list__
#define NATIVE__len__list__
#define NATIVE__argv__
#define NATIVE__open1__
#define NATIVE__open2__
#define NATIVE__close__
#define NATIVE__standard_file__
#define NATIVE__readline__
#define NATIVE__read__
#define NATIVE__getitem__dict__
#define NATIVE__len__dict__
#define NATIVE__contains__dict__
#define NATIVE__notcontains__dict__
#define NATIVE__is__
#define NATIVE__isnot__

#include <cstdlib>
#include <iostream>
#include <map>

using namespace std;

/** 
 * Kevin 
 */
class Frame
{
private:
    map<string, void*> locals;
    const Frame* enclosing;

public:
    Frame(const Frame* static_link);
    Frame();
    virtual void setVar(string name, void* value);
    virtual void* getVar(string name) const;
};

class Closure {
public:
    Closure();
    Closure(void* (*fp) (Frame*), Frame* frame, std::vector<string> args);
    void* (*fp) (Frame*);
    Frame* frame;
    std::vector<string> args; 

};

class Bool{
public:
    bool value;
    Bool(bool v){
        value = v;
    }
    Bool(void* v){
        value = ((Bool*)v)->value;
    }
};

inline
bool operator==(const Bool& b, bool rhs){
    return b.value == rhs;
}
inline
ostream& operator<<(ostream& out, const Bool& b){
    if(b.value)
        out << "False";
    else
        out << "True";
    return out;
}

class String{
public:
    string value;
    String(string v){
        value = v;
    }
    String(void* v){
        value = ((String*)v)->value;
    }
};
inline
bool operator==(const String& b, const String& rhs){
    return b.value==rhs.value;
}
inline
bool operator==(const String& b, bool rhs){
    return b.value!="";
}
inline
ostream& operator<<(ostream& out, const String& b){
    out << b.value;
    return out;
}
class Integer{
public:
    int value;
    Integer(int v){
        value = v;
    }
    Integer(void* v){
        value = ((Integer*)v)->value;
    }
};
inline
Bool* operator<(const Integer& a, const Integer& b){
    return new Bool(a.value<b.value);
}
inline
Bool* operator>(const Integer& a, const Integer& b){
    return new Bool(a.value>b.value);
}
inline
Integer* operator%(const Integer& a, const Integer& b){
    return new Integer(a.value%b.value);
}
inline
Integer* operator/(const Integer& a, const Integer& b){
    return new Integer(a.value/b.value);
}
inline
Integer* operator-(const Integer& a, const Integer& b){
    return new Integer(a.value-b.value);
}
inline
Integer* operator+(const Integer& a, const Integer& b){
    return new Integer(a.value+b.value);
}
inline
Integer* operator*(const Integer& a, const Integer& b){
    return new Integer(a.value*b.value);
}
inline
Bool* operator!=(const Integer& b, const Integer& rhs){
    return new Bool(b.value!=rhs.value);
}
inline
Bool* operator==(const Integer& b, const Integer& rhs){
    return new Bool(b.value==rhs.value); 
}
inline
Bool* operator==(const Integer& b, bool rhs){
    return new Bool((b.value && rhs) || (!b.value && !rhs));
}
inline
ostream& operator<<(ostream& out, const Integer& b){
    out << b.value;
    return out;
}


template<class T>
class List{
public:
   vector<T> items;
   ostream& operator<<(ostream& out){
       out << "[";
       for(std::vector<int>::iterator it = items.begin() ; it != items.end(); ++it){
           if(it!=items.begin())
               out << ",";
           out << *it;
       }
       out << "]";
       return out;
   }
};

#endif
