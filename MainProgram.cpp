/************************************************************
 CMP2003 Data Structures
 Lab 04 – Linked List Implementation (Student Version)
 
 Instructions:
 - Write the struct definition of nodeType yourself.
 - Complete the TODO parts below.
 - deleteNode(), copy constructor, and destructor 
   are already implemented for you.
************************************************************/

#include <iostream>
#include <cassert>
using namespace std;

// =======================================
// (i) Struct Definition of nodeType
// =======================================
// TODO: Define struct nodeType here
// It must contain:
// - a data field (info) of template type
// - a pointer (link) to the next node
// Example:
// template <class Type>
// struct nodeType {
//
//
// };

// =======================================
// (ii) LinkedListType Class Declaration
// =======================================

template <class Type>
class LinkedListType {
protected:
    int count;
    nodeType<Type>* first;
    nodeType<Type>* last;

public:
    LinkedListType();  // default constructor
    LinkedListType(const LinkedListType<Type>& otherList); // copy constructor (given)
    ~LinkedListType(); // destructor (given)

    void initializeList();    
    bool isEmptyList() const;
    void print() const;
    int length() const;
    void destroyList();
    Type front() const;
    Type back() const;
    bool search(const Type& searchItem) const;
    void insertFirst(const Type& newItem);
    void insertLast(const Type& newItem);
    void deleteNode(const Type& deleteItem); // already implemented

private:
    void copyList(const LinkedListType<Type>& otherList);
};

// =======================================
// (iii) Function Definitions (Skeletons)
// =======================================

template <class Type>
LinkedListType<Type>::LinkedListType() {
    initializeList();
}

// =======================================
// Copy Constructor (Given)
// =======================================
template <class Type>
LinkedListType<Type>::LinkedListType(const LinkedListType<Type>& otherList) {
    first = last = nullptr;
    count = 0;
    copyList(otherList);
}

// =======================================
// Destructor (Given)
// =======================================
template <class Type>
LinkedListType<Type>::~LinkedListType() {
    destroyList();
}

// =======================================
// initializeList()
// =======================================
template <class Type>
void LinkedListType<Type>::initializeList() {
    first = nullptr;
    last = nullptr;
    count = 0;
}

// =======================================
// isEmptyList()
// =======================================
template <class Type>
bool LinkedListType<Type>::isEmptyList() const {
    return (first == nullptr);
}

// =======================================
// print()
// =======================================
template <class Type>
void LinkedListType<Type>::print() const {
    // TODO: Traverse the list and print each node's info
}

// =======================================
// length()
// =======================================
template <class Type>
int LinkedListType<Type>::length() const {
    // TODO: Return count
    return 0;
}

// =======================================
// destroyList()
// =======================================
template <class Type>
void LinkedListType<Type>::destroyList() {
    nodeType<Type>* temp;
    while (first != nullptr) {
        temp = first;
        first = first->link;
        delete temp;
    }
    last = nullptr;
    count = 0;
}

// =======================================
// front()
// =======================================
template <class Type>
Type LinkedListType<Type>::front() const {
    // TODO: Return first->info if list not empty
    return Type();
}

// =======================================
// back()
// =======================================
template <class Type>
Type LinkedListType<Type>::back() const {
    // TODO: Return last->info if list not empty
    return Type();
}

// =======================================
// search()
// =======================================
template <class Type>
bool LinkedListType<Type>::search(const Type& searchItem) const {
    // TODO: Traverse list, return true if found
    return false;
}

// =======================================
// insertFirst()
// =======================================
template <class Type>
void LinkedListType<Type>::insertFirst(const Type& newItem) {
    // TODO: Insert newItem at the beginning
}

// =======================================
// insertLast()
// =======================================
template <class Type>
void LinkedListType<Type>::insertLast(const Type& newItem) {
    // TODO: Insert newItem at the end
}

// =======================================
// deleteNode() (Given)
// =======================================
template <class Type>
void LinkedListType<Type>::deleteNode(const Type& deleteItem) {
    if (first == nullptr) {
        cout << "Cannot delete from an empty list." << endl;
        return;
    }

    nodeType<Type>* current;
    nodeType<Type>* trailCurrent;
    bool found = false;

    if (first->info == deleteItem) {
        current = first;
        first = first->link;
        if (first == nullptr)
            last = nullptr;
        delete current;
        count--;
        found = true;
    } else {
        trailCurrent = first;
        current = first->link;

        while (current != nullptr && !found) {
            if (current->info != deleteItem) {
                trailCurrent = current;
                current = current->link;
            } else {
                found = true;
            }
        }

        if (found) {
            trailCurrent->link = current->link;
            if (current == last)
                last = trailCurrent;
            delete current;
            count--;
        } else {
            cout << "Item not found in the list." << endl;
        }
    }
}

// =======================================
// copyList() (Given helper)
// =======================================
template <class Type>
void LinkedListType<Type>::copyList(const LinkedListType<Type>& otherList) {
    if (this == &otherList)
        return;

    destroyList();

    if (otherList.first == nullptr) {
        first = last = nullptr;
        count = 0;
        return;
    }

    nodeType<Type>* current = otherList.first;

    first = new nodeType<Type>;
    first->info = current->info;
    first->link = nullptr;
    last = first;
    current = current->link;

    while (current != nullptr) {
        nodeType<Type>* newNode = new nodeType<Type>;
        newNode->info = current->info;
        newNode->link = nullptr;
        last->link = newNode;
        last = newNode;
        current = current->link;
    }

    count = otherList.count;
}

// =======================================
// Main Function (for manual testing only)
// =======================================
#ifndef CATCH_TESTING
int main() {
    LinkedListType<int> list;

    list.insertLast(10);
    list.insertLast(20);
    list.insertLast(30);

    cout << "List elements: ";
    list.print();
    cout << endl;

    cout << "Length: " << list.length() << endl;
    cout << "Front: " << list.front() << ", Back: " << list.back() << endl;

    cout << "Searching 20: " << (list.search(20) ? "Found" : "Not found") << endl;

    list.deleteNode(20);
    cout << "After deleting 20: ";
    list.print();
    cout << endl;

    return 0;
}
#endif
