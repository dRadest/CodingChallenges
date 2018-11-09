# Contents

* [Basics](#basics)
 	- [Node definition](#node-in-a-tree-defined-as)
 	- [Tree traversals](#tree-traversals)
 		+ [Tree Height](#tree-height)
* [Solutions](#solutions)
	- [Top View](#top-view)
	- [Is This a Binary Search Tree?](#is-this-a-binary-search-tree)
	- [Swap Nodes](#swap-nodes)





# Basics

#### Node in a tree defined as
```c
struct node {
    
    int data;
    struct node *left;
    struct node *right;
  
};
```

#### Tree traversals

* __PRE__-order

	_root-left-right_
```c
void preOrder( struct node *root) {
    printf("%d ", root -> data);
    if(root -> left != NULL){
        preOrder(root -> left);
    }
    if(root -> right != NULL){
        preOrder(root -> right);
    }
}
```

* __IN__-order

	_left-root-right_
```c
void inOrder( struct node *root) {
    if(root -> left != NULL){
        inOrder(root -> left);
    }
    printf("%d ", root -> data);
    if(root -> right != NULL){
        inOrder(root -> right);
    }
}
```

* __POST__-order

	_left-right-root_
```c
void postOrder( struct node *root) {
    if(root -> left != NULL){
        postOrder(root -> left);
    }
    if(root -> right != NULL){
        postOrder(root -> right);
    }
    printf("%d ", root -> data);

}
```

Tutorialspoint [tutorial](https://www.tutorialspoint.com/data_structures_algorithms/tree_traversal.htm) on tree traversal


##### Tree Height

Tree height is the number of edges between its root and furthest leaf.

```c
// return number of edges between root and leaf (inclusive)
int getHeight(struct node* root) {
    if(root == NULL){
        return -1; // return 0 for number of nodes
    }else {
        int lheight = getHeight(root -> left);
        int rheight = getHeight(root -> right);
        
        if(lheight > rheight){
            return (lheight + 1);
        } else{
            return (rheight + 1);
        }
    }   
}
```

* __LEVEL__-order

```c
// returns number of nodes from root to leaf (inclusive)
int getHeight(struct node* root) {
    if(root == NULL){
        return 0;
    }else {
        int lheight = getHeight(root -> left);
        int rheight = getHeight(root -> right);
        
        if(lheight > rheight){
            return (lheight + 1);
        } else{
            return (rheight + 1);
        }
    }   
}

// prints nodes at the given level
void printGivenLevel(struct node* root, int level) 
{ 
    if (root == NULL) 
        return; 
    if (level == 1) 
        printf("%d ", root->data); 
    else if (level > 1) 
    { 
        printGivenLevel(root->left, level-1); 
        printGivenLevel(root->right, level-1); 
    } 
} 

// print level order traversal of a tree
void levelOrder( struct node *root) {
    int h = getHeight(root); 
    int i; 
    for (i=1; i<=h; i++) 
        printGivenLevel(root, i); 
}
```

Code adopted from GeeksforGeeks [article](https://www.geeksforgeeks.org/level-order-tree-traversal/)


# Solutions
#### Top View

Problem on [HackerRank](https://www.hackerrank.com/challenges/tree-top-view/problem)

file: C++ [top_view.cpp](top_view.cpp)

GeeksforGeeks [article](https://www.geeksforgeeks.org/print-nodes-top-view-binary-tree/) on top view

#### Is This a Binary Search Tree?

Problem on [HackerRank](https://www.hackerrank.com/challenges/is-binary-search-tree/problem)

file: C++ [check_bst.cpp](check_bst.cpp)

GeeksforGeeks [article](https://www.geeksforgeeks.org/a-program-to-check-if-a-binary-tree-is-bst-or-not/) on checking if a tree is a BST

#### Swap Nodes

Problem on [HackerRank](https://www.hackerrank.com/challenges/swap-nodes-algo/problem)

file: 

Recursive, passes 8/12 test cases

C++ [swap_nodes_rec.cpp](swap_nodes_rec.cpp) and [swap_nodes-rec2.cpp](swap_nodes-rec2.cpp) 

GeeksforGeeks [article](https://www.geeksforgeeks.org/swap-nodes-binary-tree-every-kth-level/)