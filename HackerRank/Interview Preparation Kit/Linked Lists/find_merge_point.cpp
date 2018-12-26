/*
   Find merge point of two linked lists
   Node is defined as
   struct Node
   {
       int data;
       Node* next;
   }
*/
int FindMergeNode(Node *headA, Node *headB)
{
    // Complete this function
    // Do not write the main method. 
    Node* curA = headA;
    Node* curB = headB;
    while(curA != curB){
        if(curA->next == NULL)
            curA = headB;
        else
            curA = curA->next;
        if(curB->next == NULL)
            curB = headA;
        else
            curB = curB -> next;
    }
    return curB -> data;
}
