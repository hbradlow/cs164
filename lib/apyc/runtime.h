/* APYC Runtime Librar*((int*)frame->getVar("y") Headers */

/* Authors:  YOUR NAMES HERE */

#ifndef _RUNTIME_H_
#define _RUNTIME_H_

#include <sstream>
#include <string>
#include <vector>
#include <math.h>
#include <stdint.h>
#include <cstdlib>
#include <iostream>
#include <map>
#include "natives.h"

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

class Integer{
public:
    int value;
    Integer(int v){
        value = v;
    }
    Integer(void* v){
        value = ((Integer*)v)->value;
    }
    Integer* pow_(Integer i)
    {
        return new Integer(pow((double)value, (double)i.value));
    }
};

class String{
public:
    string value;
    String(string v){
        value = v;
    }
    String(void* v){
        value = ((String*)v)->value;
    }
    Integer*
    toInt()
    {
        return new Integer(atoi(value.c_str()));
    }
    String*
    getIndex(Integer i)
    {
        return new String(new string(&value[i.value]));
    }
    String*
    getSlice(Integer i, Integer j)
    {
        return new String(new string(value.substr(i.value, j.value)));
    }
};

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

//------------------------------------------------------------
// String
//------------------------------------------------------------
inline 
Bool* operator<(const String& b, const String& rhs)
{
    return new Bool(b.value.compare(rhs.value) < 0);
}
inline 
Bool* operator>(const String& b, const String& rhs)
{
    return new Bool(b.value.compare(rhs.value) > 0);
}
inline 
Bool* operator<=(const String& b, const String& rhs)
{
    return new Bool(b.value.compare(rhs.value) <= 0);
}
inline 
Bool* operator>=(const String& b, const String& rhs)
{
    return new Bool(b.value.compare(rhs.value) >= 0);
}
inline
Bool* operator==(const String& b, const String& rhs){
    return new Bool(b.value==rhs.value);
}
inline
Bool* operator==(const String& b, bool rhs){
    return new Bool(b.value!="");
}
inline 
Bool* operator!=(const String& b, const String& rhs)
{
    return new Bool(b.value != rhs.value);
}
inline 
String* operator+(const String& b, const String& c)
{
    return new String(b.value + c.value);
}
inline
ostream& operator<<(ostream& out, const String& b){
    out << b.value;
    return out;
}
//------------------------------------------------------------

//------------------------------------------------------------
// Integer 
//------------------------------------------------------------
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
Bool* operator>(const Integer& a, const Integer& b){
    return new Bool(a.value>b.value);
}
inline
Bool* operator>=(const Integer& a, const Integer& b){
    return new Bool(a.value>=b.value);
}
inline
Bool* operator<=(const Integer& a, const Integer& b){
    return new Bool(a.value<=b.value);
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
//------------------------------------------------------------

//------------------------------------------------------------
// BOOL
//------------------------------------------------------------

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
//------------------------------------------------------------


#endif
