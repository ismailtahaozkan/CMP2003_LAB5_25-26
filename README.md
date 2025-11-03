# CMP2003 Data Structures
## Lab 04 – Linked Lists Implementation (Student Version)

### 🎯 Objective
To implement and understand the **core logic of a singly linked list** including traversal, insertion, searching, and accessing front/back elements.

Students will complete the given skeleton by filling in the missing `struct nodeType` definition and TODO parts of the core member functions.  
The `deleteNode()`, copy constructor, and destructor are already implemented for guidance.

---

### 🧩 Task Overview

#### (i) Write the struct `nodeType`
Define a `struct` named `nodeType` that includes:
- A data field `info` of template type `Type`  
- A pointer `link` that points to the next node in the list

Example:
```cpp
template <class Type>
struct nodeType {
    Type info;
    nodeType<Type>* link;
};
```

---

#### (ii) Implement constructors for `LinkedListType`
- **Default constructor**: initializes the list to empty  
- **Copy constructor**: already provided (deep copy logic given)

---

#### (iii) Implement the following member functions

| Function | Description |
|-----------|-------------|
| **initializeList()** | Initializes the list to empty. <br> *Postcondition:* `first = NULL; last = NULL; count = 0;` |
| **isEmptyList()** | Returns `true` if list is empty, otherwise `false`. |
| **print()** | Outputs data contained in each node. |
| **length()** | Returns the number of nodes. |
| **destroyList()** | Deletes all nodes from the list.<br> *Postcondition:* `first = NULL; last = NULL; count = 0;` |
| **front()** | Returns the first element.<br> *If list is empty → terminate program.* |
| **back()** | Returns the last element.<br> *If list is empty → terminate program.* |
| **search(const Type& searchItem)** | Returns `true` if `searchItem` is found, otherwise `false`. |
| **insertFirst(const Type& newItem)** | Inserts `newItem` at the beginning. |
| **insertLast(const Type& newItem)** | Inserts `newItem` at the end. |
| **deleteNode(const Type& deleteItem)** | Deletes the node containing `deleteItem` (already implemented). |

---

### 💡 Hints
- Use `new` and `delete` carefully to manage memory.
- Always update `first`, `last`, and `count` correctly.
- Traverse with a temporary pointer like `nodeType<Type>* current = first;`.
- Always check for an empty list before accessing elements.

---

### 🧱 Expected File
`MainProgram.cpp`

---

### 🧰 Starter Skeleton
Your `MainProgram.cpp` file should follow this structure:
```cpp
#include <iostream>
#include <cassert>
using namespace std;

// TODO: Define struct nodeType here

template <class Type>
class LinkedListType {
    // Class definition with given and missing functions
};

// TODO: Complete the function bodies marked as TODO

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
```

---

### 🧪 Testing
If using Catch2 autograder, protect your main with:
```cpp
#ifndef CATCH_TESTING
int main() { ... }
#endif
```
and create a separate test file like `test_linkedlist.cpp`.

---

### 🧾 Submission
- Submit your **MainProgram.cpp** to GitHub Classroom.
- Ensure successful compilation.
- Your output should match the expected test results.

---

### 🕒 Time Expectation
Focus on completing:
- `struct nodeType`
- `insertFirst`, `insertLast`, `print`, `search`, `front`, and `back`
You do **not** need to modify the provided destructor, copy constructor, or deleteNode logic.
