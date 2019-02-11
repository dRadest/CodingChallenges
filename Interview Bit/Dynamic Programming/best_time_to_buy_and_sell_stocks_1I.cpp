/*
*
* https://www.interviewbit.com/problems/best-time-to-buy-and-sell-stocks-ii/
*
* Say you have an array for which the ith element is the price of a given stock on day i.
*
* Design an algorithm to find the maximum profit. You may complete as many transactions as you like
* (ie, buy one and sell one share of the stock multiple times). 
* However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*
* Example :
*
*	Input : [1 2 3]
*	Return : 2
*/

int Solution::maxProfit(const vector<int> &A) {    
    int i = 1;
    int sol = 0;
    while(i < A.size()){
        int diff = A[i] - A[i-1];
        if(diff > 0){
            sol = sol + diff;
        }
        i++;
    }
    
    return sol;
}


