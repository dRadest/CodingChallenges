/*
* https://www.interviewbit.com/problems/next-greater-number-bst/
*
* Given a BST node, return the node which has value just greater than the given node.
*
* Example:
*
* Given the tree
*               100
*              /   \
*            98    102
*           /  \
*         96    99
*          \
*           97
*
* Given 97, you should return the node corresponding to 98 as thats the value just greater than 97 in the tree.
* If there are no successor in the tree ( the value is the largest in the tree, return NULL).
*
* Using recursion is not allowed.
* 
* Assume that the value is always present in the tree.
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
// Function to find the node with a given value
 TreeNode* Find(TreeNode* root, int data) {
    if(root == NULL) return NULL;
    else if(root->val == data) return root;
    else if(root->val < data) return Find(root->right,data);
    else return Find(root->left,data);
}
// Function to find the node with minimum value in a BST
struct TreeNode* FindMin(struct TreeNode* root) {
    if(root == NULL) return NULL;
    // go down left as possible
    while(root->left != NULL)
        root = root->left;
    return root;
}
TreeNode* Solution::getSuccessor(TreeNode* A, int B) {
    // Search the Node - O(h)
    struct TreeNode* current = Find(A,B);
    if(current == NULL) return NULL;
    if(current->right != NULL) {  //Case 1: Node has right subtree
        return FindMin(current->right); // O(h)
    }
    else {   //Case 2: No right subtree  - O(h)
        struct TreeNode* successor = NULL;
        struct TreeNode* ancestor = A;
        // traverse down the tree until current reached
        while(ancestor != current) {
            if(current->val < ancestor->val) {
                successor = ancestor; // so far this is the deepest node for which current node is in left
                ancestor = ancestor->left;
            }
            else
                ancestor = ancestor->right;
        }
        return successor;
    }
}
