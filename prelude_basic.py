# The standard prelude.

# NOTE: You may want to phase this in gently, with just a portion of the
#       definitions at first, to keep the sizes of your trees under control
#       during development.

# The __init__ methods of all builtin classes call a function that causes
# a fatal error.

class int:
    pass

class bool:
    pass

class string:
    pass


