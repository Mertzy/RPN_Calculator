CPP = g++
CPPFLAGS = -std=c++0x -g
CXX      = g++ -std=c++11
DEBUG    = -g
CXXFLAGS = $(shell fltk-config --cxxflags ) -std=c++11 -I.
LDFLAGS  = $(shell fltk-config --ldflags )
LDSTATIC = $(shell fltk-config --ldstaticflags )
LINK     = g++-4.8
OBJS = stack.o


.o:	$@.cpp $@.h
	$(CXX) $(CXXFLAGS) -c $@.cpp

Stacktest:	Stacktest.cpp $(OBJS)
	$(CXX) $(CXXFLAGS) Stacktest.cpp $(OBJS) $(LDFLAGS) -o Stacktest

GUIYahtzee:	GUIYahtzee.cpp $(OBJS)
	$(CXX) $(CXXFLAGS) GUIYahtzee.cpp $(OBJS) $(LDFLAGS) -o GUIYahtze