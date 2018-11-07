static SinglyLinkedListNode insertNodeAtTail(SinglyLinkedListNode head, int data) {
    SinglyLinkedListNode newnode = new SinglyLinkedListNode(data);
    
    if(head == null){
        head = newnode;
        return head;
    }
    
    SinglyLinkedListNode temp = head;
    while(temp.next != null){
        temp = temp.next;
    }
    temp.next = newnode;
    return head;
}