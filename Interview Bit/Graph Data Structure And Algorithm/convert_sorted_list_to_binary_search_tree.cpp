/*
*
* https://www.interviewbit.com/problems/convert-sorted-list-to-binary-search-tree/
*
* Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
*
*    A height balanced BST : a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1. 
*
* Example :
*
*	Given A : 1 -> 2 -> 3
*	A height balanced BST  :
*
*	      2
*	    /   \
*	   1     3
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
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// constructs a BST in an inorder fashion
TreeNode* makeBST(ListNode* &node, int start, int end){
    if(start > end){ // base case
        return NULL;
    }
    // calculate mid point
    int mid = start + (end-start)/2;
    // construct a left subtree from nodes in the first half of the list
    TreeNode* leftsub = makeBST(node, start, mid-1);
    TreeNode* root = new TreeNode(node->val);
    node = node -> next;
    // construct a right subtree from nodes in the second half of the list
    TreeNode* rightsub = makeBST(node, mid+1, end);
    root->left = leftsub;
    root->right = rightsub;
    return root;
}
TreeNode* Solution::sortedListToBST(ListNode* A) {
    if(A == NULL) return NULL;
    // calculate the length of the list
    int len = 0;
    ListNode* current = A;
    while(current != NULL){
        len++;
        current = current->next;
    }
    return makeBST(A, 0, len-1);
}
