
CC = g++
CFLAGS = -g -I

RM = rm 
RMFLAGS = -r -f

LIBS = -lm

SRCS_KMST = ./src/MST.cpp
SRCS_BAH = ./src/bahubali.cpp

INCLUDES = ./include/

all:   clean MST bahubali

clean:	
	$(RM) $(RMFLAGS) ./bin/*
MST:	$(SRCS_KMST)
	$(CC) $(CFLAGS) $(INCLUDES) $(SRCS_KMST) -o ./bin/MST $(LIBS)
bahubali:	$(SRCS_BAH)
	$(CC) $(CFLAGS) $(INCLUDES) $(SRCS_BAH) -o ./bin/bahubali $(LIBS)