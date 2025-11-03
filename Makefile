# =====================================================
# CMP2003 Data Structures – Lab 04
# Linked List Implementation
# Multi-Target Makefile for Function-Based Testing
# =====================================================

CXX = g++
CXXFLAGS = -Wall --std=c++17

# -----------------------------------------------------
# Default target: runs all tests
# -----------------------------------------------------
all: test_linkedlist
	./test_linkedlist

# -----------------------------------------------------
# Build test binary (student + Catch2)
# -----------------------------------------------------
test_linkedlist: test_linkedlist.o MainProgram.o
	$(CXX) $(CXXFLAGS) -Dmain=student_main test_linkedlist.o MainProgram.o -o test_linkedlist

test_linkedlist.o: test_linkedlist.cpp
	$(CXX) $(CXXFLAGS) -c test_linkedlist.cpp -o test_linkedlist.o

MainProgram.o: MainProgram.cpp
	$(CXX) $(CXXFLAGS) -c MainProgram.cpp -o MainProgram.o

# -----------------------------------------------------
# Individual test targets for autograder
# -----------------------------------------------------
destroylist: test_linkedlist
	./test_linkedlist "[destroyList]"

search: test_linkedlist
	./test_linkedlist "[search]"

insertfirst: test_linkedlist
	./test_linkedlist "[insertFirst]"

insertlast: test_linkedlist
	./test_linkedlist "[insertLast]"

# -----------------------------------------------------
# Cleanup
# -----------------------------------------------------
clean:
	rm -f *.o test_linkedlist
