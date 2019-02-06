/*
* https://www.interviewbit.com/problems/search-for-a-range/
* Given a sorted array of integers, find the starting and ending position of a given target value.
* Your algorithm’s runtime complexity must be in the order of O(log n).
* If the target is not found in the array, return [-1, -1].
*/

// helper function to search for the first or last occurance of key
// indicated by searchFirst
int binarySearch(const vector<int>& A, int key, bool searchFirst){
    int start = 0;
    int end = A.size()-1;
    int mid;
    int result =  -1;
    while(start <= end){
        mid = start + (end-start)/2;
        if(A[mid] == key){ // key found
            result = mid;
            if(searchFirst){ // move left
                end = mid-1;
            }
            else{ // move right
                start = mid+1;
            }
        }
        else if(A[mid] > key){
        	// discard the right half
            end = mid-1;
        }
        else{ // A[mid] < key
        	// discard the left half
            start = mid+1;
        }
    }
    return result;
}

 
vector<int> Solution::searchRange(const vector<int> &A, int B) {
    vector<int> sol;
    
    sol.push_back(binarySearch(A, B, true)); // find first occurance
    sol.push_back(binarySearch(A, B, false)); // find last occurance
    
    return sol;
    
}