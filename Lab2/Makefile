     #@author: Ronan Timmons
       #@date: 02/10/17
    #@version: 0.9
#@lastUpdated: 10/10/17

EXE = rendezvousexe
CC = g++
CFLAGS = -std=c++11 -pthread -I.

#each .o file needs a cpp file of same name
%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

ALL :Rendezvous.o Semaphore.o
	$(CC) $(CFLAGS) Rendezvous.cpp Semaphore.cpp -o $(EXE)

#delete all .o files
CLEAN:
	rm*.o
