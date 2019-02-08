/*
* https://www.interviewbit.com/problems/permutations/
*
* Given a collection of numbers, return all possible permutations.
* Note:
*    No two entries in the permutation sequence should be the same.
*    For the purpose of this problem, assume that all the numbers in the collection are unique.
*
* geeksforgeeks:
* https://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/
*/

// swap elements x and y
void swap(int* x, int* y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
void permuteHelp(vector<vector<int>> &ans, vector<int> &A, int l, int r){
    if(l == r){
        ans.push_back(A);
    }else{
        for(int i=l; i<=r; i++){
            swap(A[l], A[i]);
            permuteHelp(ans, A, l+1, r);
            swap(A[l], A[i]); // swap back
        }
    }
}
vector<vector<int> > Solution::permute(vector<int> &A) {
    vector<vector<int>> ans;
    permuteHelp(ans, A, 0, A.size()-1);
    return ans;
}

