/*
*
* https://www.interviewbit.com/problems/sorted-array-to-balanced-bst/
*
* Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
*
*    Balanced tree : a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1. 
*
* Example :
*
* Given A : [1, 2, 3]
* A height balanced BST  : 
*
*      2
*    /   \
*   1     3
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
 
TreeNode* arrayToBSTUtil(const vector<int> &A, int start, int end){
	// base case
    if(start>end){
        return NULL;
    }
    // get a mid point
    int mid = end - (end-start)/2;
    TreeNode* root = new TreeNode(A[mid]);
    // recur left
    root->left=arrayToBSTUtil(A, start, mid-1);
    // recur right
    root->right = arrayToBSTUtil(A, mid+1, end);
    return root;
}
TreeNode* Solution::sortedArrayToBST(const vector<int> &A) {
    return arrayToBSTUtil(A, 0, A.size()-1);
    
}

