/*
* https://www.interviewbit.com/problems/sort-list/
* Sort a linked list in O(n log n) time using constant space complexity.
*
* idea: use merge sort
* geeksforgeeks:
* https://www.geeksforgeeks.org/merge-sort-for-linked-list/
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 // merges two linked lists in ASC order
 // return pointer to head of a merged list
 ListNode* merge(ListNode* A, ListNode* B){
    if(A == NULL){
        return B;
    }
    if(B == NULL){
        return A;
    }
    
    ListNode* head = NULL;
    
    // start with smaller element and move to next in the list
    if(A->val < B->val){
        head = A;
        A = A->next;
    }
    else{
        head = B;
        B = B->next;
    }
    
    ListNode* temp = head;
    
    // traverse both linked lists
    while(A != NULL && B != NULL){
        // insert A before B
        if(A->val < B->val){
            temp->next = A;
            A = A->next;
        }
        // insert B before A
        else{
            temp->next = B;
            B = B->next;
        }
        temp = temp->next;
    }
    
    // last element
    if(A != NULL){
        temp->next = A;
    }
    else{
        temp->next = B;
    }
    
    return head;
} 
// using merge sort logic
ListNode* Solution::sortList(ListNode* A) {
    ListNode* head = A;

    // zero or one element
    if(head == NULL || head->next == NULL){
        return head;
    }
    
    ListNode* start = A;
    ListNode* end = A->next;
    // move to the end w/ one node between start and end
    while(end != NULL && end->next != NULL){
        start = start->next;
        end = (end->next)->next;
    }
    
    end = start->next;
    start->next = NULL;
    
    return merge(sortList(head), sortList(end)); 
}
