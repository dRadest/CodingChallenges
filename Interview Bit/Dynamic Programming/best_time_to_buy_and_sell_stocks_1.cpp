/*
*
* https://www.interviewbit.com/problems/best-time-to-buy-and-sell-stocks-i/
*
* Say you have an array for which the ith element is the price of a given stock on day i.
*
* If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), 
* design an algorithm to find the maximum profit.
*
* Example :
*
*	Input : [1 2]
*	Return :  1
*/

// gredy approach
int Solution::maxProfit(const vector<int> &A) {
    if(A.size() == 0){
        return 0;
    }
    int ans = 0;
    int min_price = A[0];
    for(int i=1; i<A.size(); i++){
        // find min price
        if(A[i] < min_price){
            min_price = A[i];
        }
        ans = max(ans, A[i]-min_price);
    }
    return ans;
}


