CXX = g++
CXXFLAGS = -std=c++11 -Wall

OBJS = main.o Graph.o TourSolver.o

project3 : ${OBJS}
	${CXX} ${CXXFLAGS} -o $@ ${OBJS}

main.o : TourSolver.h
	${CXX} ${CXXFLAGS} -c main.cpp

Graph.o : Graph.h
	${CXX} ${CXXFLAGS} -c Graph.cpp

TourSolver.o : TourSolver.h Graph.h
	${CXX} ${CXXFLAGS} -c TourSolver.cpp

clean:
	rm -f *.o
	rm -f project3