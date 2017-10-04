#Joseph Kehoe 13/9/2017
#Second improved Makefile
#Used to contain commands to compile projects
#Equivalent(?) to a project file in VStudio -- only better!
#See http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/ for info.


EXE = sigexe
CC = g++
CFLAGS = -std=c++11 -pthread

CFILES = signal.cpp Semaphore.cpp
HFILES = Semaphore.h

ALL: $(CFILES) $(HFILES)
	$(CC) $(CFLAGS) *.cpp -o sigexe
