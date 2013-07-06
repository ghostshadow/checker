CXX=g++
CXXFLAGS=-std=c++11 -g
LFLAGS=

LIBS=

checker: main.cpp checker.cpp checker.hpp
	${CXX} ${CXXFLAGS} ${LFlAGS} ${LIBS} main.cpp checker.cpp -o checker

.PHONY: clean
clean:
	rm checker


