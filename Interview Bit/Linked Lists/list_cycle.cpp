/*
* https://www.interviewbit.com/problems/list-cycle/
*
* Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
*
* Try solving it using constant additional space.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::detectCycle(ListNode* A) {
    if(!A || !A->next)
        return NULL;
    ListNode* slow, *fast;      //Floyd's cycle finding algorithm
    slow = fast = A;
    while (fast)    //if you give condn slow!=fast; it's wrong since slow=fast=A initially.
    {
        if (!fast->next || !fast->next->next)
            return NULL;
        slow = slow->next;
        fast = fast->next->next; 
        if(slow==fast)
            break;
    }
    slow = A;
    while(slow!=fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}
