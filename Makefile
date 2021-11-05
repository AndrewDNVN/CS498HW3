#! /usr/bin/make -f

CXX=g++ -Wall --std=c++17

all: test_reverse

.PHONY: run
run: test_reverse
	./test_reverse

test_reverse: test_reverse.o
	$(CXX) -o $@ $^

%.o : %.cpp
	$(CXX) -c -o $@ $<



clean: 
	rm *.o test_reverse