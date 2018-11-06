* [Basics](#basics)
* [Solutions](#solutions)
	- [2D Arrays](#2d-arrays)
	- [Dynamic Arrays](#dynamic-arrays)
	- [Left rotation](#left-rotation)
	- [Sparse Arrays](#sparse-arrays)

# Basics

__declare, initialize, access...__

_C/C++_
```c
// declare: type arrayName [ arraySize ];
int intArray[10];
// initialize: type arrayName [] = {0, 1, 2, ..., n-1};
int array[] = {1, 2, 3, 4, 5};
int array[4] = 8; /* assign a single element */
// access element at position 3
int number = array[3];

/* 
* using pointers
* array name is a constant pointer to the first element of the array
*/

int* p = (int*) malloc (5 * sizeof(int)); // declaration using malloc
int* p = {1, 2, 3, 4, 5};
int number = *(p+2); // access element at position 1
```

_Java_
```java
// declare: dataType[] name;
int[] array;
// create: dataType[] name = new dataType[size];
int[] array = new int[5];
// or
int[] array = {1, 2, 3, 4, 5};
// access element: dataType[position]
int number = array[3];
```

# Solutions
## 2D Arrays
Problem on [HackerRank](https://www.hackerrank.com/challenges/2d-array/problem)
file: 

Java [2dArrays.java](2dArrays.java)

C [2d_arrays.c](2d_arrays.c)

access 2d array elements via pointers

`*(*(arr + i) + j)` where i is row number and j is column number

tutorial on [dyclassroom.com](https://www.dyclassroom.com/c/c-pointers-and-two-dimensional-array)

## Dynamic Arrays
Problem on [HackerRank](https://www.hackerrank.com/challenges/dynamic-array/problem)

file:

Java [DynamicArrays.java](DynamicArrays.java)

C [dynamic_arrays.c](dynamic_array.c)

allocate memory for an array

`int* b = (int*)malloc(sizeof(int));`

reallocate memory for an array

`b = (int*)realloc(b, 4*sizeof(int));`

Linked list C tutorial on [learn-c.org](https://www.learn-c.org/en/Linked_lists)

## Left Rotation

Problem on [HackerRank](https://www.hackerrank.com/challenges/array-left-rotation/problem)

file: Java [LeftRotation.java](LeftRotation.java)

## Sparse Arrays

Problem on [HackerRank](https://www.hackerrank.com/challenges/sparse-arrays/problem)

file: Java [SparseArrays.java](SparseArrays.java)