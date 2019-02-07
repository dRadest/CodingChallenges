/*
* https://www.interviewbit.com/problems/nearest-smaller-element/
*
* Given an array, find the nearest smaller element G[i] for every element A[i] in the array 
* such that the element has an index smaller than i.
*
* More formally,
* G[i] for an element A[i] = an element A[j] such that 
*    j is maximum possible AND 
*    j < i AND
*    A[j] < A[i]
*
* Elements for which no smaller element exist, consider next smaller element as -1.
*/

vector<int> Solution::prevSmaller(vector<int> &A) {
    int n = A.size();
    // initialize ans to -1
    vector<int> ans(n,-1);
    stack<int> st;
    // traverse input array
    for(int i=0; i<A.size(); i++){
        // pop all elements greater than or equal to A[i]
        while(!st.empty() && st.top()>=A[i]){
            st.pop();
        }
        // element smaller than A[i] on the stack
        if(!st.empty()){
            ans[i] = st.top();
        }
        // current element smallest so far
        st.push(A[i]);

    }
    return ans;
}
