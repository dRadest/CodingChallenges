/*
* https://www.interviewbit.com/problems/remove-duplicates-from-sorted-array/
*
* Remove duplicates from Sorted Array
* Given a sorted array, remove the duplicates in place such that each element appears only once and return the new length.
*
* Note that even though we want you to return the new length, make sure to change the original array as well in place
* Do not allocate extra space for another array, you must do this in place with constant memory.
*/

int Solution::removeDuplicates(vector<int> &A) {    
    if(A.size() == 0){
        return A.size();
    }
    
    // position in the new array
    int k = 0;
    for(int i = 1; i < A.size(); i++){
    	// skip the elements of the same value
        if(A[k] != A[i]){
            A[k+1] = A[i];
            k++;
        }
    }
    
    A.erase(A.begin()+k+1, A.end());
    return k+1;
    
}
