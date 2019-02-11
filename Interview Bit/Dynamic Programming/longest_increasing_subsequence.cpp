/*
*
* https://www.interviewbit.com/problems/longest-increasing-subsequence/
*
* Find the longest increasing subsequence of a given sequence / array.
*
* In other words, find a subsequence of array in which the subsequence’s elements are in strictly increasing order, 
* and in which the subsequence is as long as possible.
* This subsequence is not necessarily contiguous, or unique.
* In this case, we only care about the length of the longest increasing subsequence.
*
* Example :
*
*   Input : [0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15]
*   Output : 6
*
*   The sequence : [0, 2, 6, 9, 13, 15] or [0, 4, 6, 9, 11, 15] or [0, 4, 6, 9, 13, 15]
*/

int Solution::lis(const vector<int> &A) {
    if(A.size() == 0){
        return 0;
    }
    int n = A.size();
    // array to store LIS up to the number at index i
    int dp[n];
    // initialize all the values to 1
    for(int i=0; i<n; i++){
        dp[i] = 1;
    }
    int ans = 1; // minimum 1 element in LIS
    // construct dp 
    // for every element at index j
    // check if it can be added to element at index i (going up to j)
    // to form incrementing sequence
    for(int j=1; j<n; j++){
        for(int i=0; i<j; i++){
            if(A[i] < A[j] && dp[i]+1 > dp[j]){
                dp[j] = dp[i]+1;
                ans = max(ans, dp[j]);
            }
        }
    }
    return ans;
}
