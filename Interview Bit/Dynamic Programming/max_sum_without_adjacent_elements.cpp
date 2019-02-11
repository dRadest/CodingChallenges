/*
*
* https://www.interviewbit.com/problems/max-sum-without-adjacent-elements/
*
* Given a 2 * N Grid of numbers, choose numbers such that the sum of the numbers
* is maximum and no two chosen numbers are adjacent horizontally, vertically or diagonally, and return it.
*
* Example:
*
*	Grid:
*		1 2 3 4
*		2 3 4 5
*	so we will choose
*	3 and 5 so sum will be 3 + 5 = 8
*
* Note that you can choose more than 2 numbers
*/

int Solution::adjacent(vector<vector<int> > &A) {
    if(A.size() == 0){
        return 0;
    }
    
    int inc = 0, exc = 0;
    
    // traverse the length of both rows
    for(int i = 0; i < A[0].size(); i++){
    	// pick the highest number of the two in current column
        int num = max(A[0][i], A[1][i]);
        
        // calculate sum if we include and exclude current number
        int temp = max(exc, inc);
    
        inc = exc + num;
        exc = temp;
    }
    
    
    return max(inc, exc);
}

