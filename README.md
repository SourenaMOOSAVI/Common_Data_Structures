# Some common data structures to know
A gentle introduction to data structures and their properties along with the implementation of some data structures such as vector, array and linked list.

## Definitions
### What is data?
The quantities, characters, or symbols on which operations are performed by a computer, which may be stored and transmitted in the form of electrical signals and recorded on magnetic, optical, or mechanical recording media.

### Data structure
A data structure is a systematic way to organize data on a computer so that it can be used efficiently. A data structure is not only used for organizing the data. It is also used for processing, retrieving, and storing data. 

Data Structures can be Linear or Non-Linear. In linear Data Structures elements are arranged sequentially or linearly, where each element is attached to its previous and next adjacent elements. In non-linear data structures data elements are not placed sequentially or linearly. 

Linear Data Structures in turn are divided in two subgroups:
* Static Data Structures: Static data structure has a fixed memory size. It is easier to access the elements in a static data structure. An example of this data structure is an array.

 and 

* Dynamic Data Structures: In dynamic data structure, the size is not fixed. An example of this data structure is Linked List.

## Popular types of Data Structures
There exists numerous data structures that are used to organize and process data, some of the most popular ones are the followings:
* Array

An array is a collection of items stored at contiguous memory locations. The idea is to store multiple items of the same type together. This makes it easier to calculate the position of each element by simply adding an offset to a base value, i.e., the memory location of the first element of the array (generally denoted by the name of the array).
* Linked List

A linked list is a linear data structure, in which the elements are not stored at contiguous memory locations. The elements in a linked list are linked using pointers.
* Vector

Vectors are the same as dynamic arrays with the ability to resize itself automatically when an element is inserted or deleted, with their storage being handled automatically by the container. Vector elements are placed in contiguous storage so that they can be accessed and traversed using iterators.

There also exits
* Stack
* Queue
* Hashing

Whose properties one can simply look up from myriad of references.

In this repository the implementation of `Array`, `Vector` and `LinkeList` is demonstrated in `C++`.