/*
* https://www.interviewbit.com/problems/subset/
*
* Given a set of distinct integers, S, return all possible subsets.
* Note:
* 
*    1. Elements in a subset must be in non-descending order.
*    2. The solution set must not contain duplicate subsets.
*    3. Also, the subsets should be sorted in ascending ( lexicographic ) order.
*    4. The list is not necessarily sorted.
*/

void make(vector<int>& A, vector<int> temp, int curr, vector<vector<int> >& ans){
    int n = A.size();
    
    ans.push_back(temp);
    
    if(curr == n){ // last reached
        return;
    }
    
    // consider all elements from current to the end
    for(int i = curr; i < n; i++){
        vector<int> temp1(temp); // copy temp 
        temp1.push_back(A[i]); // include element
        make(A, temp1, i+1, ans);
    }
}
vector<vector<int> > Solution::subsets(vector<int> &A) {
    vector<vector<int> > ans;
    vector<int> temp;
    
    if(A.size()){
       sort(A.begin(), A.end()); 
    }
    
    make(A, temp, 0, ans);
    
    return ans;
}
