SinglyLinkedListNode* insertNodeAtTail(SinglyLinkedListNode* head, int data) {
    SinglyLinkedListNode* newnode = (SinglyLinkedListNode*)malloc(sizeof(SinglyLinkedListNode));
    newnode -> data = data;
    newnode -> next = NULL;

    if(head == NULL){
        head = newnode;
        return head;
    }
    
    SinglyLinkedListNode* temp = head;
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    temp -> next = newnode;
    return head;
}