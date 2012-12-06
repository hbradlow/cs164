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
Frame::setVar(string name, Object* value)
{
    this->locals[name] = value; 
}

Object* 
Frame::getVar(string name)
{
    if (this->locals.count(name) == 0) 
        return frame->getVar(name);
    else
        return this->locals.find(name)->second;
}
Frame::Frame(Frame* static_link) : frame(static_link)
{
    this->locals = std::map<string, Object*>();
}
Frame::Frame(){
}
Closure::Closure(Object* (*fp) (Frame*), Frame* frame, std::vector<string> args) : fp(fp), frame(frame), args(args)
{
}

Closure::Closure(){
}
