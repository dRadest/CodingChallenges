/*
* https://www.interviewbit.com/problems/max-depth-of-binary-tree/
*
*
* Given a binary tree, find its maximum depth.
*
* The maximum depth of a binary tree is the number of nodes along the longest path from the root node down to the farthest leaf node.
*
*   NOTE : The path has to end on a leaf node. 
*
* Example :
*
*         1
*        /
*       2
*
* max depth = 2.
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
int depth(TreeNode* node){
    if(node== NULL){
        return 0;
    }
    return 1+max(depth(node->left), depth(node->right));
}
int Solution::maxDepth(TreeNode* A) {
    int d = depth(A);
    return d;
}
