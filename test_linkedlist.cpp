#define CATCH_CONFIG_MAIN
#include "catch_amalgamated.hpp"
#include <iostream>
#include <sstream>
#include "MainProgram.cpp" // student code

// ======================================================
// CMP2003 Data Structures - Lab 04 Linked List
// Autograding Catch2 Test File
// Each function test worth 1 point
// ======================================================

// Helper: capture printed output
template <typename T>
std::string getListOutput(LinkedListType<T>& list) {
    std::ostringstream oss;
    // Redirect cout temporarily
    std::streambuf* oldBuf = std::cout.rdbuf(oss.rdbuf());
    list.print();
    std::cout.rdbuf(oldBuf);
    return oss.str();
}

// ======================================================
// TEST 1: destroyList()
// ======================================================
TEST_CASE("destroyList() resets the list", "[destroyList]") {
    LinkedListType<int> list;
    list.insertLast(10);
    list.insertLast(20);
    list.insertLast(30);

    REQUIRE(list.length() == 3);

    list.destroyList();

    REQUIRE(list.length() == 0);
    REQUIRE(list.isEmptyList() == true);
}

// ======================================================
// TEST 2: search()
// ======================================================
TEST_CASE("search() finds existing and missing elements", "[search]") {
    LinkedListType<int> list;
    list.insertLast(5);
    list.insertLast(10);
    list.insertLast(15);
    list.insertLast(20);

    REQUIRE(list.search(10) == true);
    REQUIRE(list.search(5) == true);
    REQUIRE(list.search(25) == false);
    REQUIRE(list.search(0) == false);
}

// ======================================================
// TEST 3: insertFirst()
// ======================================================
TEST_CASE("insertFirst() correctly inserts elements at beginning", "[insertFirst]") {
    LinkedListType<int> list;
    list.insertFirst(100);
    list.insertFirst(200);
    list.insertFirst(300);

    REQUIRE(list.length() == 3);

    REQUIRE(list.front() == 300);
    REQUIRE(list.back() == 100);

    std::string output = getListOutput(list);
    REQUIRE(output == "300 200 100 ");
}

// ======================================================
// TEST 4: insertLast()
// ======================================================
TEST_CASE("insertLast() correctly inserts elements at the end", "[insertLast]") {
    LinkedListType<int> list;
    list.insertLast(10);
    list.insertLast(20);
    list.insertLast(30);

    REQUIRE(list.length() == 3);
    REQUIRE(list.front() == 10);
    REQUIRE(list.back() == 30);

    std::string output = getListOutput(list);
    REQUIRE(output == "10 20 30 ");
}
