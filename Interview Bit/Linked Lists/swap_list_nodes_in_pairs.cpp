/*
* https://www.interviewbit.com/problems/swap-list-nodes-in-pairs/
* Given a linked list, swap every two adjacent nodes and return its head.
*
* For example,
* Given 1->2->3->4, you should return the list as 2->1->4->3.
* 
* Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// swaps nodes next1 and next2
ListNode* swap(ListNode* next1, ListNode* next2) {
    next1->next = next2->next;
    next2->next = next1;
    return next2;
}
ListNode* Solution::swapPairs(ListNode* A) {
    ListNode* start = new ListNode(0); //make head no longer a special case
    start->next = A;

    ListNode *cur = start;
    while (cur->next != NULL && cur->next->next != NULL) {
        cur->next = swap(cur->next, cur->next->next);
        cur = cur->next->next; // advance by two
    }
    return start->next;

}
