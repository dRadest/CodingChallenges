/*
* https://www.interviewbit.com/problems/add-two-numbers-as-lists/
* 
* You are given two linked lists representing two non-negative numbers. 
* The digits are stored in reverse order and each of their nodes contain a single digit. 
* Add the two numbers and return it as a linked list.
*
* Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
* Output: 7 -> 0 -> 8
* 342 + 465 = 807
*
* Make sure there are no trailing zeros in the output list
* So, 7 -> 0 -> 8 -> 0 is not a valid response even though the value is still 807.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
	// when one of the lists is empty
    if(!A)
        return B;
    if(!B)
        return A;
        
    int carry = 0, sum = 0;
    // sum of values of nodes in first position
    sum = A->val + B->val + carry;
    ListNode* newHead = new ListNode(sum%10);
    carry = sum/10;
    A = A->next;
    B = B->next;
    ListNode* newHeadPtr = newHead;
    
    while(A || B || carry)
    {
    	// sum at current position
        sum = (A ? A->val : 0) + (B ? B->val : 0) + carry;
        // create temp node with base value (sum%10)
        ListNode* temp = new ListNode(sum%10);
        // carry for next calculation
        carry = sum/10;
        newHead->next = temp;
        // advance newHead
        newHead = newHead->next;
        // advance positions in both lists accordingly
        if(A)
            A = A->next;
        if(B)
            B = B->next;
    }
    
	return newHeadPtr;
}
