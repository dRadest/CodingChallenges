/*
* https://www.interviewbit.com/problems/valid-binary-search-tree/
*
* Given a binary tree, determine if it is a valid binary search tree (BST).
*
* Assume a BST is defined as follows:
*
*    1. The left subtree of a node contains only nodes with keys less than the node’s key.
*    2. The right subtree of a node contains only nodes with keys greater than the node’s key.
*    3. Both the left and right subtrees must also be binary search trees.
*
* Example :
*	Input : 
*	   1
*	  /  \
*	 2    3
*
*	Output : 0 or False
*
*
*	Input : 
*	  2
*	 / \
*	1   3
*
*	Output : 1 or True 
*
* Return 0 / 1 ( 0 for false, 1 for true ) for this problem
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


/* OPTION 1: recursive solution
	int isValidUtil(TreeNode* root, int minValue, int maxValue){
		if(root == NULL) return 1;
	 	if(root->val > minValue
	 		&& root->val < maxValue
	 		&& isValidUtil(root->left, minValue, root->val)
	 		&& isValidUtil(root->right, root->val, maxValue)){
	    return 1;
	 }
	return 0;
 }
 */

 /* OPTION 2: inorder traversal should yield nondescending order of elements
  				store result of inorder tree traversal */
vector<int> itrav;
void inorder(TreeNode* root){
    if(root->left != NULL){
        inorder(root->left);
    }
    itrav.push_back(root->val);
    if(root->right != NULL){
        inorder(root->right);
    }
}
int isNonDescending(vector<int> vec){
    for(int i=1; i<vec.size(); i++){
        if(vec[i] < vec[i-1]){
            return 0;
        }
    }
    return 1;
}
int Solution::isValidBST(TreeNode* A) {
    itrav.clear();
    inorder(A);
    return isNonDescending(itrav);
    //return isValidUtil(A, INT_MAX, INT_MIN);
}
