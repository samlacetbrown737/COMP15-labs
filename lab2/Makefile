#
#  Comp 15: Data Structures
#  Tufts University
#  Makefile for Lab 2
#
#  Makefile for planet-driver, LinkedList and Planet
#

CXX      = clang++
CXXFLAGS = -Wall -Wextra -g -std=c++11
LDFlagS  = -g


#planet-driver: planet-driver.o Planet.o LinkedList.o
#	$(CXX) -o planet-driver planet-driver.o Planet.o LinkedList.o

zip-driver: zip-driver.o Zip.o LinkedList.o
	$(CXX) -o zip-driver zip-driver.o Zip.o LinkedList.o

#
# Only listing dependencies here
# make has a default rule that knows how to build a .o
# file from a .cpp file using $(CXX) and $(CXXFLAGS)
#
#planet-driver.o:  planet-driver.cpp LinkedList.h
zip-driver.o:  zip-driver.cpp LinkedList.h
LinkedList.o:     LinkedList.cpp LinkedList.h Zip.h
#Planet.o:         Planet.cpp Planet.h
Zip.o:         Zip.cpp Zip.h


clean:
	rm -f *.o core* *~ zip-driver
