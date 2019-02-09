/*
*
* https://www.interviewbit.com/problems/jump-game-array/
*
* Given an array of non-negative integers, you are initially positioned at the first index of the array.
*
* Each element in the array represents your maximum jump length at that position.
*
* Determine if you are able to reach the last index.
*
* For example:
*	A = [2,3,1,1,4], return 1 ( true ).
*
*	A = [3,2,1,0,4], return 0 ( false ).
*
* Return 0/1 for this problem
*/

// build the solution in top-bottom fashion
int Solution::canJump(vector<int> &A) {
    int n = A.size();
    int dp[n];
    dp[n-1] = 0; // last position
    for(int i=n-2; i>=0; i--){
        // last position directly reachable from i-th
        if(i+A[i]>n-1){
            dp[i] = n-1;
            continue;
        }
        dp[i] = i + A[i];
        // check all the positions reachable from this one (i-th)
        for(int j=i+1; j<=i+A[i]; j++){
            dp[i] = max(dp[i], dp[j]);
        }
    }
    if(dp[0]==n-1){ // reachable from first position
        return 1;
    }else{
        return 0;
    }
}

