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

class None;
class Frame;

/** 
 * Kevin 
 */
class Object{
public:
    Frame* frame;
    virtual void print(ostream& o) 
    {
        o << "fuck";
    }
    virtual void inner_print(ostream& o) 
    {
        print(o);
    }
    virtual string getValue(){
        return "";
    }
    virtual Object* getItem(Object* o){
        return new Object();
    }
};
class None: public Object{
public:
    virtual void print(ostream& o) 
    {
        o << "None";
    }
    virtual void inner_print(ostream& o) 
    {
        print(o);
    }
};
class Frame
{
private:
    map<string, Object*> locals;

public:
    Frame* frame;
    Frame(Frame* static_link);
    Frame();
    virtual void setVar(string name, Object* value);
    virtual Object* getVar(string name);
};

class Closure : public Object {
public:
    Closure();
    Closure(Object* (*fp) (Frame*), Frame* frame, std::vector<string> args);
    Closure(const Closure& copy)
    {
        fp = copy.fp; 
        frame = copy.frame;
    }
    Object* (*fp) (Frame*);
    Frame* frame;
    std::vector<string> args; 
    Object* call(Frame* dynamic_frame)
    {
       return  fp(dynamic_frame);
    }
    void print(ostream& out)
    {
        for (std::vector<string>::iterator i = args.begin();
                i != args.end(); 
                ++i)
        {
            out << ",";
            out << *i << endl;
        }
    }
};

class Bool : public Object{
public:
    bool value;
    Bool(bool v){
        value = v;
    }
    Bool(Object* v){
        value = ((Bool*)v)->value;
    }
    virtual void print(ostream& o) 
    {
        if (value) 
            o << "True"; 
        else 
            o << "False";
    }
    virtual string getValue(){
        std::stringstream ss;
        if (value) 
            ss << "True"; 
        else 
            ss << "False";
        return ss.str();
    }
};

class Integer: public Object{
public:
    int value;
    Integer(int v){
        value = v;
    }
    Integer(Object* v){
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
    virtual string getValue(){
        std::stringstream ss;
        ss << value;
        return ss.str();
    }
};

class String: public Object{
public:
    string value;
    String(string v){
        value = v;
    }
    String(string* v){
        value = *v;
    }
    String(Object* v){
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
        if (i.value >= 0)
        {
            stringstream ss;
            ss << value[i.value];
            return new String(ss.str());
        }
        else 
        {
            int neg = value.length()+i.value;
            stringstream ss;
            ss << value[neg];
            return new String(ss.str());
        }
    }
    String*
    getSlice(Integer i, Integer j)
    {
        return new String(new string(value.substr(i.value, j.value-1)));
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
    string getValue(){
        return value;
    }
};

class Dict: public Object{
public:
   map<string, Object*> items;
   void print (ostream& out) {
       out << "{";
       for(std::map<string,Object*>::iterator it = items.begin() ; it != items.end(); ++it){
           if(it!=items.begin())
               out << ", ";
           out << it->first;
           out << ": ";
           it->second->inner_print(out);
       }
       out << "}";
   }
   Dict(map<string, Object*> _items): items(_items){}
   Integer* len()
   {
        return new Integer(items.size());
   }
   Bool* contains(Object* x) {
       if (items.count(((String)x).value) == 0) {
           return new Bool(false);
       }
       else {
           return new Bool(true);
       }
   }
   Bool* notContains(Object* x) {
       if (items.count(((String)x).value) == 0) {
           return new Bool(true);
       }
       else {
           return new Bool(false);
       }
   }
   Object* getItem(Object* x){
        return items.find(x->getValue())->second;
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
    List(Integer* low, Integer* high) 
    {
        items = vector<Object*>();
        for (int j = low->value; j < high->value; j++)
        {
            items.push_back(new Integer(j));
        }
    }
    Integer* 
    len()
    {
         return new Integer(items.size());
    }
    Object*
    getItem(Integer* i)
    {
        if (i->value >= 0)
        return items[i->value];
        else 
        {
        int neg = items.size()+i->value;
        return items[neg]; 
        }
    }
    List*
    xrange(Integer i)
    {
    }
    List*
    getSlice(Integer i, Integer j) {
        vector<Object*> result;
        for (int k = i.value; k<j.value; ++k) {
            result.push_back(items[k]);
        }
        List * resultlist = new List(result);
        return resultlist;
    }
};

class Tuple0: public Object{
public:
    void print(ostream& out) 
    {
        out << "()";
    }
    Object* getItem(Object* o){
        return new None();
    }
};

template<class T>
class Tuple1: public Object{
public:
   Object* item;
   Tuple1(Object* t) : item((Object*)t){}
    void print(ostream& o) 
    {
        o << "("; 
        item->inner_print(o);
        o << ",)";
    }
    Object* getItem(Object* o){
        return item;
    }
};

template<class T, class U>
class Tuple2: public Object{
public:
   Object* item1;
   Object* item2;
   Tuple2(Object* t, Object* u) : item1((Object*)t), item2((Object*)u){}
    void print(ostream& out) 
    {
        out << "(";
        item1->inner_print(out);
        out << ", ";
        item2->inner_print(out);
        out << ")";
    }
    Object* getItem(Integer* o){
        if(o->value==0)
            return item1;
        if(o->value==1)
            return item2;
        return new None();
    }
};

template<class T, class U, class V>
class Tuple3: public Object{
public:
   Object* item1;
   Object* item2;
   Object* item3;
   Tuple3(Object* t, Object* u, Object* v) : item1((Object*)t), item2((Object*)u), item3((Object*)v){}
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
    Object* getItem(Integer* o){
        if(o->value==0)
            return item1;
        if(o->value==1)
            return item2;
        if(o->value==2)
            return item3;
        return new None();
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
inline
bool operator==(const List& b, bool rhs){
    if(b.items.size() && rhs)
        return true;
    if(!b.items.size() && !rhs)
        return true;
    return false;
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
bool operator==(const String& b, bool rhs){
    return (b.value!="");
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
bool operator==(const Integer& b, bool rhs){
    return ((b.value && rhs) || (!b.value && !rhs));
}
//------------------------------------------------------------

//------------------------------------------------------------
// BOOL
//------------------------------------------------------------

inline
bool operator==(const Object& b, bool rhs){
    return false;
}

inline
bool operator==(const Bool& b, bool rhs){
    return b.value == rhs;
}
inline
bool operator!=(const Bool& b, const Bool& rhs){
    return b.value != rhs.value;
}
inline
Bool* operator||(const Bool& b, const Bool& rhs){
    return new Bool(b.value || rhs.value);
}
inline
Bool* operator&&(const Bool& b, const Bool& rhs){
    return new Bool(b.value && rhs.value);
}
//------------------------------------------------------------
#endif
