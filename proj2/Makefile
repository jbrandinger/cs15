#
# Makefile for Six Degrees
#
# Project 2 (fall 2020)
#
# STUDENT TODO: Add any testing files before running the provide target
# 

CXX      = clang++
CXXFLAGS = -g3 -Wall -Wextra -std=c++11 
INCLUDES = $(shell echo *.h)

SixDegrees: main.o SixDegrees.o CollabGraph.o Artist.o
	${CXX} -o $@ $^

unit_test: unit_test_driver.o CollabGraph.o Artist.o
	${CXX} $(CXXFLAGS) $^

%.o: %.cpp ${INCLUDES}
	${CXX} ${CXXFLAGS} -c $<

clean:
	rm -rf SixDegrees *.o *.dSYM

provide:
	provide comp15 proj2phase2 main.cpp SixDegrees.cpp SixDegrees.h \
			CollabGraph.cpp CollabGraph.h unit_tests.h Makefile README \
			artists.txt commands.txt dataFile.txt