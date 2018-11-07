static SinglyLinkedListNode insertNodeAtPosition(SinglyLinkedListNode head, int data, int position) {
    SinglyLinkedListNode newnode = new SinglyLinkedListNode(data);
        
    if(head == null){
        return newnode;
    }
        
    if(position == 0){
        newnode.next = head;
        return newnode;
    }
        
    SinglyLinkedListNode temp = head;
    while(position > 1){
        temp = temp.next;
        position--;
    }
    newnode.next = temp.next;
    temp.next = newnode;
    return head;
}