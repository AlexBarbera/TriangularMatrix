PROJECT_ROOT = $(dir $(abspath $(lastword $(MAKEFILE_LIST))))

all: Triangular2DMatrix
	g++ -o test -std=c++11 t.o
	
Triangular2DMatrix:
	g++ -std=c++11 -c -ot.o Triangular2DMatrix.cpp

clean:
	rm *.o