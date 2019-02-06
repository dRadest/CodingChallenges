/*
* https://www.interviewbit.com/problems/rotated-array/
* Suppose a sorted array A is rotated at some pivot unknown to you beforehand.
* (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
* Find the minimum element.
* The array will not contain duplicates.
*/

int Solution::findMin(const vector<int> &A){
    int n = A.size(), start = 0, end = n-1;
    while(start <= end){
        if(A[start]<=A[end]){ // minimum found (subarray sorted)
            return A[start];
        }
        int mid = (start+end)/2; // or  (start + (end-start)/2)
        int next = (mid+1)%n; // one right of mid
        int prev = (mid+n-1)%n; // one left of mid
        // mid satisfies pivot property
        if(A[mid] <= A[next] && A[mid] <= A[prev]){
            return A[mid];
        }else if(A[mid] <= A[end]) {
            end = mid - 1; // discard second half
        }else if(A[mid] >= A[end]){
            start = mid + 1; // discard first half
        }
    }
    return A[0];
}
