     #@author: Ronan Timmons
       #@date: 02/10/17
    #@version: 0.9
#@lastUpdated: 10/10/17

EXE = mutualexe
CC = g++
CFLAGS = -std=c++11 -pthread -I.

DEBUG: DEBUGFLAGS = -g -O0
DEBUG: ALL
#each .o file needs a cpp file of same name
%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS) $(DEBUGFLAGS)

ALL :Mutual.o Semaphore.o
	$(CC) $(CFLAGS) Mutual.cpp Semaphore.cpp -o $(EXE) $(DEBUGFLAGS)

#delete all .o files
CLEAN:
	rm*.o    
