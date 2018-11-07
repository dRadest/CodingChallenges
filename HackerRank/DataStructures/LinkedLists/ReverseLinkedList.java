static SinglyLinkedListNode reverse(SinglyLinkedListNode head) {
    if (head == null){
        return head;
    }
    SinglyLinkedListNode prev = head;
    SinglyLinkedListNode cur = head.next;
    SinglyLinkedListNode nxt = cur.next;
    prev.next = null;
    while(nxt != null){
        cur.next = prev;
        prev = cur;
        cur = nxt;
        nxt = nxt.next;
    }
    head = cur;
    head.next = prev;
    return head;
}