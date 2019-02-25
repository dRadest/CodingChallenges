/*
*
* https://www.codechef.com/INOIPRAC/problems/INOI1402
*
*/

#include<bits/stdc++.h>
#include <limits.h>

int main(int argc, char const *argv[])
{
	// read the input
	int c, f;
	std::cin >> c >> f;
	// construct a graph table
	int graph[c][c];
	int i, j, k, x, y, p;
	// initialize all values to infinity
	for (i = 0; i < c; ++i)
	{
		for (j = 0; j < c; ++j)
		{
			graph[i][j] = 100000000;
		}
	}
	// no self-loops
	for (i = 0; i < c; ++i)
	{
		graph[i][i] = 0;
	}
	// read the rest of the values
	for (i = 0; i < f; ++i)
	{
		std::cin>>x>>y>>p;
		// undirected graph (every edge goes both ways)
		graph[x-1][y-1] = p;
		graph[y-1][x-1] = p;
	}
	// create a distance table which is a copy of graph (if we needed to retain original input graph)
	int distance[c][c];
	for (i = 0; i < c; ++i)
	{
		for (j = 0; j < c; ++j)
		{
			distance[i][j] = graph[i][j];
		}
	}

	/* the core of Floyd-Warshall's algorithm
	 for every node k going from 1 to N 
	 we consider if going through it (i.e. a path from i to j includes k) is shorter */
	for (k = 0; k < c; ++k)
	{
		for (i = 0; i < c; ++i)
		{
			for (j = 0; j < c; ++j)
			{
				if(distance[i][j] > distance[i][k] + distance[j][k])
				{
					distance[i][j] = distance[i][k] + distance[j][k];
				}
			}
		}
	}

	// traverse the distance table to find the maximum value
	int max_min = 0;
	for (i = 0; i < c; ++i)
	{
		for (j = 0; j < c; ++j)
		{
			max_min=std::max(max_min, distance[i][j]);
		}
	}
	std::cout << max_min << "\n";
	return 0;
}