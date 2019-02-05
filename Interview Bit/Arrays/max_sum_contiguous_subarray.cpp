/*
* https://www.interviewbit.com/problems/max-sum-contiguous-subarray/
* Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
*/

int Solution::maxSubArray(const vector<int> &A) {
   int max_so_far = A[0]; // overall max
   int curr_max = A[0]; // max of the current subarray
  
   for (int i = 1; i < A.size(); i++) 
   { 
       // include the current element in subbaray
       // or "start" a new one
       curr_max = max(A[i], curr_max+A[i]); 
       max_so_far = max(max_so_far, curr_max); 
   } 
   return max_so_far; 
}
