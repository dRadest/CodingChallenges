/*
*
* https://www.interviewbit.com/problems/flatten-binary-tree-to-linked-list/
*
*
*
* Given a binary tree, flatten it to a linked list in-place.
*
* Example :
* 	Given
*
*         1
*        / \
*       2   5
*      / \   \
*     3   4   6
*
* The flattened tree should look like:
*
*   1
*    \
*     2
*      \
*       3
*        \
*         4
*          \
*           5
*            \
*             6
*
* Note that the left child of all nodes should be NULL.
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
// Function to convert binary tree into 
// linked list by altering the right node 
// and making left node point to NULL 
void flattenUtil(struct TreeNode* root) 
{ 
    // base condition- return if root is NULL 
    // or if it is a leaf node 
    if (root == NULL || root->left == NULL && 
                        root->right == NULL) { 
        return; 
    } 
  
    // if root->left exists then we have  
    // to make it root->right 
    if (root->left != NULL) { 
  
        // move left recursively 
        flattenUtil(root->left); 
     
        // store the node root->right 
        struct TreeNode* tmpRight = root->right; 
        root->right = root->left; 
        root->left = NULL; 
  
        // find the position to insert 
        // the stored value    
        struct TreeNode* t = root->right; 
        while (t->right != NULL) { 
            t = t->right; 
        } 
  
        // insert the stored value 
        t->right = tmpRight; 
    } 
  
    // now call the same function 
    // for root->right 
    flattenUtil(root->right); 
} 
TreeNode* Solution::flatten(TreeNode* A) {
    flattenUtil(A);
    return A;
    
}

