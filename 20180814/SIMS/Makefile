SOURS=$(wildcard *.cc)
OBJS=$(SOURS:%.cc=%.o)
TAR="main"
CC=g++
CFLAGS=-Wall  

CREAT:$(OBJS)
	g++ $(OBJS) -o $(TAR) 
clean:
	rm $(TAR) $(OBJS)
