static SinglyLinkedListNode insertNodeAtHead(SinglyLinkedListNode llist, int data) {
    SinglyLinkedListNode newnode = new SinglyLinkedListNode(data);
    
    if(llist == null){
        llist = newnode;
        return llist;
    }
    
    newnode.next = llist;
    return newnode;
}