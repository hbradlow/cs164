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
Frame::getVar(string name)
{
    if (this->locals.count(name) == 0) 
        return this->enclosing->getVar(name);
    else if (this->locals == NULL) // This is a redundant check
        return NULL; 
    else
        return this->locals.find(name)->second;
}

Frame::Frame(Frame* static_link, map<string, void*> locals)
{
    this->enclosing = static_link;
    this->locals = locals;
}
Closure::Closure(void* (*fp) (), Frame* frame)
{
    this->fp = fp;
    this->frame = frame;
}

