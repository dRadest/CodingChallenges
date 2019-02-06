/*
* https://www.interviewbit.com/problems/min-xor-value/
* Given an array of N integers, 
* find the pair of integers in the array which have minimum XOR value.
* Report the minimum XOR value.
*
* idea: smallest XOR value between two numbers with minimum bit difference
*/


int Solution::findMinXor(vector<int> &A) {
    // sort in ascending order
    sort(A.begin(), A.end());
    // keep track of the smallest xor
    // of two adjacent numbers
    int smallestXor = A[0] ^ A[1];
    for (int i = 2; i < A.size(); i++) {
        smallestXor = min(smallestXor, A[i - 1] ^ A[i]);
    }
    return smallestXor;
}
