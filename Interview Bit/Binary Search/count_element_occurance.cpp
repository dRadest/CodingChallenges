/*
* https://www.interviewbit.com/problems/count-element-occurence/
* Given a sorted array of integers, find the number of occurrences of a given target value.
* Your algorithm’s runtime complexity must be in the order of O(log n).
* If the target is not found in the array, return 0
*/

// returns first or last occurance (indicated by parameter first)
// or -1 element not present
int binarySearch(vector<int> A, int target, bool first){
    int start = 0, end = A.size()-1, result = -1;
    while(start <= end){
        int mid = (start + end)/2;
        if(A[mid] == target){ // target found
            // save result
            result = mid;
            if(first){
            	// discard the right 
                end = mid - 1;
            }else{
            	// discard the left
                start = mid + 1;
            }
        }
        else if(target < A[mid]){ // go left
            end = mid - 1;
        }else{ // go right
            start = mid + 1;
        }
    }
    return result;
}

int Solution::findCount(const vector<int> &A, int B) {
    int firstIndex = binarySearch(A, B, true);
    int lastIndex = binarySearch(A, B, false);
    if(firstIndex == -1 || lastIndex == -1){
        return 0;
    }
    return (lastIndex-firstIndex+1);
}
