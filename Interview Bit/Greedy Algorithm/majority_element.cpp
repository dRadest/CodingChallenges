/*
*
* https://www.interviewbit.com/problems/majority-element/
*
* Given an array of size n, find the majority element. The majority element is the element that appears more than floor(n/2) times.
*
* You may assume that the array is non-empty and the majority element always exist in the array.
*
* Example :
*
*	Input : [2, 1, 2]
*	Return  : 2 which occurs 2 times which is greater than 3/2. 
*/

int Solution::majorityElement(const vector<int> &A) {
    int maj_occur = floor(A.size()/2);
    map<int, int> m; // msp element to its occurance
    for(int i=0; i<A.size(); i++){
        m[A[i]]++;
        if(m[A[i]] > maj_occur){
            return A[i];
        }
    }
    return A[0];
}


