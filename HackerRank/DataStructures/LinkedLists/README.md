# Contents
* [Basics](#basics)
	- [Definitions](#singly-linked-lists-definitions)
* [Solutions](#solutions)
	- [Print the Elements](#print-the-elements-of-a-inked-list)
	- [Insert at the Tail](#insert-a-node-at-the-tail-of-a-linked-list)
	- [Insert at the Head](#insert-a-node-at-the-head-of-a-linked-list)
	- [Insert at a Position](#insert-a-node-at-a-specific-position-in-a-linked-list)
	- [Delete a Node](#delete-a-node-from-a-linked-list)
	- [Print in Reverse](#print-in-reverse)
# Basics

### Singly Linked Lists Definitions

Node and Linked List in...

...C
```c
struct SinglyLinkedListNode {
    int data;
    SinglyLinkedListNode* next;
};

struct SinglyLinkedList {
    SinglyLinkedListNode* head;
    SinglyLinkedListNode* tail; 
    /* some implementation use field int size 
    	instead of a pointer to the tail node*/
};
```

...C++
```c++
class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
            }

            this->tail = node;
        }
};
```

...Java
```java
static class SinglyLinkedListNode {
    public int data;
    public SinglyLinkedListNode next;

    public SinglyLinkedListNode(int nodeData) {
        this.data = nodeData;
        this.next = null;
    }
}

static class SinglyLinkedList {
    public SinglyLinkedListNode head;
    public SinglyLinkedListNode tail;

    public SinglyLinkedList() {
        this.head = null;
        this.tail = null;
    }

    public void insertNode(int nodeData) {
        SinglyLinkedListNode node = new SinglyLinkedListNode(nodeData);

        if (this.head == null) {
            this.head = node;
        } else {
            this.tail.next = node;
        }

        this.tail = node;
    }
}
```

# Solutions

### Print the Elements of a Linked List

Problem on [HackerRank](https://www.hackerrank.com/challenges/print-the-elements-of-a-linked-list/problem)

traverse through the linked list
```
while(node != null){
	node = node -> next
}
```
file:

C [print_elements.c](print_elements.c)

C++ [print_elements.cpp](print_elements.cpp)

Java [Printelements.java](PrintElements.java)

recursive solution (Java)
```java
static void printLinkedList(SinglyLinkedListNode head) {
    if(head == null){
        return;
    }
    else{
        System.out.println(head.data);
        printLinkedList(head.next);
    }

}
```

### Insert a Node at the Tail of a Linked List

Problem on [HackerRank](https://www.hackerrank.com/challenges/insert-a-node-at-the-tail-of-a-linked-list/problem)

pseudocode
```
new_node=new Node
(*new_node).val=new_value
(*new_node).next=NULL

ptr=head

if ptr is NULL  //Empty List
    head=new_node
else
    ptr=head

    //Traverse till the last node

    while((*ptr).next!=NULL)
    ptr=(*ptr).next

    //Now ptr points to the last node of the list
    (*ptr).next=new_node
```
file:

C [insert_at_tail.c](insert_at_tail.c)

C++ [insert_at_tail.cpp](insert_at_tail.cpp)

Java [InsertAtTail.java](InsertAtTail.java)

### Insert a Node at the Head of a Linked List

Problem on [HackerRank](https://www.hackerrank.com/challenges/insert-a-node-at-the-head-of-a-linked-list/problem)

file:

C [insert_at_head.c](insert_at_head.c)

C++ [insert_at_head.cpp](insert_at_head.cpp)

Java [InsertAtHead.java](InsertAtHead.java)

### Insert a Node at a Specific Position in a Linked List

Problem on [HackerRank](https://www.hackerrank.com/challenges/insert-a-node-at-a-specific-position-in-a-linked-list/problem)

file: Java [InsertAtPosition.java](InsertAtPosition.java)

### Delete a Node From a Linked List

Problem on [HackerRank](https://www.hackerrank.com/challenges/delete-a-node-from-a-linked-list/problem)

file: Java [DeleteANode.java](DeleteANode.java)

recursive solution (Java)
```java
Node Delete(Node head, int position) {
    if(position == 0)
        return head.next;
    head.next = Delete(head.next, position-1);
    return head;
}
```

### Print in Reverse

Problem on [HackerRank](https://www.hackerrank.com/challenges/print-the-elements-of-a-linked-list-in-reverse/problem)

file: Java [PrintInReverse.java](PrintInReverse.java)