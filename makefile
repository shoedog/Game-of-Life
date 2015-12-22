
CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g


OBJS = world.o ex1.o cells.o

SRCS = world.cpp cells.cpp ex1.cpp 

HEADERS = world.hpp cells.hpp

PROGS = ex1

#all: ex1

ex_1: ${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} -o ex1

ex1.o: ex1.cpp world.hpp
	${CXX} ${CXXFLAGS} -c ex1.cpp

cells.o: cells.hpp cells.cpp world.hpp
	${CXX} ${CXXFLAGS} -c cells.cpp

world.o: world.hpp world.cpp
	${CXX} ${CXXFLAGS} -c world.cpp

#${OBJS}: ${SRCS}
#	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean: 
	rm -f ex1 *.o *~

