/*
*
* https://www.interviewbit.com/problems/clone-graph/
*
* Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.
*/

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */

/**
 * traverse graph in BFS fashion
 * while visiting a node make a clone of it
**/ 
UndirectedGraphNode *Solution::cloneGraph(UndirectedGraphNode *node) {
    // keep track of cloned nodes
    map<UndirectedGraphNode*, UndirectedGraphNode*> m;
    // used in graph traversal
    queue<UndirectedGraphNode*> q;
    
    // push source node onto queue
    q.push(node);
    // clone it and mark it
    UndirectedGraphNode* newnode;
    newnode = new UndirectedGraphNode(node->label);
    m[node]=newnode;
    
    while(!q.empty()){
        // current node = front node
        UndirectedGraphNode* u = q.front();
        q.pop();
        vector<UndirectedGraphNode*> v = u -> neighbors;
        int n = v.size();
        // traverse neighboring nodes of the current node
        for(int i=0; i<n; i++){
            if(m[v[i]]==NULL){ // not yet visited
                // clone it and mark it
                newnode = new UndirectedGraphNode(v[i]->label);
                m[v[i]] = newnode;
                // push the original onto the queue
                q.push(v[i]);
            }
            // put those neighbors on the cloned graph node
            m[u]->neighbors.push_back(m[v[i]]);
        }
        
    }
    return m[node];

}

