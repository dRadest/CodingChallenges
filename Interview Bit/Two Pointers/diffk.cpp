/*
* https://www.interviewbit.com/problems/diffk/
* Given an array ‘A’ of sorted integers and another non negative integer k, 
* find if there exists 2 indices i and j such that A[i] - A[j] = k, i != j.
* 
* Return 0 / 1 ( 0 for false, 1 for true ) for this problem
* Try doing this in less than linear space complexity.
*/

int Solution::diffPossible(vector<int> &A, int B) {
    for(int i=0; i<A.size(); i++){
        for(int j=A.size()-1; i<j && j>=0;){
            if(A[j]-A[i]>B){
                j--;
            }
            else if(A[j] - A[i] == B){
                return 1;
            }else{
                break;
            }
        }
    }
    return 0;
}

