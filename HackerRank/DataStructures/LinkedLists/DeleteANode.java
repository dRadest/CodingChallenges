static SinglyLinkedListNode deleteNode(SinglyLinkedListNode head, int position) {
    if(position == 0){
        return head.next;
    }
        
    SinglyLinkedListNode temp = head;
    while(position > 1){
        temp = temp.next;
        position--;
    }
    temp.next = temp.next.next;
    return head;
}