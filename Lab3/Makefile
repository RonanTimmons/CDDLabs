#@author Ronan Timmons
#@date 02/10/17
#@version 1.0
#See http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/ for info


EXE = sigexe
CC = g++
CFLAGS = -std=c++11 -pthread

CFILES = signal.cpp Semaphore.cpp
HFILES = Semaphore.h

ALL: $(CFILES) $(HFILES)
	$(CC) $(CFLAGS) *.cpp -o sigexe

#delete all .0 in project folder
CLEAN:
	rm *.o
