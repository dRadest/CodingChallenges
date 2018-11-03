<a href="#"><img src="https://raw.githubusercontent.com/dRadovan/CodingChallenges/master/HackerRank/C%2B%2B/cpp_badge.jpg" title="CPPGoldBadge" alt="CPPGoldBadge" width="100"></a>
# HackerRank C++ Practice Challenges
* [Pointer](#pointer)
* [Variable Sized Arrays](#variable-sized-arrays)
* [Class](#class)
* [Box It!](#box-it)
* [C++ Class Templates](#c-class-templates)
* [C++ Class Template Specialization](#c-class-template-specialization)
* [Accessing Inherited Functions](#accessing-inherited-functions)
* [Operator Overloading](#operator-overloading)
* [Overloading Ostream Operator](#overloading-ostream-operator)
* [Inherited Code](#inherited-code)
* [Cpp Exception Handling](#cpp-exception-handling)
* [Attending Workshops](#attending-workshops)
* [Virtual Function](#virtual-function)
* [Messages Order](#messages-order)
* [Abstract Classes - Polymorphism](#abstract-classes---polymorphism)
* [Magic Spells](#magic-spells)
* [C++ Variadics](#c-variadics)
* [Bit Array](#bit-array)
## Pointer

file: [pointer.cpp](pointer.cpp)

Problem description on [HackerRank](https://www.hackerrank.com/challenges/c-tutorial-pointer/problem "pointers@HR")

## Variable Sized Arrays

file: 

Solution using arrays [variable_sized_arrays_arr.cpp](variable_sized_arrays_arr.cpp)

Solution using vectors [variable_sized_arrays_vec.cpp](variable_sized_arrays_vec.cpp)

Problem description on [HackerRank](https://www.hackerrank.com/challenges/variable-sized-arrays/problem "pointers@HR") 

Documentation on C++ [vector](http://www.cplusplus.com/reference/vector/vector/ "vector@cplusplus.com")

## Class

file: [class.cpp](class.cpp)

Problem description on [HackerRank](https://www.hackerrank.com/challenges/c-tutorial-class/problem "class@HR")

Documentation for [stringstream](http://www.cplusplus.com/reference/sstream/stringstream/ "ss@cplusplus.com")

## Box It!

file: [box_it.cpp](box_it.cpp)

Problem description on [HackerRank](https://www.hackerrank.com/challenges/box-it/problem "boxit@HR")

Tutorialspoint's [article](https://www.tutorialspoint.com/cplusplus/cpp_overloading.htm) on C++ overloading

## C++ Class Templates

file: [class_templates.cpp](class_templates.cpp)

Problem description on [HackerRank](https://www.hackerrank.com/challenges/c-class-templates/problem "classtemplates@HR")

Tutorialspoint's [article](https://www.tutorialspoint.com/cplusplus/cpp_templates.htm) on C++ templates 

## C++ Class Template Specialization

file: [class_template_specialization.cpp](class_template_specialization.cpp)

Problem description on [HackerRank](https://www.hackerrank.com/challenges/cpp-class-template-specialization/problem "classtemplatespec@HR")

Documentation for static_cast conversion on [cppreference.com](https://en.cppreference.com/w/cpp/language/static_cast) and why use it on [stackoverflow](https://stackoverflow.com/questions/103512/why-use-static-castintx-instead-of-intx)

## Accessing Inherited Functions

file: [accessing_inherited_functions.cpp](accessing_inherited_functions.cpp)

Problem description on [HackerRank](https://www.hackerrank.com/challenges/accessing-inherited-functions/problem "aif@HR")

## Operator Overloading

file: [operator_overloading.cpp](operator_overloading.cpp)

Problem description on [HackerRank](https://www.hackerrank.com/challenges/operator-overloading/problem "op_overload@HR")

## Overloading Ostream Operator

file: [overloading_ostream_operator.cpp](overloading_ostream_operator.cpp)

Problem description on [HackerRank](https://www.hackerrank.com/challenges/overloading-ostream-operator/problem "ooo@HR")

## Inherited Code

file: [inherited_code.cpp](inherited_code.cpp)

Problem description on [HackerRank](https://www.hackerrank.com/challenges/inherited-code/problem "inherited_code@HR")

TutorialsPoint's [article](https://www.tutorialspoint.com/cplusplus/cpp_exceptions_handling.htm) on exceptions handling

## Cpp Exception Handling

file: [cpp_exception_handling.cpp](cpp_exception_handling.cpp)

Problem description on [HackerRank](https://www.hackerrank.com/challenges/cpp-exception-handling/problem "exception_handling@HR")

## Attending Workshops

file: [attending_workshops.cpp](attending_workshops.cpp)

Problem description on [HackerRank](https://www.hackerrank.com/challenges/attending-workshops/problem "attending_workshops@HR")

## Virtual Function

file: [virtual_functions.cpp](virtual_functions.cpp)

Problem description on [HackerRank](https://www.hackerrank.com/challenges/virtual-functions/problem "virtual_functions@HR")
s
Virtual Functions and Runtime Polymorphism in C++ [article](https://www.geeksforgeeks.org/virtual-functions-and-runtime-polymorphism-in-c-set-1-introduction/) on GeeksforGeeks

Stackoverflow [question](https://stackoverflow.com/questions/2523203/c-header-file-and-function-declaration-ending-in-0) on virtual function declaration `virtual void func() = 0; ` 

## Messages Order

file: [messages_order.cpp](messages_order.cpp)

Problem description on [HackerRank](https://www.hackerrank.com/challenges/messages-order/problem "messages_order@HR")

## Abstract Classes - Polymorphism

file: [abstract_classes.cpp](abstract_classes.cpp)

Problem description on [HackerRank](https://www.hackerrank.com/challenges/abstract-classes-polymorphism/problem "abstract_classes@HR")

## Magic Spells

file: [magic_spells.cpp](magic_spells.cpp)

Problem description on [HackerRank](https://www.hackerrank.com/challenges/magic-spells/problem "magic_spells@HR")

dynamic_cast [cppreference.com](https://en.cppreference.com/w/cpp/language/dynamic_cast) and examples on [BogoToBogo](https://www.bogotobogo.com/cplusplus/dynamic_cast.php)

Longest Common Subsequence (LCS) tutorial on [GeeksforGeeks](https://www.geeksforgeeks.org/longest-common-subsequence-dp-4/) and [Wikipedia](https://en.wikipedia.org/wiki/Longest_common_subsequence_problem) article.

Solution using vectors...
```c++
		string unknownSpell = spell->revealScrollName();
		string journalEntry = SpellJournal::journal;

		int m = journalEntry.length() + 1;
		int n = unknownSpell.length() + 1;

		vector < vector<int> > v(m, vector<int>(n));

		for (int f = 1; f<m; f++)
		{
			for (int c = 1; c<n; c++)
			{
				if (unknownSpell[c - 1] == journalEntry[f - 1])
					v[f][c] = v[f - 1][c - 1] + 1;
				else
				{
					if (v[f][c - 1] > v[f - 1][c])
						v[f][c] = v[f][c - 1];
					else
						v[f][c] = v[f - 1][c];
				}
			}
		}
		cout << v[m - 1][n - 1] << endl;
```
Solution using arrays...
```c++
        string unknownSpell = spell->revealScrollName();
        string journalEntry = SpellJournal::journal;
    
        int m = journalEntry.length() + 1;
        int n = unknownSpell.length() + 1;

        int L[m][n];
        int i, j; 
        
        for(i=0; i<m; i++) {
            L[i][0] = 0;
        }
        for(j=0; j<n; j++){
            L[0][j] = 0;
        }

       for (i=1; i<m; i++) 
       { 
         for (j=1; j<n; j++) 
         { 
           if (unknownSpell[j-1] == journalEntry[i-1]) 
             L[i][j] = L[i-1][j-1] + 1; 
       
           else 
             L[i][j] = max(L[i-1][j], L[i][j-1]); 
         } 
       } 

       cout << L[m-1][n-1] << endl;
```

## C++ Variadics

file: [cpp_variadics.cpp](cpp_variadics.cpp)

Problem description on [HackerRank](https://www.hackerrank.com/challenges/cpp-variadics/problem "cpp_variadics@HR")

Parameter pack reference on [cppreference.com](https://en.cppreference.com/w/cpp/language/parameter_pack)

Variadic templates in C++ article on [eli.thegreenplace.net](https://eli.thegreenplace.net/2014/variadic-templates-in-c/)

Post in discussion explaining the code:
>consider the int 29 = 0b00011101

>this can be seen as 1*2^0 + 0*2^1 + 1*2^2 + 1*2^3 + 1*2^4
>
>if you progressively factor out the base of 2, you can write it as
>
>1 + 2*( 0 + 2*( 1 + 2*( 1 + 2*( 1 ) ) ) )
>
>in his return statement
>
>return (reversed_binary_value<b, d...>() << 1) + a;
>
>'a' is a bool that is implicitly cast to an int as either 1 or 0. the left shift '<<' by 1 is equiv to multiplying by 2
>
>so, the return statement is of the form above, a recurring pattern of 1 + 2*(subprob), 
>
>where subprob is itself of form 1 + 2*(subprob).


## Bit Array

file: [bit_array.cpp](bit_array.cpp)

Problem description on [HackerRank](https://www.hackerrank.com/challenges/bitset-1/problem "bit_array@HR")

Solution on [ideon](https://ideone.com/gFQgqT)

Author's comments on discussion:
>The problem boils down to finding minimal m > 0 and n >= 0 such that a[n + m] = a[n].
>
>As pointed out by others Floyd's and Brent's algorithms are nice for this problem. 
>
>These algorithms are generic and work for any recurrence a[i] = f(a[i-1]), 
>
>ie, they don't make any assumption about f. For the problem at hand, f(x) = p*x + q 
>
>and we can buy a lot of time if we use f's mathematical properties. Indeed, one can easily show that
>
>a[n] = s * p^n + q * (p^(n-1) + ... + 1) for all n >= 1.
>
>The arguments are a bit lengthy for here but to give an idea of the math suppose s > 0 and q = 0 
>
>(the case where q > 0 brings some but not much complexity). Then
>
>a[n] = s * p^n for all n >= 1.
>
>It follows that
>
>a[n + m] - a[n] = s * (p^m - 1) * p^n.
>
>Consider the case where p is even but not zero. One can find unique integers x and ysuch that 
>
>p = x * 2^y and x is odd. Analogously, we can find integers u and v such that s = u * 2^v and u is odd. 
>
>Using this we obtain
>
>a[m + n] - a[n] = x^n * (p^m - 1) * u * 2^(n * y + v).
>
>Since x^n, p^m - 1 and u are odd, the only way for the rhs (and thus for the lhs) 
>
>to be zero modulo 2^31 is when n * y + v >= 31. We are looking for the minimal n which implies 
>
>n = ceiling((31 - v) / y). We have shown that
>
>a[m + n] = a[n] mod 2^31 for all m > 0,
>
>that is, the sequence is constant from n onwards. It can also be shown that a[0], ..., a[n] are all distinct. 
>
>Therefore, the solution to the problem is min(n + 1, N).
>
>When p is odd, the argument is much more complex and relies on a property of the group ((Z/rZ)*, *) 
>
>where r=2^k is a power of 2, namely, if p^m = 1 modulo r and m is minimal, >then m divides 2^(k - 1), 
>
>ie, m belongs to {1, 2, 4, ..., 2^(k - 1)}.
>
>I've implemented my solution and it took 0s to solve all test cases. 
>
>For comparison, I've also implemented the Floyd's and Brent's algorithm. 
>
>An interesting test case is N = 100000000, s = 1, p = 3 and q = 1 for which the answer is N. 
>
>My solution took 0.0s, Floyd's took 2.5s and Brent took 16.0s.
