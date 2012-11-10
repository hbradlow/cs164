# Implementations of native functions.

# Use this file as a prefix to pyunparsed files.  The files must be alpha
# converted (--alpha) to avoid name clashes.


import sys

def __donotcall__(*x):
    raise RuntimeError("Call to unimplemented function.")

def __None__():
    return None

def __truth__(x):
    return bool(x)

def __not__(x):
    return not x

def __xrange__(low, high):
    return xrange(low, high)

def __len__range__(r):
    return len(range)

def __add__int__(x, y):
    return x+y

def __sub__int__(x, y):
    return x-y

def __mul__int__(x, y):
    return x*y

def __floordiv__int__(x, y):
    return x//y

def __mod__int__(x, y):
    return x%y

def __pow__int__(x, y):
    return x**y

def __neg__int__(x):
    return -x

def __pos__int__(x):
    return x

def __lt__int__(x, y):
    return x<y

def __gt__int__(x, y):
    return x>y

def __le__int__(x, y):
    return x<=y

def __ge__int__(x, y):
    return x>=y

def __eq__int__(x, y):
    return x==y

def __ne__int__(x, y):
    return x != y

def __toint__str__(x):
    return int(x)

# Type str

def __add__str__(x, y):
    return x+y

def __mul__str__(x, y):
    return x*y

def __rmul__str__(x, y):
    return x * y

def __lt__str__(x, y):
    return x<y

def __gt__str__(x, y):
    return x>y

def __le__str__(x, y):
    return x<=y

def __ge__str__(x, y):
    return x>=y

def __eq__str__(x, y):
    return x==y

def __ne__str__(x, y):
    return x!=y

def __getitem__str__(S, k):
    return S[k]

def __getslice__str__(S, L, U):
    return S[L:U]

def __len__str__(S):
    return len(S)

def __tostr__(x):
    return str(x)

# Type list

def __getitem__list__(S, k):
    return S[k]

def __getslice__list__(S, L, U):
    return S[L:U]

def __len__list__(S):
    return len(S)

def __argv__():
    return sys.argv

# Type file

def __open1__(name):
    return open(name)

def __open2__(name, mode):
    return open(name, mode)

def __close__(f):
    f.close()

def readline(f):
    return f.readline()

def read(f):
    return f.read()

def __standard_file__(k):
    return sys.stdin if k == 0 else sys.stdout if k == 1 else sys.stderr

# Type dict

def __getitem__dict__(D, x):
    return D[x]

def __len__dict__(D):
    return len(D)

# Backwards from regular Python
def __contains__dict__(x, D):
    return x in D

# Backwards from regular Python
def __notcontains__dict__(x, D):
    return x not in D


# General

def __is__(x, y):
    return x is y

def __isnot__(x, y):
    return x is not y
class int_0:
    def __init__(self_0):
        return __donotcall__(self_0)
class bool_0:
    def __init__(self_1):
        return __donotcall__(self_1)
class str_0:
    def __init__(self_2):
        return __donotcall__(self_2)
class range_0:
    def __init__(self_3):
        return __donotcall__(self_3)
class file_0:
    def __init__(self_4):
        return __donotcall__(self_4)
class list_0:
    def __init__(self_5):
        return __donotcall__(self_5)
class dict_0:
    def __init__(self_6):
        return __donotcall__(self_6)
class tuple0_0:
    def __init__(self_7):
        return __donotcall__(self_7)
class tuple1_0:
    def __init__(self_8):
        return __donotcall__(self_8)
class tuple2_0:
    def __init__(self_9):
        return __donotcall__(self_9)
class tuple3_0:
    def __init__(self_10):
        return __donotcall__(self_10)
def truth_0(x_0):
    return __truth__(x_0)
def __not_0__(x_1):
    return __not__(x_1)
True_0 = truth_0(1)
False_0 = truth_0(0)
def xrange_0(low_0, high_0):
    return __xrange__(low_0, high_0)
def len_0(r_0):
    return __len__range__(r_0)
def __add_0__(x_2, y_0):
    return __add__int__(x_2, y_0)
def __sub_0__(x_3, y_1):
    return __sub__int__(x_3, y_1)
def __mul_0__(x_4, y_2):
    return __mul__int__(x_4, y_2)
def __floordiv_0__(x_5, y_3):
    return __floordiv__int__(x_5, y_3)
def __mod_0__(x_6, y_4):
    return __mod__int__(x_6, y_4)
def __pow_0__(x_7, y_5):
    return __pow__int__(x_7, y_5)
def __neg_0__(x_8):
    return __neg__int__(x_8)
def __pos_0__(x_9):
    return __pos__int__(x_9)
def __lt_0__(x_10, y_6):
    return __lt__int__(x_10, y_6)
def __gt_0__(x_11, y_7):
    return __gt__int__(x_11, y_7)
def __le_0__(x_12, y_8):
    return __le__int__(x_12, y_8)
def __ge_0__(x_13, y_9):
    return __ge__int__(x_13, y_9)
def __eq_0__(x_14, y_10):
    return __eq__int__(x_14, y_10)
def __ne_0__(x_15, y_11):
    return __ne__int__(x_15, y_11)
def toint_0(x_16):
    return __toint__str__(x_16)
def __getitem_0__(S_0, k_0):
    return __getitem__list__(S_0, k_0)
def __getslice_0__(S_1, L_0, U_0):
    return __getslice__list__(S_1, L_0, U_0)
def len_1(S_2):
    return __len__list__(S_2)
def __argv_0__():
    return __argv__()
def __standard_file_0__(x_17):
    return __standard_file__(x_17)
class __sys_0__:
    def __init__(self_11):
        pass
    stdin_0 = __standard_file_0__(0)
    stdout_0 = __standard_file_0__(1)
    stderr_0 = __standard_file_0__(2)
    argv_0 = __argv_0__()
sys_0 = __sys_0__()
def __None_0__():
    return __None__()
def open_0(name_0):
    return __open1__(name_0)
def open_1(name_1, mode_0):
    return __open2__(name_1, mode_0)
def close_0(f_0):
    return __close__(f_0)
if True_0:
    a_0 = 123
    if True_0:
        b_0 = a_0
    else:
        pass
else:
    pass
