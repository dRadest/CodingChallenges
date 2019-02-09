/*
* https://www.interviewbit.com/problems/zigzag-level-order-traversal-bt/
*
* Given a binary tree, return the zigzag level order traversal of its nodes’ values. 
* (ie, from left to right, then right to left for the next level and alternate between).
*
* Example :
*	Given binary tree
*	    3
*	   / \
*	  9  20
*	    /  \
*	   15   7
*
* return
*	[
*	     [3],
*	     [20, 9],
*	     [15, 7]
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
void levelorder(TreeNode* root, vector<vector<int>> &ans, bool left, int level){
    if(root == NULL){ // base case
        return;
    }
    // no input for this level yet
    if(ans.size()<level){
        vector<int> temp;
        ans.push_back(temp);
    }
    // push values depending on the flag
    if(left){ // left to right
        ans[level-1].push_back(root->val);
    }else{ // right to left
        ans[level-1].insert(ans[level-1].begin(), root->val);
    }
    // traverse left and right subtree
    levelorder(root->left, ans, !left, level+1);
    levelorder(root->right, ans, !left, level+1);
}
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
    vector<vector<int>> ans;
    levelorder(A, ans, true, 1);
    return ans;
}
