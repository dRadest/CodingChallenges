/*
*
* https://www.interviewbit.com/problems/max-sum-path-in-binary-tree/
*
* Given a binary tree, find the maximum path sum.
*
* The path may start and end at any node in the tree.
*
* Example :
*
*	Given the below binary tree,
*
*       1
*      / \
*     2   3
*
* geeksforgeeks:
* https://www.geeksforgeeks.org/find-maximum-path-sum-in-a-binary-tree/
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
 
// This function returns overall maximum path sum in 'res' 
// And returns max path sum going through root. 
int findMaxUtil(TreeNode* root, int &res) 
{ 
    //Base Case 
    if (root == NULL) 
        return 0; 
  
    // l and r store maximum path sum going through left and 
    // right child of root respectively 
    int l = findMaxUtil(root->left,res); 
    int r = findMaxUtil(root->right,res); 
  
    // Max path for parent call of root. This path must 
    // include at-most one child of root 
    int max_single = max(max(l, r) + root->val, root->val); 
  
    // Max Top represents the sum when the Node under 
    // consideration is the root of the maxsum path and no 
    // ancestors of root are there in max sum path 
    int max_top = max(max_single, l + r + root->val); 
  
    res = max(res, max_top); // Store the Maximum Result. 
  
    return max_single; 
} 
int Solution::maxPathSum(TreeNode* A) {
    // Initialize result 
    int res = INT_MIN; 
  
    // Compute and return result 
    findMaxUtil(A, res); 
    return res; }

