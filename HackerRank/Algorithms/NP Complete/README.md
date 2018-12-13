## MIT OpenCourseWare

[Design and Analysis of Algorithms](https://ocw.mit.edu/courses/electrical-engineering-and-computer-science/6-046j-design-and-analysis-of-algorithms-spring-2015/)

Youtube video: [Lecture 16](https://youtu.be/eHZifpgyH_4) on Complexity (P, NP, NP Complete)

__P__ = {problems solvable in polynomial time n^(O(I))}

__NP__ = {decision problems (yes/no) solvable in polynomial nondeterministic time}

problem X is:

* _NP-complete_ if XεNP & X is NP-hard
* _NP-hard_ if every problem YεNP reduces to X

__reduction__ from problem A to problem B: polynominal time algorithm convertin A inputs into equivalent B inputs

--P--|------NP------|---NPhard----- difficulty

				NP complete

How to prove X is NP complete? 

1. XεNP via nondeterministic algorithm or certificate + verifier
2. reduce from known NP complete problem Y to X

## Other Resources

hackerdashery [P vs NP](https://youtu.be/YX40hbAHx3s) youtube video

undefined behavior [P vs. NP - an introduction](https://youtu.be/OY41QYPI8cw) youtube video

Wikipedia [NP-completeness](https://en.wikipedia.org/wiki/NP-completeness)

GeeksforGeeks [NP-completeness](https://www.geeksforgeeks.org/np-completeness-set-1/)

Stackoverflow [answer](https://stackoverflow.com/questions/210829/what-is-an-np-complete-in-computer-science) to _What is NP-complete in CS?_

NP-complete problem [definition](https://www.britannica.com/science/NP-complete-problem) @britannica.com

GeeksforGeeks [Algorithm Analysis](https://www.geeksforgeeks.org/fundamentals-of-algorithms/#AnalysisofAlgorithms)

## Examples

#### SAT - Boolean Satisfiability Problem
[wikipedia](https://en.wikipedia.org/wiki/Boolean_satisfiability_problem)

Variable values TRUE or FALSE such that the formula evaluates to TRUE?

```
(x1∨x2∨...∨xn) and (y1∨x2∨...∨xn) ∧ ... ∧ (y1∨y2∨...∨yn)
```

Cook-Levin Theorem [wikipedia](https://en.wikipedia.org/wiki/Cook%E2%80%93Levin_theorem)


#### 0-1 Knapsack

_Given weights and values of n items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack._

Pseudo-polynomial time algorithm

* C/C++ [knapsack.c](knapsack.c)
* Java [Knapsack.java](Knapsack.java)

Wikipedia [article](https://en.wikipedia.org/wiki/Knapsack_problem)

GeeksforGeeks [tutorial](https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/)

Tushar Roy's youtube [video tutorial](https://youtu.be/8LusJS5-AGo)

#### Partition Problem

_Can a given multiset S of integers be partitioned into subsets S1 and S2 such that the sum of numbers in S1 equals sum of numbers in S2?_

Pseudo-polynomial time algorithm __for small sum__

* C/C++ [partition_problem.c](partition_problem.c)
* Java [PartitionProblem.java](PartitionProblem.java)

Wikipedia [article](https://en.wikipedia.org/wiki/Partition_problem)

GeeksforGeeks [tutorial](https://www.geeksforgeeks.org/partition-problem-dp-18/)

#### Vertex Cover

_for every edge(u,v) either 'u' or 'v' is in vertex cover (i.e. all edges are covered)_

Pseudo-polynomial time algorithm for binary tree

* C/C++ [vertex_cover_bt.c](vertex_cover_bt.c)

GeeksforGeeks [article](https://www.geeksforgeeks.org/vertex-cover-problem-set-2-dynamic-programming-solution-tree/)

AITR CS2 [vertex cover](https://youtu.be/ZZxj9hqldng) youtube video

Georgia Tech [vertex cover](https://youtu.be/m_dOtat56vY) youtube video

[Approximation Algorithms](https://youtu.be/MEz1J9wY2iM) by MITCourseWare

#### Hamiltonian Cycle

prerequisites: [Intro to backtracking](https://www.geeksforgeeks.org/backtracking-introduction/) on GeeksforGeeks, [Hamiltonian Path](https://en.wikipedia.org/wiki/Hamiltonian_path)

Hamiltonian path = path that visits each vertex in a graph exactly once

Hamiltonian cycle = Hamiltonian path with an edge between first and last vertex

_Determine whether a given graph contains Hamiltonian cycle_

Algorithms using 2D array to indicate edges

* C/C++ [ham_cycle_2d.c](ham_cycle_2d.c)
* Java [HamCycle2d.java](HamCycle2d.java)

Algorithm using array list to represent adjacency list

* Java [HamCycleAdj.java](HamCycleAdj.java)

GeeksforGeeks [tutorial](https://www.geeksforgeeks.org/hamiltonian-cycle-backtracking-6/)

#### Sudoku
GeeksforGeeks [tutorial](https://www.geeksforgeeks.org/sudoku-backtracking-7/)

Algorithm using backtracking

* C/C++ [sudoku.c](sudoku.c)
* Java [Sudoku.java](Sudoku.java)

#### Graph Coloring
_assignment of labels ("colors") to elements of a graph subject to certain constraints_

vertex coloring = _no two adjacent vertices are of the same color_

edge coloring = _no two adjacent edges are of the same color_

face coloring = _no two faces(regions) that share a boundary have the same color_

* Resources
	- Wikipedia 
		+ [article](https://en.wikipedia.org/wiki/Graph_coloring)
	- GeeksforGeeks 
		+ [intro tutorial](https://www.geeksforgeeks.org/graph-coloring-applications/)
		+ [greedy vertex coloring](https://www.geeksforgeeks.org/graph-coloring-set-2-greedy-algorithm/)
	- TutorialsPoint 
		+ [guide](https://www.tutorialspoint.com/graph_theory/graph_theory_coloring.htm)
* Greedy algorithm for vertex color
	- C++ [vertex_color.cpp](vertex_color.cpp)
	- Java [VertexColor.java](VertexColor.java)

#### Travelling salesman

_Given a list of cities and the distances between each pair of cities, what is the shortest possible route that visits each city and returns to the origin city?_ aka _find minimum weight hamiltonian cycle_

* Resources
	- Wikipedia
		+ [article](https://en.wikipedia.org/wiki/Travelling_salesman_problem)
	- GeeksforGeeks
		+ [naive and dp](https://www.geeksforgeeks.org/travelling-salesman-problem-set-1/)
		+ [approximate using MST](https://www.geeksforgeeks.org/travelling-salesman-problem-set-2-approximate-using-mst/)
	- medium.com
		+ [trials and tribulations of TSP](https://medium.com/basecs/the-trials-and-tribulations-of-the-traveling-salesman-56048d6709d)
	- Youtube
		+ poprythym [visualization](https://youtu.be/SC5CX8drAtU)
		+ Abdul Bari [dp](https://youtu.be/XaXsJJh-Q5Y) and [branch and bound](https://youtu.be/1FEP_sNb62k)
		+ Microsoft Research [2016 new approximation algorithms for TSP](https://youtu.be/t_Fd0n_AHLI)
	* Cambridge University
		+ [Approximation Algorithms and TSP](https://www.cl.cam.ac.uk/teaching/1516/AdvAlgo/tsp.pdf)

## Solutions
#### Walking The Approximate Longest Path
[Description](https://www.hackerrank.com/challenges/walking-the-approximate-longest-path/problem)

file: Java [WalkingTheApproximateLongestPath.java](WalkingTheApproximateLongestPath.java)


