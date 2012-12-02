/* -*- mode: C++; c-file-style: "stroustrup"; indent-tabs-mode: nil; -*- */

/* APYC Runtime Library */

/* Authors:  YOUR NAMES HERE */

// OTHERS?

#include "runtime.h"

using namespace std;

/** 
 * Kevin 
 */
void 
Frame::setVar(string name, void* value)
{
    this->locals[name] = value; 
}

void* 
Frame::getVar(string name) const
{
    if (this->locals.count(name) == 0) 
        return enclosing->getVar(name);
    else
        return this->locals.find(name)->second;
}
Frame::Frame(const Frame* static_link) : enclosing(static_link)
{
    this->locals = std::map<string, void*>();
}
Closure::Closure(void* (*fp) (), Frame frame) : fp(fp), frame(frame)
{
}

