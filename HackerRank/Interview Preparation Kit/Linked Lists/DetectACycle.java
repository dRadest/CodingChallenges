/*
Detect a cycle in a linked list. Note that the head pointer may be 'null' if the list is empty.

A Node is defined as: 
    class Node {
        int data;
        Node next;
    }
*/

boolean hasCycle(Node head) {
    if (head == null) return false;
    
    Node currNode = head;
    Set<Node> seen = new HashSet<>();
    while (currNode != null) {
        seen.add(currNode);
        currNode = currNode.next;
        if (seen.contains(currNode)) return true;
    }
    return false;
}


