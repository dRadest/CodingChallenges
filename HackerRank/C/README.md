<a href="#"><img src="https://raw.githubusercontent.com/dRadovan/CodingChallenges/master/HackerRank/C/c_badge.jpg" title="CGoldBadge" alt="CGoldBadge" width="100"></a>
# HackerRank C Practice Challenges
Solutions with blog posts (where suitable)
* [Pointers in C](#pointers-in-c)
* [Bitwise Operators](#bitwise-operators)
* [Boxes through a Tunnel](#boxes-through-a-tunnel)
* [1D Arrays in C](#1d-arrays-in-c)
* [Array Reversal](#array-reversal)
* [Variadic Functions in C](#variadic-functions-in-c)
* [Permutations of Strings](#permutations-of-strings)
* [Smal Triangles, Large Triangles](#small-triangles-large-triangles)
* [Sorting Arrays of Strings](#sorting-arrays-of-strings)
* [Querying the Documents](#querying-the-documents)
* [Post Transition](#post-transition)
* [Structuring the Document](#structuring-the-document)

## Pointers in C
file: [pointers.c](pointers.c)

Problem description on [HackerRank](https://www.hackerrank.com/challenges/pointer-in-c/problem "pointers@HR") 

`int* p = &val` saves the address in a pointer. `&val` returns the memory address of val. `*p` to access the content of the memory to which the pointer points

## Bitwise Operators
file: [bitwise.c](bitwise.c)

Problem description on [HackerRank](https://www.hackerrank.com/challenges/bitwise-operators-in-c/problem "bitwise@HR") 

Bitwise operations reference table


| bit a | bit b  | a&b(AND) | a\|b(OR)| a^b(XOR) | ~a(NOT) |
| :----:|:------:| :-------:|:-------:|:--------:|:-------:|
| 0     | 0      | 0        | 0       | 0        | 1       |
| 0     | 1      | 0        | 1       | 1        | 1       |
| 1     | 0      | 0        | 1       | 1        | 0       |
| 1     | 1      | 1        | 1       | 0        | 0       |


## Boxes through a Tunnel
file: [boxes.c](boxes.c)

Problem description on [HackerRank](https://www.hackerrank.com/challenges/too-high-boxes/problem "boxes@HR")

## 1D Arrays in C
file: [1darray.c](1darray.c)

Problem description on [HackerRank](https://www.hackerrank.com/challenges/1d-arrays-in-c/problem "1darray@HR")

## Array Reversal
file: [arrayrev.c](arrayrev.c)

Problem description on [HackerRank](https://www.hackerrank.com/challenges/reverse-array-c/problem "arrayrev@HR")

## Variadic Functions in C
file: [variadic.c](variadic.c)

Problem description on [HackerRank](https://www.hackerrank.com/challenges/variadic-functions-in-c/problem "variadic@HR")

#### stdarg.h 
Defines a variable type _va_list_ and three macros: _va_start()_, _va_arg()_ and _va_end()_

* **va_list**

holds the information needed by the three macros

* **va_start()**

`void va_start(va_list ap, last_arg)` initializes _ap_ variable. _last_arg_ is the last required (fixed) argument (before the ellipsis ...)

* **va_arg()**

`type va_arg(va_list ap, type)` retrieves the next argument in the arguments list of type _type_

* **va_end()**

`void va_end(va_list ap)` allows the function with variable arguments which called _va_start()_ to return (else result is undefined) 

## Permutations of Strings
file: [permutations.c](permutations.c)

Problem description on [HackerRank](https://www.hackerrank.com/challenges/permutations-of-strings/problem "permutations@HR")

This is a solution with the implementation of algorithm from [Wikipedia](https://en.wikipedia.org/wiki/Permutation#Generation_in_lexicographic_order):

1. Find the largest index k such that a[k] < a[k + 1]. If no such index exists, the permutation is the last permutation.
2. Find the largest index l greater than k such that a[k] < a[l].
3. Swap the value of a[k] with that of a[l].
4. Reverse the sequence from a[k + 1] up to and including the final element a[n].

## Small Triangles, Large Triangles
file: [triangle.c](triangle.c)

Problem description on [HackerRank](https://www.hackerrank.com/challenges/small-triangles-large-triangles/problem "triangle@HR")

## Sorting Arrays of Strings
file: [sorting.c](sorting.c)

Problem description on [HackerRank](https://www.hackerrank.com/challenges/sorting-array-of-strings/problem "sorting@HR")

Documentation for [strcmp()](http://www.cplusplus.com/reference/cstring/strcmp/), [strchr()](http://www.cplusplus.com/reference/cstring/strchr/) and [strlen()](http://www.cplusplus.com/reference/cstring/strlen/) from [string.h](http://www.cplusplus.com/reference/cstring/) library  

## Querying the Documents
file: [querying.c](querying.c)

Problem description on [HackerRank](https://www.hackerrank.com/challenges/querying-the-document/problem "querying@HR")

Interesting post in discussion section:

> I have never seen C being used for complex parsing before. If you find yourself using quadruple pointers, other than for representing matrices, you're doing something wrong.
> This is the apotheosis of bad problem design and choice of language. People can learn something useful like function passing, structs, recursion, preprocessing, etc, instead > of digging the ground like a madman.

## Post Transition
file: [post_transition.c](post_transition.c)

Problem description on [HackerRank](https://www.hackerrank.com/challenges/post-transition/problem "ptransition@HR")

Documentation for [realloc()](http://www.cplusplus.com/reference/cstdlib/realloc/) of the standard c library [stdlib.h](http://www.cplusplus.com/reference/cstdlib/)

## Structuring the Document
file: [structuring.c](structuring.c)

Problem description on [HackerRank](https://www.hackerrank.com/challenges/structuring-the-document/problem "structuring@HR")

Documentation for [strlen()](http://www.cplusplus.com/reference/cstring/strlen/), [strchr()](http://www.cplusplus.com/reference/cstring/strchr/), [memset()](http://www.cplusplus.com/reference/cstring/memset/) and [strncpy()](http://www.cplusplus.com/reference/cstring/strncpy/) of the c string library [string.h](http://www.cplusplus.com/reference/cstring/)



