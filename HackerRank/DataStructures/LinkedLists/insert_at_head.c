SinglyLinkedListNode* insertNodeAtHead(SinglyLinkedListNode* llist, int data) {
    SinglyLinkedListNode* newnode = (SinglyLinkedListNode*)malloc(sizeof(SinglyLinkedListNode));
    newnode -> data = data;
    newnode -> next = NULL;
    
    if(llist == NULL){
        llist = newnode;
        return llist;
    }
    
    newnode -> next = llist;
    return newnode;
}