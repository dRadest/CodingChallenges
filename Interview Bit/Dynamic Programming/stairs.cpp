/*
*
* https://www.interviewbit.com/problems/stairs/
*
* You are climbing a stair case. It takes n steps to reach to the top.
*
* Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
* 
* Example :
*
*	Input : 3
*	Return : 3
*
*	Steps : [1 1 1], [1 2], [2 1]
*/

vector<int> dp;
int steps(int n){
    if(n < 0){
        return 0;
    }
    else if(n == 1){
        return 1;
    }
    else if(n == 2){
        return 2;
    }
    else if(dp[n]){
        return dp[n];
    }
    dp[n] = steps(n-2) + steps(n-1);
    return dp[n];
}
int Solution::climbStairs(int A) {
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    return steps(A);
}

