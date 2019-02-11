/*
*
* https://www.interviewbit.com/problems/n-digit-numbers-with-digit-sum-s-/
*
* Find out the number of N digit numbers, whose digits on being added equals to a given number S. 
* Note that a valid number starts from digits 1-9 except the number 0 itself. i.e. leading zeroes are not allowed.
*
* Since the answer can be large, output answer modulo 1000000007
*
*   N = 2, S = 4
*   Valid numbers are {22, 31, 13, 40}
*   Hence output 4.
*
* geeksforgeeks:
* https://www.geeksforgeeks.org/count-of-n-digit-numbers-whose-sum-of-digits-equals-to-given-sum/
*/

int rec(vector<vector<int > > &dp, int n, int sum) {
    if(n == 0 && sum == 0) return 1;
    if(n == 0) return 0;

    if(dp[n][sum] != -1) return dp[n][sum];

    int ans = 0;
    for(int i = 0; i < 10; i++) {
        if(sum-i >= 0){
            ans += rec(dp,n - 1, sum - i);
            ans %= 1000000007;
        }
    }
    return dp[n][sum] = ans;
}

int Solution::solve(int A, int B) {
    int ans = 0;
    // prepare dp table
    vector<vector<int> > dp;
    dp.resize(A+1);
    for(int i = 0; i < A+1; i++) {
        dp[i].resize(B+1);
        for(int j = 0; j < B+1; j++){
            dp[i][j] = -1;
        }
    }
    for(int i = 1; i < 10; i++) {
        if(B-i >= 0){
            ans += rec(dp, A-1, B-i);
            ans %= 1000000007;
        }
    }
    return ans;
}