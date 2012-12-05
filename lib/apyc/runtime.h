/* -*- mode: C++; c-file-st*((int*)frame->getVar("y")le: "stroustrup"; indent-tabs-mode: nil; -*- */

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
class Object{
public:
    virtual void print(ostream& o) 
    {
        o << "fuck";
    }
    virtual void inner_print(ostream& o) 
    {
        print(o);
    }
};
class Frame
{
private:
    map<string, void*> locals;

public:
    Frame* frame;
    Frame(Frame* static_link);
    Frame();
    virtual void setVar(string name, void* value);
    virtual void* getVar(string name);
};

class Closure : public Object {
public:
    Closure();
    Closure(void* (*fp) (Frame*), Frame* frame, std::vector<string> args);
    void* (*fp) (Frame*);
    Frame* frame;
    std::vector<string> args; 
    void* call(Frame* dynamic_frame)
    {
       return  fp(dynamic_frame);
    }
};

class Bool : public Object{
public:
    bool value;
    Bool(bool v){
        value = v;
    }
    Bool(void* v){
        value = ((Bool*)v)->value;
    }
    virtual void print(ostream& o) 
    {
        if (value) 
            o << "True"; 
        else 
            o << "False";
    }
};

class Integer: public Object{
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
    void print(ostream& o) 
    {
        o << value;
    }
};

class String: public Object{
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
    Integer*
    len()
    {
        return new Integer(value.length());
    }
    void inner_print(ostream& o) 
    {
        o << "'" << value << "'";
    }
    void print(ostream& o) 
    {
        o << value;
    }
};

template<class K, class V>
class Dict: public Object{
public:
   map<K, V> items;
   ostream& operator<<(ostream& out){
       out << "{";
       for(std::map<int,int>::iterator it = items.begin() ; it != items.end(); ++it){
           if(it!=items.begin())
               out << ",";
           out << it->first << " : " << it->second;
       }
       out << "}";
       return out;
   }
   Dict(map<K, V> _items): items(_items){}
   Integer* len()
   {
        return new Integer(items.size());
   }
};

class List: public Object{
public:
    vector<Object*> items;
    virtual void print(ostream& out)
    {
        out << "[";
        for(std::vector<Object*>::iterator it = items.begin() ; it != items.end(); ++it){
            if(it!=items.begin())
                out << ", ";
            (*it)->print(out);
        }
        out << "]";
    }
    virtual void inner_print(ostream& o)
    {
        this->print(o);
    }
    List(vector<Object*> _items): items(_items){}
    Integer* 
    len()
    {
         return new Integer(items.size());
    }
    Object*
    getItem(Integer i)
    {
        return items[i.value];
    }
};

class Tuple0: public Object{
public:
    void print(ostream& out) 
    {
        out << "()";
    }
};

template<class T>
class Tuple1: public Object{
public:
   Object* item;
   Tuple1(void* t) : item((Object*)t){}
    void print(ostream& o) 
    {
        o << "("; 
        item->inner_print(o);
        o << ",)";
    }
};

template<class T, class U>
class Tuple2: public Object{
public:
   Object* item1;
   Object* item2;
   Tuple2(void* t, void* u) : item1((Object*)t), item2((Object*)u){}
    void print(ostream& out) 
    {
        out << "(";
        item1->inner_print(out);
        out << ", ";
        item2->inner_print(out);
        out << ")";
    }
};

template<class T, class U, class V>
class Tuple3: public Object{
public:
   Object* item1;
   Object* item2;
   Object* item3;
   Tuple3(void* t, void* u, void* v) : item1((Object*)t), item2((Object*)u), item3((Object*)v){}
    void print(ostream& out) 
    {
        out << "(";
        item1->inner_print(out);
        out << ", ";
        item2->inner_print(out);
        out << ", ";
        item3->inner_print(out);
        out << ")";
    }
};
//------------------------------------------------------------
// List
//------------------------------------------------------------
inline
Object* operator||(const List& b, const List& rhs){
    if(b.items.size())
        return new List(b.items);
    else
        return new List(rhs.items);
}
inline
Object* operator&&(const List& b, const List& rhs){
    if(b.items.size())
        return new List(rhs.items);
    else
        return new List(b.items);
}
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
//------------------------------------------------------------

//------------------------------------------------------------
// Integer 
//------------------------------------------------------------
inline
Object* operator||(const Integer& b, const Integer& rhs){
    if(b.value)
        return new Integer(b.value);
    else
        return new Integer(rhs.value);
}
inline
Object* operator&&(const Integer& b, const Integer& rhs){
    if(b.value)
        return new Integer(rhs.value);
    else
        return new Integer(b.value);
}
inline
Bool* operator<(const Integer& a, const Integer& b){
    return new Bool(a.value<b.value);
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
//------------------------------------------------------------

//------------------------------------------------------------
// BOOL
//------------------------------------------------------------

inline
bool operator==(const Bool& b, bool rhs){
    return b.value == rhs;
}
inline
bool operator!=(const Bool& b, const Bool& rhs){
    return b.value != rhs.value;
}
inline
bool operator||(const Bool& b, const Bool& rhs){
    return b.value || rhs.value;
}
inline
Bool* operator&&(const Bool& b, const Bool& rhs){
    return new Bool(b.value && rhs.value);
}
//------------------------------------------------------------
#endif
