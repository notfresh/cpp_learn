CC      = gcc
CXXFLAGS= -Wall -O -g
INCLUDE = -I ../test_make_lib/include

TARGET  = main

LIBPATH = -L ../test_make_lib/lib
LIBVAR  = -lmyadd

vpath %.h ../test_make_lib/include

OBJS    = main.o
SRCS    = main.cpp

$(OBJS):$(SRCS)
	$(CC) $(CXXFLAGS) $(INCLUDE) -c $^

all:$(OBJS)
# 	cd ./test_make_lib && make all
	$(CC) $(CXXFLAGS) $(INCLUDE) -o main  $(OBJS) $(LIBPATH) $(LIBVAR) -lstdc++

clear:
	rm -f *.o
	rm -f $(TARGET)
