/*
* https://www.interviewbit.com/problems/remove-duplicates-from-sorted-list/
* Given a sorted linked list, delete all duplicates such that each element appear only once.
*
* For example,
* Given 1->1->2, return 1->2.
* Given 1->1->2->3->3, return 1->2->3.
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 

ListNode* Solution::deleteDuplicates(ListNode* A) {
    if(!A || !A->next)
        return A;
        
    ListNode* head = A;
    while(A->next)
    {
        if(A->val == A->next->val){
            // skip repeating elements
            A->next = A->next->next;
        }
        else // advance to next node
            A = A->next;
    }
    return head;
}
