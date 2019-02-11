/*
*
* https://www.interviewbit.com/problems/level-order/
*
* Given a binary tree, return the level order traversal of its nodes’ values. (ie, from left to right, level by level).
*
* Example :
*	Given binary tree
*
*	    3
*	   / \
*	  9  20
*	    /  \
*	   15   7
*
*	return its level order traversal as:
*
*	[
*	  [3],
*	  [9,20],
*	  [15,7]
*	]
*
* Also think about a version of the question where you are asked to do a level order traversal of the tree 
* when depth of the tree is much greater than number of nodes on a level.
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
vector<vector<int> > Solution::levelOrder(TreeNode* A) {
    vector<vector<int> > ans;
    vector<int> temp;
    queue<TreeNode*> q;
    queue<int> level;
    
    if(A == NULL){
        return ans;
    }
    
    q.push(A);
    level.push(0);
    
    while(!q.empty()){
        // examine the node at the front of the queue
        TreeNode* curr = q.front();
        int lev = level.front(); // current level
        // next level reached
        if(ans.size() != lev+1){
            ans.push_back(temp);
        }
        // push current value to the answer vector
        ans[lev].push_back(curr->val);
        // update queues for left and right child
        if(curr->left != NULL){
            q.push(curr->left);
            level.push(lev+1);
        }
        if(curr->right != NULL){
            q.push(curr->right);
            level.push(lev+1);
        }
        q.pop();
        level.pop();
    }
    
    return ans;
}
