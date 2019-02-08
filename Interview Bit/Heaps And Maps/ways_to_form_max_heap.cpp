/*
* https://www.interviewbit.com/problems/ways-to-form-max-heap/
*
* Max Heap is a special kind of complete binary tree in which 
* for every node the value present in that node is greater than the value present in it’s children nodes. 
* If you want to know more about Heaps, please visit this link
*
* So now the problem statement for this question is:
*
* How many distinct Max Heap can be made from n distinct integers
*
* In short, you have to ensure the following properties for the max heap :
*
*   Heap has to be a complete binary tree ( A complete binary tree is a binary tree in which every level, 
*	except possibly the last, is completely filled, and all nodes are as far left as possible. )
*   Every node is greater than all its children
*
* Let us take an example of 4 distinct integers. Without loss of generality let us take 1 2 3 4 as our 4 distinct integers
* 
* Following are the possible max heaps from these 4 numbers :
*
*         4 
*       /  \ 
*      3   2 
*     / 
*    1
*         4 
*       /  \ 
*      2   3 
*     / 
*    1
*        4 
*       /  \ 
*      3   1 
*     / 
*    2
*
* These are the only possible 3 distinct max heaps possible for 4 distinct elements.
* 
* Implement the below function to return the number of distinct Max Heaps that is possible from n distinct elements.
*
* As the final answer can be very large output your answer modulo 1000000007
*
* Input Constraints : n <= 100
*
* geeksforgeeks:
* https://www.geeksforgeeks.org/number-ways-form-heap-n-distinct-integers/
*/

//#define MAXN 105 // maximum value of n here 
  
// dp[i] = number of max heaps for i distinct integers 
long long dp[105];  
  
// nck[i][j] = number of ways to choose j elements 
//             form i elements, no order */ 
long long nck[105][105];  
  
// log2[i] = floor of logarithm of base 2 of i 
long long qwe[105];  
  
// to calculate nCk 
long long choose(int n, int k) 
{ 
    if (k > n) 
        return 0LL; 
    if (n <= 1LL) 
        return 1LL; 
    if (k == 0LL) 
        return 1LL; 
  
    if (nck[n][k] != -1) 
        return nck[n][k]; 
  
    long long answer = choose(n - 1, k - 1)%1000000007LL + choose(n - 1, k)%1000000007LL; 
    nck[n][k] = answer%1000000007LL; 
    return answer%1000000007LL; 
} 
  
// calculate l for give value of n 
int getLeft(int n) 
{ 
    if (n == 1) 
        return 0; 
  
    int h = qwe[n]; 
  
    // max number of elements that can be present in the  
    // hth level of any heap 
    int numh = (1 << h); //(2 ^ h) 
  
    // number of elements that are actually present in 
    // last level(hth level) 
    // (2^h - 1) 
    int last = n - ((1 << h) - 1); 
  
    // if more than half-filled 
    if (last >= (numh / 2)) 
        return (1 << h) - 1; // (2^h) - 1 
    else
        return (1 << h) - 1 - ((numh / 2) - last); 
} 
  
// find maximum number of heaps for n 
long long numberOfHeaps(int n) 
{ 
    if (n <= 1LL) 
        return 1LL; 
  
    if (dp[n] != -1LL) 
        return dp[n]; 
  
    int left = getLeft(n); 
    long long ans = ((choose(n - 1, left)%1000000007LL * numberOfHeaps(left)%1000000007LL)%1000000007LL) *  
                             numberOfHeaps(n - 1 - left)%1000000007LL ; 
    return dp[n] = (ans%1000000007LL); 
    
} 
  
// function to initialize arrays 
int Solution:: solve(int n) 
{ 
    for (int i = 0; i <= n; i++) 
        dp[i] = -1; 
  
    for (int i = 0; i <= n; i++) 
        for (int j = 0; j <= n; j++) 
            nck[i][j] = -1; 
  
    int currLog2 = -1; 
    int currPower2 = 1; 
  
    // for each power of two find logarithm 
    for (int i = 1; i <= n; i++) 
    { 
        if (currPower2 == i) 
        { 
            currLog2++; 
            currPower2 *= 2; 
           
        } 
        qwe[i] = currLog2; 
    } 
  
    return numberOfHeaps(n); 
}