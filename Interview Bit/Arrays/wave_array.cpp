/*
* https://www.interviewbit.com/problems/wave-array/
* Given an array of integers, sort the array into a wave like array and return it,
* In other words, arrange the elements into a sequence such that a1 >= a2 <= a3 >= a4 <= a5.....
*/

vector<int> Solution::wave(vector<int> &A) {
    // sort the input array in ascending order
    sort(A.begin(), A.end());
    vector<int> ret;
    // traverse the array for every second index
    for(int i=0; i<A.size()-1; i+=2){
        // swap the element at index i and the next element
        ret.push_back(A[i+1]);
        ret.push_back(A[i]);
    }
    // add unprocessed element
    if(A.size()%2 != 0){
        ret.push_back(A[A.size()-1]);
    }
    return ret;
}
