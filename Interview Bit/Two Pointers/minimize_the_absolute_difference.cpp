/*
* https://www.interviewbit.com/problems/minimize-the-absolute-difference/
* Given three sorted arrays A, B and Cof not necessarily same sizes.
* Calculate the minimum absolute difference between the maximum and minimum number 
* from the triplet a, b, c such that a, b, c belongs arrays A, B, C respectively.
* i.e. minimize | max(a,b,c) - min(a,b,c) |.
*/

int Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    int diff = INT_MAX;
    // indecies of positions in arrays A, B, and C
    int i=0, j=0, k=0;
    int p=A.size(), q=B.size(), r=C.size();
    int maximum, minimum;
    while(i<p && j<q && k<r){ // indecies in range
    	// get max and min values of integers at current indecies
        maximum = max(A[i], max(B[j], C[k]));
        minimum = min(A[i], min(B[j], C[k]));
        
        if(maximum-minimum < diff){ // update diff
            diff = maximum-minimum;
        }
        if(diff == 0){ // minimum reached
            return 0;
        }
        
        // depending on where was minimum found
        // advance that position
        if(A[i] == minimum){
            i++;
        }else if(B[j] == minimum){
            j++;
        }else{
            k++;
        }
    }
    return diff;
}
