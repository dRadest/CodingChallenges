/*
* https://www.interviewbit.com/problems/rotated-sorted-array-search/
* Suppose a sorted array is rotated at some pivot unknown to you beforehand.
* (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2 ).
* You are given a target value to search. If found in the array, return its index, otherwise return -1.
* You may assume no duplicate exists in the array.
*/

// return index of minimum value in A
int findMin(const vector<int> &A){
    int n = A.size(), start = 0, end = n-1;
    while(start <= end){
        if(A[start]<=A[end]){ // minimum found
            return start;
        }
        int mid = (start+end)/2;
        int next = (mid+1)%n;
        int prev = (mid+n-1)%n;
        if(A[mid] <= A[next] && A[mid] <= A[prev]){
            return mid; // pivot found
        }else if(A[mid] <= A[end]) {
            end = mid - 1; // discard second half
        }else if(A[mid] >= A[end]){
            start = mid + 1; // discard first half
        }
    }
    return 0; // not found
}

// classic binary search
int binarySearch(const vector<int> &A, int start, int end, int target){
    int mid, low = start, high = end;
    while(low <= high){
        mid = low + (high-low)/2;
        if(A[mid] == target){
            return mid;
        }else if(A[mid] > target){
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return -1; // not found
}

int Solution::search(const vector<int> &A, int B) {
    // find pivot point (index of minimum value)
    int pivotIndex = findMin(A);
    if(A[pivotIndex] == B){
        return pivotIndex;
    }
    int targetIndex;
    if(pivotIndex == 0){
        targetIndex = binarySearch(A, 0, A.size()-1, B);
    }else if(B <= A[pivotIndex-1] && B >= A[0]){ // B left of pivot
        targetIndex = binarySearch(A, 0, pivotIndex-1, B);
    }else{ // B right of pivot
        targetIndex = binarySearch(A, pivotIndex+1, A.size()-1, B);
    }
    return targetIndex;
    
    
}
