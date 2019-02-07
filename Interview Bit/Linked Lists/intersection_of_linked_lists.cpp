/*
* https://www.interviewbit.com/problems/intersection-of-linked-lists/
* Write a program to find the node at which the intersection of two singly linked lists begins.
* 
* mycodeschool:
* https://youtu.be/gE0GopCq378
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 // returns the length of a linked list
 int length(ListNode* A){
     int len = 0;
     while(A -> next != NULL){
         len++;
         A = A -> next;
     }
     return len;
 }
ListNode* Solution::getIntersectionNode(ListNode* A, ListNode* B) {
    if(!A || !B){
        return NULL;
    }
    int m = length(A);
    int n = length(B);
    int d = n - m;
    if(m > n){
        // swap A and B
        struct ListNode* temp = A;
        A = B;
        B = temp;
        d = m - n;
    }
    // skip the first d elements
    for(int i=0; i<d; i++){
        B = B -> next;
    }
    // compare each node
    while(A != NULL && B != NULL){
        if(A == B){
            return A;
        }
        A = A -> next;
        B = B -> next;
    }
    return NULL;
}
