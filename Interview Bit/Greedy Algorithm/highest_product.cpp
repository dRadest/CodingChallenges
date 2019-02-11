/*
*
* https://www.interviewbit.com/problems/highest-product/
*
* Given an array of integers, return the highest product possible by multiplying 3 numbers from the array
*
* Input:
*
* array of integers e.g {1, 2, 3}
*
*   NOTE: Solution will fit in a 32-bit signed integer 
*
* Example:
*
*	[0, -1, 3, 100, 70, 50]
*
*	=> 70*50*100 = 350000
*
*/

int Solution::maxp3(vector<int> &A) {
    int n=A.size();
    sort(A.begin(),A.end());
    // choose max between
    // bottom two * top, and
    // top three multiplied
    int ans=max(A[0]*A[1]*A[n-1], A[n-3]*A[n-2]*A[n-1]);
    return ans;
}
