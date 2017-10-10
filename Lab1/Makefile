     #@author: Ronan Timmons
       #@date: 02/10/17
    #@version: 0.9
#@lastUpdated: 10/10/17

EXE = sigexe
CC = g++
CFLAGS = -std=c++11 -pthread -I.

#each .o file needs a cpp file of same name
%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

ALL :signal.o Semaphore.o
	$(CC) $(CFLAGS) signal.cpp Semaphore.cpp -o $(EXE)

#delete all .o files
CLEAN:
	rm*.o


