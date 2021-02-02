CC = g++
CFLAGS =
CXXFLAGS = -Wall -0 -g
INCLUDE = -I ./include
TARGET = libmyadd.a
LIBPATH = ./lib/

vpath %.h ./include
vpath %.cpp ./src

OBJS = myadd.o
SRCS = myadd.cpp

$(OBJS):$(SRCS)
	$(CC) $(CFLAGS) $(INCLUDE) -c $^

all: $(OBJS)
	ar rcs $(TARGET) $^
	mv $(TARGET) $(LIBPATH)

clear:
	rm -f *.o
	rm -f $(LIBPATH)*






