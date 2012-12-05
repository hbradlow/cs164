#include <sstream>
#include <string>
#include <vector>
#include <math.h>
#include <stdint.h>

#define NATIVE__donotcall__
#define NATIVE__None__              return NULL
#define NATIVE__truth__             return (*((Integer*)frame->getVar("x")))!=Integer(0)
#define NATIVE__not__               return (*((Integer*)frame->getVar("x")))==Integer(0)
#define NATIVE__xrange__            return new List((Integer*)frame->getVar("low"), (Integer*)frame->getVar("high"))
#define NATIVE__len__range__        return ((List*)frame->getVar("r"))->len(); 
#define NATIVE__add__int__          return (*(Integer*)frame->getVar("x"))+(*(Integer*)frame->getVar("y"))
#define NATIVE__sub__int__          return (*(Integer*)frame->getVar("x"))-(*(Integer*)frame->getVar("y"))
#define NATIVE__mul__int__          return (*(Integer*)frame->getVar("x"))*(*(Integer*)frame->getVar("y"))
#define NATIVE__floordiv__int__     return (*(Integer*)frame->getVar("x"))/(*(Integer*)frame->getVar("y"))
#define NATIVE__mod__int__          return (*(Integer*)frame->getVar("x"))%(*(Integer*)frame->getVar("y"))
#define NATIVE__pow__int__          return (*(Integer*)frame->getVar("x")).pow_((*(Integer*)frame->getVar("y")))
#define NATIVE__neg__int__          return new Integer(-((Integer*)frame->getVar("x"))->value)
#define NATIVE__pos__int__          return new Integer(+((Integer*)frame->getVar("x"))->value)
#define NATIVE__lt__int__           return (*(Integer*)frame->getVar("x"))<(*(Integer*)frame->getVar("y"))
#define NATIVE__gt__int__           return (*(Integer*)frame->getVar("x"))>(*(Integer*)frame->getVar("y"))
#define NATIVE__le__int__           return (*(Integer*)frame->getVar("x"))<=(*(Integer*)frame->getVar("y"))
#define NATIVE__ge__int__           return (*(Integer*)frame->getVar("x"))>=(*(Integer*)frame->getVar("y"))
#define NATIVE__eq__int__           return (*((Integer*)frame->getVar("x")))==(*((Integer*)frame->getVar("y")))
#define NATIVE__ne__int__           return (*((Integer*)frame->getVar("x")))!=(*((Integer*)frame->getVar("y")))
#define NATIVE__toint__str__        return (*((String*)frame->getVar("x"))).toInt();
#define NATIVE__add__str__          return (*((String*)frame->getVar("x")))+(*((String*)frame->getVar("y")))
#define NATIVE__lmul__str__         std::stringstream ss; \
                                    for(int i = 0; i<((Integer*)frame->getVar("y"))->value; i++) \
                                        ss << ((String*)frame->getVar("x"))->value; \
                                    String* s = new String(ss.str());\
                                    return s
#define NATIVE__rmul__str__         std::stringstream ss; \
                                    for(int i = 0; i<((Integer*)frame->getVar("x"))->value; i++) \
                                        ss << ((String*)frame->getVar("y"))->value; \
                                    String* s = new String(ss.str());\
                                    return s
#define NATIVE__lt__str__           return (*((String*)frame->getVar("x")))<(*((String*)frame->getVar("y")))
#define NATIVE__gt__str__           return (*((String*)frame->getVar("x")))>(*((String*)frame->getVar("y")))
#define NATIVE__le__str__           return (*((String*)frame->getVar("x")))<=(*((String*)frame->getVar("y")))
#define NATIVE__ge__str__           return (*((String*)frame->getVar("x")))>=(*((String*)frame->getVar("y"))) 
#define NATIVE__eq__str__           return (*((String*)frame->getVar("x")))==(*((String*)frame->getVar("y")))
#define NATIVE__ne__str__           return (*((String*)frame->getVar("x")))!=(*((String*)frame->getVar("y")))
#define NATIVE__getitem__str__      return (*((String*)frame->getVar("S"))).getIndex((*((Integer*)frame->getVar("k"))))
#define NATIVE__getslice__str__     return (*((String*)frame->getVar("S"))).getSlice((*((Integer*)frame->getVar("L"))), (*((Integer*)frame->getVar("U"))))
#define NATIVE__len__str__          return (*((String*)frame->getVar("x"))).len()
#define NATIVE__tostr__             std::stringstream ss; \
                                    ss << ((String*)(frame->getVar("x")))->value; \
                                    String* s = new String(ss.str());\
                                    return s
#define NATIVE__getitem__list__     //return ((List*)frame->getVar("S"))->getItem(*((Integer*)frame->getVar("k")))
#define NATIVE__getslice__list__    //return ((List*)frame->getVar("S"))->getSlice(*((Integer*)frame->getVar("k")))
#define NATIVE__len__list__         //return ((List*)frame->getVar("S"))->len()
#define NATIVE__argv__
#define NATIVE__open1__
#define NATIVE__open2__
#define NATIVE__close__
#define NATIVE__standard_file__
#define NATIVE__readline__
#define NATIVE__read__
#define NATIVE__getitem__dict__     //return (((Dict*)frame->getVar("D"))->getItem(*(frame->getVar("x")))
#define NATIVE__len__dict__         //return (((Dict*)frame->getVar("D"))->len()
#define NATIVE__contains__dict__    //return (((Dict*)frame->getVar("D"))->contains(*(frame->getVar("x")))
#define NATIVE__notcontains__dict__ //return (((Dict*)frame->getVar("D"))->notContains(*(frame->getVar("x")))
#define NATIVE__is__                //return new Bool(frame->getVar("x") == frame->getVar("y"))
#define NATIVE__isnot__             //return new Bool(frame->getVar("x") != frame->getVar("y"))

