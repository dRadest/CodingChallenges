/*
*
* https://www.interviewbit.com/problems/commutable-islands/
*
* There are n islands and there are many bridges connecting them. Each bridge has some cost attached to it.
*
* We need to find bridges with minimal cost such that all islands are connected.
*
* It is guaranteed that input data will contain at least one possible scenario in which all islands are connected with each other.
*
* Example :
*   Input
*
*         Number of islands ( n ) = 4
*         1 2 1 
*         2 3 4
*         1 4 3
*         4 3 2
*         1 3 10
*
* In this example, we have number of islands(n) = 4 . Each row then represents a bridge configuration.
* In each row first two numbers represent the islands number which are connected by this bridge 
* and the third integer is the cost associated with this bridge.
*
* In the above example, we can select bridges 1(connecting islands 1 and 2 with cost 1), 3(connecting islands 1 and 4 with cost 3), 
* 4(connecting islands 4 and 3 with cost 2). Thus we will have all islands connected with the minimum possible cost(1+3+2 = 6).
* In any other case, cost incurred will be more.
*/

/**
 * Kruskal's algorithm
**/

// returns the parent of node i
int find(int parent[], int i) {
    if(parent[i]==-1)
        return i;
    return find(parent, parent[i]);
}

// joins node x and y
void Union(int parent[], int x, int y) {
    int xp = find(parent, x);
    int yp = find(parent, y);
    parent[xp] = yp;
}
// function used for comparing edges
bool comp(vector<int> a, vector<int> b) {
    return a[2] < b[2];
}
int Solution::solve(int A, vector<vector<int> > &B) {
    // sort edges in ascending order by weight
    sort(B.begin(), B.end(), comp);
    
    // initialize parent array
    int parent[A];
    fill_n(parent, A, -1);
    
    int ans = 0;
    
    // traverse sorted edges
    for(int i=0;i<B.size();i++) {
        int up = find(parent, B[i][0]-1);
        int vp = find(parent, B[i][1]-1);
        
        // adding this edges doesn't form a circle
        if(up!=vp) {
            Union(parent, up, vp);
            ans += B[i][2];
        }
    }

    return ans;
}
