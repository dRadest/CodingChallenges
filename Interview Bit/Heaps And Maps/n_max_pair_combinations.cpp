/*
* https://www.interviewbit.com/problems/n-max-pair-combinations/
*
* Given two arrays A & B of size N each.
* Find the maximum n elements from the sum combinations (Ai + Bj) formed from elements in array A and B.
*
* For example if A = [1,2], B = [3,4], then possible pair sums can be 1+3 = 4 , 1+4=5 , 2+3=5 , 2+4=6
* and maximum 2 elements are 6, 5
*
* Example:
*   N = 4
*   a[]={1,4,2,3}
*   b[]={2,5,1,6}
*   Maximum 4 elements of combinations sum are
*   10   (4+6), 
*   9    (3+6),
*   9    (4+5),
*   8    (2+6)
*/

vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    // max heap to store sum and indecies pair
    priority_queue<pair<int,pair<int,int> >>p;

    // sort input arrays in ascending order
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    
    // last numbers are going to yield highest sum
    // and make our first entry
    int end1 = A.size()-1;
    int end2 = B.size()-1;
    
    // map to keep track of processed pairs
    map<pair<int,int>,int> m;
    
    // process first entry
    p.push({A[end1]+B[end2],{end1,end2}});
    m[{end1,end2}] = 1;
    
    // for traversing input arrays
    int st = 1;
    
    vector<int> v; // store result
    while(st<=A.size()){
        // get top of the heap
        pair<int,pair<int,int>> tp = p.top();
        v.push_back(tp.first);
        p.pop();
        
        // consider pair with number at index in A one less than current
        pair<int,int> p1 = {tp.second.first-1,tp.second.second};
        
        if(!m[p1]){
            p.push({A[p1.first]+B[p1.second],p1});
            m[p1] =1;
        };
        
        // consider pair with number at index in B one less than current
        p1 = {tp.second.first,tp.second.second-1};
        
        if(!m[p1]){
            p.push({A[p1.first]+B[p1.second],p1});
            m[p1] =1;
        };
        
        
        st++;
        
    }
    

    return v;
}
