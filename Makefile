CXX := g++
CXXFLAGS := -g -Wall --std=c++11
VALGRIND := valgrind --tool=memcheck --leak-check=yes

all: llrec-test

stack: stack_test

heap: heap_test

#-----------------------------------------------------
# ADD target(s) to build your llrec-test executable
#-----------------------------------------------------
llrec-test: llrec-test.o 
	$(CXX) $(CXXFLAGS) -o $@ llrec-test.cpp llrec.cpp llrec.h 

llrec-test.o: llrec-test.cpp llrec.cpp llrec.h
	$(CXX) $(CXXFLAGS) -o $@ -c llrec-test.cpp 

stack_test: stack.o
	$(CXX) $(CXXFLAGS) -o $@ stack.h stack_test.cpp

stack.o: stack_test.cpp stack.h
	$(CXX) $(CXXFLAGS) -o $@ -c stack.h


heap_test: heap.o
	$(CXX) $(CXXFLAGS) -o $@ heap.h heap_test.cpp

heap.o: heap_test.cpp heap.h
	$(CXX) $(CXXFLAGS) -o $@ -c heap.h

clean:
	rm -f *.o rh llrec-test *~

.PHONY: clean 