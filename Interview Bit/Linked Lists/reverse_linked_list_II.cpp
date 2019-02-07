/*
* https://www.interviewbit.com/problems/reverse-link-list-ii/
*
* Reverse a linked list from position m to n. Do it in-place and in one-pass.
*
* For example:
* Given 1->2->3->4->5->NULL, m = 2 and n = 4,
*
* return 1->4->3->2->5->NULL.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseBetween(ListNode* A, int m, int n) {
    if (!A)
        return NULL;
    if(m==n)
        return A;
    ListNode *temp, *current, *prev, *next, *start, *end;
    int pos = 1;
    temp = A;
    // reversing from 1st position?
    bool flag = false;
    if(m==1)
        flag = true;
    // mark starting position (head)
    // move temp to starting position to reverse from
    while(pos<m)
    {
        start = temp; //(m-1)th node
        temp = temp->next;
        ++pos;
    }
    // start reversing at this position
    current = next = temp;
    
    // move temp to ending position for reversing
    while(pos<n)
    {
        temp = temp->next;
        ++pos;
    }
    end = temp; // nth node
    prev = temp->next;
    ListNode *endplus = end->next;
    // reverse nodes in given range
    while(current != endplus)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    if(m==1)// started with first node
        A = prev;
    else
        start->next = prev;
    return A;
}
