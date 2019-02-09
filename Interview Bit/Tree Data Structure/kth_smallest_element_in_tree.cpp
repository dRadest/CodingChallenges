/*
*
* https://www.interviewbit.com/problems/kth-smallest-element-in-tree/
*
* Given a binary search tree, write a function to find the kth smallest element in the tree.
* 
* Example :
* 
*	Input : 
*	  2
*	 / \
*	1   3
*
*	and k = 2
*
*	Return : 2
*
* As 2 is the second smallest element in the tree.
* 
*    NOTE : You may assume 1 <= k <= Total number of nodes in BST 
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
vector<int> invec;
void inorder(TreeNode* root){
    if(root -> left != NULL){
        inorder(root->left);
    }
    invec.push_back(root->val);
    if(root -> right != NULL){
        inorder(root->right);
    }
}
// do inorder traversal and return element at index (B-1)
int Solution::kthsmallest(TreeNode* A, int B) {
    invec.clear();
    inorder(A);
    return invec[B-1];
}



