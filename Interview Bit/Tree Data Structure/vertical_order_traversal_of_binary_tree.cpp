/*
* https://www.interviewbit.com/problems/vertical-order-traversal-of-binary-tree/
*
* Given a binary tree, return a 2-D array with vertical order traversal of it.
* Go through the example and image for more details.
*
* Example :
*	Given binary tree:
*
*	      6
*	    /   \
*	   3     7
*	  / \     \
*	 2   5     9
*
* returns
*
*	[
*	    [2],
*	    [3],
*	    [6 5],
*	    [7],
*	    [9]
*	]
*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// node struct that keeps distance value from the root
struct node{
    TreeNode* root;
    int dis;
};

// map dis ---> list of nodes
void make(map<int, vector<int> >& m, queue<node>& q){
    if(q.size() == 0){
        return;
    }
    
    TreeNode* root = (q.front()).root;
    int dis = (q.front()).dis;
    
    if(!root){
        return;
    }
    
    m[dis].push_back(root->val);
    
    q.pop();
    // has left subtree
    if(root->left){
        node l1;
        l1.root =  root->left;
        l1.dis = dis-1;
        q.push(l1);
    }
    // has right subtree
    if(root->right){
        node l1;
        l1.root =  root->right;
        l1.dis = dis+1;
        q.push(l1);
    }
    
    make(m, q);
}
vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* A) {
    map<int, vector<int> > m; // dis -> list of nodes
    vector<vector<int> > sol;
    queue<node> q;
    
    // push root node onto the queue
    node n;
    n.root = A;
    n.dis = 0;
    
    q.push(n);
    
    make(m, q);
    
    map<int, vector<int> > :: iterator it = m.begin();
    // marks line number starting from far left
    int curr = 0;
    
    while(it != m.end()){
        vector<int> temp;
        sol.push_back(temp);
        
        temp = it->second;
        
        for(int i = 0; i < temp.size(); i++){
            sol[curr].push_back(temp[i]);
        }
        
        curr++;
        it++;
    }
    
    return sol;
}
