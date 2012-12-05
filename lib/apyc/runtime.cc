/* -*- mode: C++; c-file-style: "stroustrup"; indent-tabs-mode: nil; -*- */

/* APYC Runtime Library */

/* Authors:  YOUR NAMES HERE */

// OTHERS?

#include "runtime.h"
#include <vector>

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
        return frame->getVar(name);
    else
        return this->locals.find(name)->second;
}
Frame::Frame(Frame* static_link) : frame(static_link)
{
    this->locals = std::map<string, void*>();
}
Frame::Frame(){
}
Closure::Closure(void* (*fp) (Frame*), Frame* frame, std::vector<string> args) : fp(fp), frame(frame), args(args)
{
}

Closure::Closure(){
}
