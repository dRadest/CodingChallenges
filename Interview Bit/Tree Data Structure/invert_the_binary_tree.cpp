/*
*
* https://www.interviewbit.com/problems/invert-the-binary-tree/
*
* Given a binary tree, invert the binary tree and return it.
* Look at the example for more details.
*
*	Example :
*	Given binary tree
*
*	     1
*	   /   \
*	  2     3
*	 / \   / \
*	4   5 6   7
*
*	invert and return
*	
*	     1
*	   /   \
*	  3     2
*	 / \   / \
*	7   6 5   4
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

// traverse all the way down to leaf nodes 
// of left and right subtree
// swap nodes as you move back up
void swap(TreeNode* root){
    if(root == NULL){
        return;
    }
    TreeNode* temp;
    swap(root->left);
    swap(root->right);
    // actual swapping
    temp = root->left;
    root->left = root->right;
    root->right = temp;
}
TreeNode* Solution::invertTree(TreeNode* A) {
    swap(A);
    return A;
}

