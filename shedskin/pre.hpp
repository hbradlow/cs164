#ifndef __PRE_HPP
#define __PRE_HPP

using namespace __shedskin__;
namespace __pre__ {

extern str *const_0, *const_1, *const_10, *const_11, *const_12, *const_13, *const_14, *const_15, *const_16, *const_17, *const_18, *const_19, *const_2, *const_20, *const_21, *const_22, *const_23, *const_24, *const_25, *const_26, *const_27, *const_28, *const_29, *const_3, *const_4, *const_5, *const_6, *const_7, *const_8, *const_9;


typedef void *(*lambda3)(__re__::match_object *);
typedef str *(*lambda4)(__re__::match_object *);
typedef str *(*lambda0)(__re__::match_object *);
typedef str *(*lambda5)(__re__::match_object *);
typedef void *(*lambda2)(__re__::match_object *);
typedef str *(*lambda1)(__re__::match_object *);

extern __ss_int indent_len;
extern str *DEDENT, *INDENT, *__name__, *arg;
extern file *f;


pyiter<str *> *preprocess(str *infile);
str *process(str *in_file);

} // module namespace
#endif
