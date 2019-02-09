/*
* https://www.interviewbit.com/problems/identical-binary-trees/
*
* Given two binary trees, write a function to check if they are equal or not.
*
* Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
* 
* Return 0 / 1 ( 0 for false, 1 for true ) for this problem
*
* Example :
*
*	Input : 
*
*	   1       1
*	  / \     / \
*	 2   3   2   3
*
*	Output :
* 
*  1 or True
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

void inorder(TreeNode* root, vector<int> &vec){
   if(root == NULL){
       return;
   }
   inorder(root->left, vec);
   vec.push_back(root->val);
   inorder(root->right, vec);
}
// inorder traversal should yield the same result
int Solution::isSameTree(TreeNode* A, TreeNode* B) {
    vector<int> one;
    vector<int> two;
    inorder(A, one);
    inorder(B, two);
    if(one == two){
        return 1;
    }
    return 0;
}

