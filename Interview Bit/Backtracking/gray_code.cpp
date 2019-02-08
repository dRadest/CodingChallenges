/*
* https://www.interviewbit.com/problems/gray-code/
*
*The gray code is a binary numeral system where two successive values differ in only one bit.
*
* Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. 
* A gray code sequence must begin with 0.
*
* For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:
*   00 - 0
*   01 - 1
*   11 - 3
*   10 - 2
*
* There might be multiple gray code sequences possible for a given n.
* Return any such sequence.
*/

void backtrack(int n, vector<int> &ans){
    if(n==1){
        ans.push_back(0);
        ans.push_back(1);
        return;
    }
    backtrack(n-1,ans);
    int m=ans.size();
    int two=1;
    int i=1;
    // most significant bit
    while(i<n){
        two=two<<1;
        i++;
    }
    for(i=m-1;i>=0;i--){
        ans.push_back(ans[i]|two);
    }
    
}
vector<int> Solution::grayCode(int A) {
    vector<int> ans;
    if(A==0){
        ans.push_back(0);
        return ans;
    }
    backtrack(A,ans);
    return ans;
    
}
