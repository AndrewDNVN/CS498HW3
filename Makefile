#! /usr/bin/make -f

CXX=g++ -Og -g --std=c++17

EXECUTABLES=run-tests main

all: $(EXECUTABLES)

clean:
	-rm *.o tests/*.o $(EXECUTABLES)

run-tests: tests/test.o GOOD-reveresed.o
	$(CXX) -o $@ $^

main: GOOD-reveresed.o main.o
	$(CXX) -o $@ $^

%.o : %.cc
	$(CXX) -c -o $@ $<