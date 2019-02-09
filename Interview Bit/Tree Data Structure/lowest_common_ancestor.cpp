/*
*
* https://www.interviewbit.com/problems/least-common-ancestor/
*
* Find the lowest common ancestor in an unordered binary tree given two values in the tree.
*
*   Lowest common ancestor : 
* 		the lowest common ancestor (LCA) of two nodes v and w in a tree or directed acyclic graph (DAG) 
*		is the lowest (i.e. deepest) node that has both v and w as descendants. 
*
*	Example :
*
*
*       _______3______
*       /              \
*    ___5__          ___1__
*   /      \        /      \
*   6      _2_     0        8
*         /   \
*         7    4
*
* For the above tree, the LCA of nodes 5 and 1 is 3.
*
*    LCA = Lowest common ancestor 
*
* Please note that LCA for nodes 5 and 4 is 5.
* 
*        You are given 2 values. Find the lowest common ancestor of the two nodes represented by val1 and val2
*        No guarantee that val1 and val2 exist in the tree. If one value doesn’t exist in the tree then return -1.
*        There are no duplicate values.
*        You can use extra memory, helper functions, and can modify the node struct but, you can’t add a parent pointer.
*
* geeksforgeeks:
* https://www.geeksforgeeks.org/lowest-common-ancestor-binary-tree-set-1/
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
// Returns true if value k is present in tree rooted with root 
bool find(TreeNode* root, int k) { 
    // Base Case 
    if (root == NULL) 
        return false; 
  
    // If key is present at root, or in left subtree or right subtree, 
    // return true; 
    if (root->val == k || find(root->left, k) ||  find(root->right, k)) 
        return true; 
  
    // Else return false 
    return false; 
} 
// This function returns pointer to LCA of two given values n1 and n2. 
// v1 is set as true by this function if n1 is found 
// v2 is set as true by this function if n2 is found 
TreeNode* findLCAUtil(TreeNode* root, int n1, int n2, bool &v1, bool &v2) { 
    // Base case 
    if (root == NULL) return NULL; 
  
    // If either n1 or n2 matches with root's key, report the presence 
    // by setting v1 or v2 as true and return root (Note that if a key 
    // is ancestor of other, then the ancestor key becomes LCA) 
    if (root->val == n1) { 
        v1 = true; 
        return root; 
    } 
    if (root->val == n2) { 
        v2 = true; 
        return root; 
    } 
  
    // Look for keys in left and right subtrees 
    TreeNode* left_lca  = findLCAUtil(root->left, n1, n2, v1, v2); 
    TreeNode* right_lca = findLCAUtil(root->right, n1, n2, v1, v2); 
  
    // If both of the above calls return Non-NULL, then one key 
    // is present in once subtree and other is present in other, 
    // So this node is the LCA 
    if (left_lca && right_lca)  return root; 
  
    // Otherwise check if left subtree or right subtree is LCA 
    return (left_lca != NULL)? left_lca: right_lca; 
} 
int Solution::lca(TreeNode* A, int B, int C) {
    // Initialize n1 and n2 as not visited 
    bool v1 = false, v2 = false; 
  
    // Find lca of n1 and n2 using the technique discussed above 
    TreeNode* lca = findLCAUtil(A, B, C, v1, v2); 
  
    // Return LCA only if both n1 and n2 are present in tree 
    if (v1 && v2 || v1 && find(lca, C) || v2 && find(lca, B)) 
        return lca->val; 
  
    // Else return NULL 
    return -1; 
}
