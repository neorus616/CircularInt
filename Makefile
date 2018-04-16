CXX=g++
CXXFLAGS=-std=c++11 

all: a.out
	./a.exe

a.out: CircularInt.o main.o
	$(CXX) $(CXXFLAGS) CircularInt.o main.o

CircularInt.o: CircularInt.cpp CircularInt.hpp
	$(CXX) $(CXXFLAGS) --compile CircularInt.cpp -o CircularInt.o

main.o: main.cpp CircularInt.hpp doctest.h
	$(CXX) $(CXXFLAGS) --compile main.cpp -o main.o

clean: 
	rm *.o a.exe