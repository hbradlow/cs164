class int_0:
    def __init__(self_0::int_0):
        native "__donotcall__"
class bool_0:
    def __init__(self_1::bool_0):
        native "__donotcall__"
class str_0:
    def __init__(self_2::str_0):
        native "__donotcall__"
class range_0:
    def __init__(self_3::range_0):
        native "__donotcall__"
class file_0:
    def __init__(self_4::file_0):
        native "__donotcall__"
class list_0:
    def __init__(self_5::list_0 of [$#55]):
        native "__donotcall__"
class dict_0 of [$Key, $Value]:
    def __init__(self_6::dict_0 of [$#60, $#61]):
        native "__donotcall__"
class tuple0_0:
    def __init__(self_7::tuple0_0):
        native "__donotcall__"
class tuple1_0:
    def __init__(self_8::tuple1_0 of [$#70]):
        native "__donotcall__"
class tuple2_0 of [$T1, $T2]:
    def __init__(self_9::tuple2_0 of [$#75, $#76]):
        native "__donotcall__"
class tuple3_0 of [$T1, $T2, $T3]:
    def __init__(self_10::tuple3_0 of [$#82, $#83, $#84]):
        native "__donotcall__"
def __None_0__():
    native "__None__"
def truth_0(x_0)::bool_0:
    native "__truth__"
def __not_0__(x_1)::bool_0:
    native "__not__"
True_0::bool_0 = truth_0(1)
False_0::bool_0 = truth_0(0)
def xrange_0(low_0::int_0, high_0::int_0)::range_0:
    native "__xrange__"
def len_0(r_0::range_0)::int_0:
    native "__len__range__"
def __add_0__(x_2::int_0, y_0::int_0)::int_0:
    native "__add__int__"
def __sub_0__(x_3::int_0, y_1::int_0)::int_0:
    native "__sub__int__"
def __mul_0__(x_4::int_0, y_2::int_0)::int_0:
    native "__mul__int__"
def __floordiv_0__(x_5::int_0, y_3::int_0)::int_0:
    native "__floordiv__int__"
def __mod_0__(x_6::int_0, y_4::int_0)::int_0:
    native "__mod__int__"
def __pow_0__(x_7::int_0, y_5::int_0)::int_0:
    native "__pow__int__"
def __neg_0__(x_8::int_0)::int_0:
    native "__neg__int__"
def __pos_0__(x_9::int_0)::int_0:
    native "__pos__int__"
def __lt_0__(x_10::int_0, y_6::int_0)::bool_0:
    native "__lt__int__"
def __gt_0__(x_11::int_0, y_7::int_0)::bool_0:
    native "__gt__int__"
def __le_0__(x_12::int_0, y_8::int_0)::bool_0:
    native "__le__int__"
def __ge_0__(x_13::int_0, y_9::int_0)::bool_0:
    native "__ge__int__"
def __eq_0__(x_14::int_0, y_10::int_0)::bool_0:
    native "__eq__int__"
def __ne_0__(x_15::int_0, y_11::int_0)::bool_0:
    native "__ne__int__"
def toint_0(x_16::str_0)::int_0:
    native "__toint__str__"
def __add_1__(x_17::str_0, y_12::str_0)::str_0:
    native "__add__str__"
def __mul_1__(x_18::str_0, y_13::int_0)::str_0:
    native "__lmul__str__"
def __mul_2__(x_19::int_0, y_14::str_0)::str_0:
    native "__rmul__str__"
def __lt_1__(x_20::str_0, y_15::str_0)::bool_0:
    native "__lt__str__"
def __gt_1__(x_21::str_0, y_16::str_0)::bool_0:
    native "__gt__str__"
def __le_1__(x_22::str_0, y_17::str_0)::bool_0:
    native "__le__str__"
def __ge_1__(x_23::str_0, y_18::str_0)::bool_0:
    native "__ge__str__"
def __eq_1__(x_24::str_0, y_19::str_0)::bool_0:
    native "__eq__str__"
def __ne_1__(x_25::str_0, y_20::str_0)::bool_0:
    native "__ne__str__"
def __getitem_0__(S_0::str_0, k_0::int_0)::str_0:
    native "__getitem__str__"
def __getslice_0__(S_1::str_0, L_0::int_0, U_0::int_0)::str_0:
    native "__getslice__str__"
def len_1(S_2::str_0)::int_0:
    native "__len__str__"
def tostr_0(x_26)::str_0:
    native "__tostr__"
def __getitem_1__(S_3::list_0 of [$#184], k_1::int_0)::$a:
    native "__getitem__list__"
def __getslice_1__(S_4::list_0 of [$#188], L_1::int_0, U_1::int_0)::list_0 of [$#191]:
    native "__getslice__list__"
def len_2(S_5::list_0 of [$#194])::int_0:
    native "__len__list__"
def __argv_0__()::list_0 of [str_0]:
    native "__argv__"
def open_0(name_0::str_0)::file_0:
    native "__open1__"
def open_1(name_1::str_0, mode_0::str_0)::file_0:
    native "__open2__"
def close_0(f_0::file_0):
    native "__close__"
def __standard_file_0__(k_2::int_0):
    native "__standard_file__"
def readline_0(f_1::file_0)::str_0:
    native "__readline__"
def read_0(f_2::file_0)::str_0:
    native "__read__"
class __sys_0__:
    def __init__(self_11):
        pass
    stdin_0::file_0 = __standard_file_0__(0)
    stdout_0::file_0 = __standard_file_0__(1)
    stderr_0::file_0 = __standard_file_0__(2)
    argv_0::list_0 of [str_0] = __argv_0__()
sys_0::__sys_0__ = __sys_0__()
def __getitem_2__(D_0::dict_0 of [int_0, $#221], x_27::int_0)::$b:
    native "__getitem__dict__"
def __getitem_3__(D_1::dict_0 of [bool_0, $#225], x_28::bool_0)::$b:
    native "__getitem__dict__"
def __getitem_4__(D_2::dict_0 of [str_0, $#229], x_29::str_0)::$b:
    native "__getitem__dict__"
def len_3(D_3::dict_0 of [int_0, $#233])::int_0:
    native "__len__dict__"
def len_4(D_4::dict_0 of [bool_0, $#236])::int_0:
    native "__len__dict__"
def len_5(D_5::dict_0 of [str_0, $#239])::int_0:
    native "__len__dict__"
def __contains_0__(x_30::int_0, D_6::dict_0 of [int_0, $#243])::bool_0:
    native "__contains__dict__"
def __contains_1__(x_31::bool_0, D_7::dict_0 of [bool_0, $#247])::bool_0:
    native "__contains__dict__"
def __contains_2__(x_32::str_0, D_8::dict_0 of [str_0, $#251])::bool_0:
    native "__contains__dict__"
def __notcontains_0__(x_33::int_0, D_9::dict_0 of [int_0, $#255])::bool_0:
    native "__notcontains__dict__"
def __notcontains_1__(x_34::bool_0, D_10::dict_0 of [bool_0, $#259])::bool_0:
    native "__notcontains__dict__"
def __notcontains_2__(x_35::str_0, D_11::dict_0 of [str_0, $#263])::bool_0:
    native "__notcontains__dict__"
def __is_0__(x_36, y_21)::bool_0:
    native "__is__"
def __isnot_0__(x_37, y_22)::bool_0:
    native "__isnot__"
def f_3(x_38):
    return x_38 - 3
def f_4(x_39):
    return "Hello, " + x_39
print f_4(3)
print f_3("world")
