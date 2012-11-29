#include "runtime.h"
class str{
public:
    void* __init__(str self){
        NATIVE__donotcall__;
    }
};
class range{
public:
    void* __init__(range self){
        NATIVE__donotcall__;
    }
};
class file{
public:
    void* __init__(file self){
        NATIVE__donotcall__;
    }
};
class list{
public:
    void* __init__(list self){
        NATIVE__donotcall__;
    }
};
class tuple0{
public:
    void* __init__(tuple0 self){
        NATIVE__donotcall__;
    }
};
class tuple1{
public:
    void* __init__(tuple1 self){
        NATIVE__donotcall__;
    }
};
class tuple2{
public:
    void* __init__(tuple2 self){
        NATIVE__donotcall__;
    }
};
class tuple3{
public:
    void* __init__(tuple3 self){
        NATIVE__donotcall__;
    }
};
class __sys__{
public:
        void* __init__(void* self){
    }
};
void* __None__(){
    NATIVE__None__;
}
bool truth(int x){
    NATIVE__truth__;
}
bool __not__(void* x){
    NATIVE__not__;
}
range xrange(int low,int high){
    NATIVE__xrange__;
}
int len(range r){
    NATIVE__len__range__;
}
int __add__(int x,int y){
    NATIVE__add__int__;
}
int __sub__(int x,int y){
    NATIVE__sub__int__;
}
int __mul__(int x,int y){
    NATIVE__mul__int__;
}
int __floordiv__(int x,int y){
    NATIVE__floordiv__int__;
}
int __mod__(int x,int y){
    NATIVE__mod__int__;
}
int __pow__(int x,int y){
    NATIVE__pow__int__;
}
int __neg__(int x){
    NATIVE__neg__int__;
}
int __pos__(int x){
    NATIVE__pos__int__;
}
bool __lt__(int x,int y){
    NATIVE__lt__int__;
}
bool __gt__(int x,int y){
    NATIVE__gt__int__;
}
bool __le__(int x,int y){
    NATIVE__le__int__;
}
bool __ge__(int x,int y){
    NATIVE__ge__int__;
}
bool __eq__(int x,int y){
    NATIVE__eq__int__;
}
bool __ne__(int x,int y){
    NATIVE__ne__int__;
}
int toint(str x){
    NATIVE__toint__str__;
}
str __add__(str x,str y){
    NATIVE__add__str__;
}
str __mul__(str x,int y){
    NATIVE__lmul__str__;
}
str __mul__(int x,str y){
    NATIVE__rmul__str__;
}
bool __lt__(str x,str y){
    NATIVE__lt__str__;
}
bool __gt__(str x,str y){
    NATIVE__gt__str__;
}
bool __le__(str x,str y){
    NATIVE__le__str__;
}
bool __ge__(str x,str y){
    NATIVE__ge__str__;
}
bool __eq__(str x,str y){
    NATIVE__eq__str__;
}
bool __ne__(str x,str y){
    NATIVE__ne__str__;
}
str __getitem__(str S,int k){
    NATIVE__getitem__str__;
}
str __getslice__(str S,int L,int U){
    NATIVE__getslice__str__;
}
int len(str S){
    NATIVE__len__str__;
}
str tostr(void* x){
    NATIVE__tostr__;
}
void* __getitem__(list S,int k){
    NATIVE__getitem__list__;
}
list __getslice__(list S,int L,int U){
    NATIVE__getslice__list__;
}
int len(list S){
    NATIVE__len__list__;
}
list __argv__(){
    NATIVE__argv__;
}
file open(str name){
    NATIVE__open1__;
}
file open(str name,str mode){
    NATIVE__open2__;
}
void* close(file f){
    NATIVE__close__;
}
void* __standard_file__(int k){
    NATIVE__standard_file__;
}
str readline(file f){
    NATIVE__readline__;
}
str read(file f){
    NATIVE__read__;
}
void* __getitem__(map<int, void*> D,int x){
    NATIVE__getitem__dict__;
}
void* __getitem__(map<bool, void*> D,bool x){
    NATIVE__getitem__dict__;
}
void* __getitem__(map<str, void*> D,str x){
    NATIVE__getitem__dict__;
}
int len(map<int, void*> D){
    NATIVE__len__dict__;
}
int len(map<bool, void*> D){
    NATIVE__len__dict__;
}
int len(map<str, void*> D){
    NATIVE__len__dict__;
}
bool __contains__(int x,map<int, void*> D){
    NATIVE__contains__dict__;
}
bool __contains__(bool x,map<bool, void*> D){
    NATIVE__contains__dict__;
}
bool __contains__(str x,map<str, void*> D){
    NATIVE__contains__dict__;
}
bool __notcontains__(int x,map<int, void*> D){
    NATIVE__notcontains__dict__;
}
bool __notcontains__(bool x,map<bool, void*> D){
    NATIVE__notcontains__dict__;
}
bool __notcontains__(str x,map<str, void*> D){
    NATIVE__notcontains__dict__;
}
bool __is__(void* x,void* y){
    NATIVE__is__;
}
bool __isnot__(void* x,void* y){
    NATIVE__isnot__;
}
void* foo(int x){
    if (__eq__(x,2)) {
                cout << "true" << endl;
        cout << "also true" << endl;
}
else {
                cout << "false" << endl;
}
}
int main(int argc, char* argv[]) {
    bool True = truth(1);
    bool False = truth(0);
    __sys__* sys = new __sys__;
foo(2)}
