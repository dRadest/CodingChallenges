/*
*
* https://www.interviewbit.com/problems/unique-binary-search-trees-ii/
*
* Given A, how many structurally unique BST’s (binary search trees) that store values 1...A?
*
* Example :
*
*   Given A = 3, there are a total of 5 unique BST’s.
*
*
*      1         3     3      2      1
*       \       /     /      / \      \
*        3     2     1      1   3      2
*       /     /       \                 \
*      2     1         2                 3
*/

// A dynamic programming based function to find nth Catalan number 
int catalan(int n) 
{ 
    // Table to store results of subproblems 
    int catalanDP[n+1]; 
  
    // Initialize first two values in table 
    catalanDP[0] = catalanDP[1] = 1; 
  
    // Fill entries in catalan[] using recursive formula 
    for (int i=2; i<=n; i++) 
    { 
        catalanDP[i] = 0; 
        for (int j=0; j<i; j++) 
            catalanDP[i] += catalanDP[j] * catalanDP[i-j-1]; 
    } 
  
    // Return last entry 
    return catalanDP[n]; 
} 
int Solution::numTrees(int A) {
    return catalan(A);
}
