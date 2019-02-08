/*
* https://www.interviewbit.com/problems/distinct-numbers-in-window/
*
* You are given an array of N integers, A1, A2 ,…, AN and an integer K. 
* Return the of count of distinct numbers in all windows of size K.
*
* Formally, return an array of size N-K+1 where i’th element in this array contains number of distinct elements in sequence Ai, Ai+1 ,…, Ai+k-1.
*
* Note:
*	If K > N, return empty array.
*
* For example,
/	A=[1, 2, 1, 3, 4, 3] and K = 3
*
*	All windows of size K are
*
*	[1, 2, 1]
*	[2, 1, 3]
*	[1, 3, 4]
*	[3, 4, 3]
*
* So, we return an array [2, 3, 3, 2].
*/

vector<int> Solution::dNums(vector<int> &A, int B) {
    vector<int> ans;
    if(B > A.size()){
        return ans;
    }
    
    map<int, int> m; // map number to occurance
    int distinct = 0; // keep track of distinct numbers in the window

    // get distinct value for the first window
    int i=0;
    for(; i<B; i++){
        if(m.find(A[i]) == m.end() || m[A[i]] == 0){
            distinct++;
        }
        m[A[i]] += 1;
    }
    ans.push_back(distinct);
    
    // add next number to window and remove first
    for(i=B; i<A.size(); i++){
        // remove first number
        int first_num = A[i-B];
        m[first_num] -= 1;
        if(m[first_num] == 0){ // first_num was unique
            distinct--;
        }
        // add current number 
        int current_num = A[i];
        if(m.find(current_num) == m.end() || m[A[i]] == 0){
            distinct++;
        }
        m[current_num] += 1;
        ans.push_back(distinct);
    }
    return ans;
}

