# coding-interview
## Data structure
A data structure is a way to store and organize data in a computer so that it can be used efficiently.

An abstract data type <b>(ADT)</b> is the specification of a data type within some language, independent of an implementation. The interface for the ADT is defined in terms of a type and a set of operations on that type. The behavior of each operation is determined by its inputs and outputs. An ADT does not specify how the data type is implemented. These implementation details are hidden from the user of the ADT and protected from outside access, a concept referred to as encapsulation. A data structure is an implementation for an ADT. 

In simple term, ADT is a definition of data type and operation, but not the implementation.

### The five basic requirements of any ADT,
* How to <b>Access</b> (one item / all item)
* How to <b>Insert</b> (at end / at position)
* How to <b>Delete</b> (from end / from position)
* How to <b>Find</b> (if exists / what location)
* How to <b>Sort</b> (sorr in place / created sorted version)

## Operations, Time complexity, and Space Complexity:
![Time complexity, and Space Complexity](images/big_o_cheatsheet.jpg)

## List:
#### ADT:
A List is a collection of items stored at contiguous memory locations. The idea is to store multiple items of the same type together. i.e Array, string, Linked List.

* get() – Return an element from the list at any given position.
* insert() – Insert an element at any position of the list.
* remove() – Remove the first occurrence of any element from a non-empty list.
* removeAt() – Remove the element at a specified location from a non-empty list.
* replace() – Replace an element at any position by another element.
* size() – Return the number of elements in the list.
* isEmpty() – Return true if the list is empty, otherwise return false.
* isFull() – Return true if the list is full, otherwise return false.

#### Implementation:
* [Array Stack Implementation](array/array_stack_init.c)
* [Array Heap Implementation](array/array_heap_init.c)
* [Array ADT Implementation](array/array_adt_implementation.c)
* String Stack Implementation
* String Heap Implementation
* String ADT Implementation

---
**NOTE**
List always looks for contiguous memory and return the pointer if successfull. If the size is full we need to double the array and copy old array elements to new array. To overcome this problem we use <b>Linked List</br>.
---


