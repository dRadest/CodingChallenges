SinglyLinkedListNode* insertNodeAtTail(SinglyLinkedListNode* head, int data) {
    SinglyLinkedListNode* newnode = new SinglyLinkedListNode(data);
    
    if(head == nullptr){
        head = newnode;
        return head;
    }
    
    SinglyLinkedListNode* temp = head;
    while(temp -> next != nullptr){
        temp = temp -> next;
    }
    temp -> next = newnode;
    return head;
}