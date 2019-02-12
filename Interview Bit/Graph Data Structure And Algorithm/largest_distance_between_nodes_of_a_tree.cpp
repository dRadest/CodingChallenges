/*
*
* https://www.interviewbit.com/problems/largest-distance-between-nodes-of-a-tree/
*
* Find largest distance
* Given an arbitrary unweighted rooted tree which consists of N (2 <= N <= 40000) nodes. 
* The goal of the problem is to find largest distance between two nodes in a tree.
* Distance between two nodes is a number of edges on a path between the nodes (there will be a unique path between any pair of nodes since it is a tree).
* The nodes will be numbered 0 through N - 1.
*
* The tree is given as an array P, there is an edge between nodes P[i] and i (0 <= i < N).
* Exactly one of the i’s will have P[i] equal to -1, it will be root node.
*
* Example:
*    If given P is [-1, 0, 0, 0, 3], then node 0 is the root and the whole tree looks like this: 
*
*          0
*       /  |  \
*      1   2   3
*               \
*                4  
*
* One of the longest path is 1 -> 0 -> 3 -> 4 and its length is 3, thus the answer is 3. Note that there are other paths with maximal distance. 
*/

pair<int, int> process(queue<pair<int, int> >& q, vector<int>& visited, unordered_map<int, vector<int> >& x){
    // Typical BFS with keeping track of the longest distance and farthest element.
    int maxi = INT_MIN, farthest = 0;
    while(!q.empty()){
        int node = q.front().first;
        int distance = q.front().second;
        q.pop();
        if(distance > maxi){
            maxi = distance;
            farthest = node;
        }
        visited[node] = 1;
        for(int i = 0; i < x[node].size(); i++){
            if(!visited[x[node][i]]){
                visited[x[node][i]] = 1;
                q.push({x[node][i], distance+1});
            }
        }
    }
    return {maxi, farthest};
}
int Solution::solve(vector<int> &A) {
    // Base Case
    if(A.size() <= 1)return 0;
    
    // Visited array to keep track of visited elements
    vector<int> visited(A.size(), 0);
    
    // Map to make the graph from given array
    unordered_map<int, vector<int> > x;
    x.clear();
    
    for(int i = 0; i < A.size(); i++){
        // If the value is -1, it doesn't have any parent.
        // Make the pairs in the adj. list type map
        if(A[i] != -1){
            x[A[i]].push_back(i);
            x[i].push_back(A[i]);
        }
    }
    
    // Start from the first element in the array and mark it as visited
    queue<pair<int, int> > q;
    q.push({0, 0});
    visited[0] = 1;

    // Gets the farthest element from the first element
    int farthest = process(q, visited, x).second;

    vector<int> vis(A.size(), 0);
    
    // Now apply BFS on the farthest element found and return the distance
    // of the farthest element found so far.
    q.push({farthest, 0});
    vis[farthest] = 1;
    return process(q, vis, x).first;
}

