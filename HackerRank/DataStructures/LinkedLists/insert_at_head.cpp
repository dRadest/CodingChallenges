SinglyLinkedListNode* insertNodeAtHead(SinglyLinkedListNode* llist, int data) {
    SinglyLinkedListNode* newnode = new SinglyLinkedListNode(data);
    
    if(llist == nullptr){
        llist = newnode;
        return llist;
    }
    
    newnode -> next = llist;
    return newnode;
}