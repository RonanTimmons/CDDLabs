     #@author: Ronan Timmons
       #@date: 02/10/17
    #@version: 0.9
#@lastUpdated: 23/10/17

EXE = barrierexe
CC = g++
HFILES = Semaphore.h
CPPFILES = Barrier.cpp Semaphore.cpp
CFLAGS = -std=c++11 -pthread -Wall -I. 

DEBUG: DEBUGFLAGS = -g -O0 
DEBUG: ALL

#each .o file has dependency on a cpp file of same name
%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS) $(DEBUGFLAGS)

ALL : $(CPPFILES) $(HFILES)
	$(CC) $(CFLAGS) $(CPPFILES) -o $(EXE) $(DEBUGFLAGS)

#delete all .o files
CLEAN:
	rm*.o    
