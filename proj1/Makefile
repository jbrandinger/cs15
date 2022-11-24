###
### Makefile for CalcYouLater Project
### CalcYouLater is an RPN calculator
###
### Author: Joel Brandinger

CXX      = clang++
CXXFLAGS = -g3 -Wall -Wextra -Wpedantic -Wshadow
LDFLAGS  = -g3 

# CalcYouLater rule 
CalcYouLater: main.o RPNCalc.o parser.o DatumStack.o Datum.o
	$(CXX) $(CXXFLAGS) -o CalcYouLater main.o RPNCalc.o parser.o \
						got_int.o DatumStack.o Datum.o
						
# This rule builds main.o
main.o: main.cpp RPNCalc.h DatumStack.h Datum.h parser.o got_int.o
	$(CXX) $(CXXFLAGS) -c main.cpp

#thus rule builds RPNCalc.o	
RPNCalc.o: RPNCalc.cpp RPNCalc.h DatumStack.h Datum.h parser.o got_int.o
	$(CXX) $(CXXFLAGS) -c RPNCalc.cpp
	
# This rule builds parser.o	
parser.o: parser.cpp
	$(CXX) $(CXXFLAGS) -c parser.cpp
	
# This rule builds got_int.o
got_int.o: got_int.cpp
	$(CXX) $(CXXFLAGS) -c got_int.cpp
		
# This rule builds DatumStack.o
DatumStack.o: DatumStack.cpp DatumStack.h Datum.h 
	$(CXX) $(CXXFLAGS) -c DatumStack.cpp
	
# The below rule will be used by unit_test.
unit_test: unit_test_driver.o DatumStack.o Datum.o RPNCalc.o
	$(CXX) $(CXXFLAGS) $^

provide:
	provide comp15 proj1_calcyoulater DatumStack.h DatumStack.cpp parser.cpp \
						RPNCalc.h RPNCalc.cpp main.cpp test_file.txt \
						unit_tests.h README Makefile fact.cyl fib.cyl \
						got_int.cpp
											
## Here is a rule for compiling .cyl files for use in your testing
%.cylc:  %.cyl
	./cylc $^
	
# remove executables, object code, and temporary files from the current folder 
# -- the executable created by unit_test is called a.out
clean: 
	rm *.o *~ a.out
