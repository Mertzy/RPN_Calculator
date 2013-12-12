CPP = g++
CPPFLAGS = -std=c++0x -g
CXX      = g++ -std=c++11
DEBUG    = -g
CXXFLAGS = $(shell fltk-config --cxxflags ) -std=c++11 -I.
LDFLAGS  = $(shell fltk-config --ldflags )
LDSTATIC = $(shell fltk-config --ldstaticflags )
LINK     = g++-4.8
OBJS = stack.o display.o


.o:	$@.cpp $@.h
	$(CXX) $(CXXFLAGS) -c $@.cpp

Stacktest:	Stacktest.cpp $(OBJS)
	$(CXX) $(CXXFLAGS) Stacktest.cpp $(OBJS) $(LDFLAGS) -o Stacktest

CommandLineCalculator:	commandLineCalculator.cpp $(OBJS)
	$(CXX) $(CXXFLAGS) commandLineCalculator.cpp $(OBJS) $(LDFLAGS) -o commandLineCalculator

RPNCalculator:	RPNCalculator.cpp $(OBJS)
	$(CXX) $(CXXFLAGS) RPNCalculator.cpp $(OBJS) $(LDFLAGS) -o RPNCalculator