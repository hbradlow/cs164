SHEDSKIN_LIBDIR=/Library/Python/2.7/site-packages/shedskin/lib
CC=g++
CCFLAGS=-O2 -Wno-deprecated $(CPPFLAGS) -I. -I${SHEDSKIN_LIBDIR} -I/usr/local/include -I/opt/local/include
LFLAGS=-lgc -lpcre $(LDFLAGS) -L/opt/local/lib -L/usr/local/lib

CPPFILES=pre.cpp \
	${SHEDSKIN_LIBDIR}/sys.cpp \
	${SHEDSKIN_LIBDIR}/re.cpp \
	${SHEDSKIN_LIBDIR}/builtin.cpp

HPPFILES=pre.hpp \
	${SHEDSKIN_LIBDIR}/sys.hpp \
	${SHEDSKIN_LIBDIR}/re.hpp \
	${SHEDSKIN_LIBDIR}/builtin.hpp

all:	pre

pre:	$(CPPFILES) $(HPPFILES)
	$(CC)  $(CCFLAGS) $(CPPFILES) $(LFLAGS) -o pre

pre_prof:	$(CPPFILES) $(HPPFILES)
	$(CC) -pg -ggdb $(CCFLAGS) $(CPPFILES) $(LFLAGS) -o pre_prof

pre_debug:	$(CPPFILES) $(HPPFILES)
	$(CC) -g -ggdb $(CCFLAGS) $(CPPFILES) $(LFLAGS) -o pre_debug

clean:
	rm -f pre pre_prof pre_debug

.PHONY: all clean

