#include<bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }
        /*
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/

typedef pair<int,int> v_h; 
map <int,v_h> m; // map
map <int, v_h> :: iterator itr; //iterator

void store_view(Node* root,int i,int h)
{
    if(root == NULL){
        return;
    }
    itr=m.find(i);
    if(itr==m.end()){
        m[i]=make_pair(h,root->data);
    }else{
        if(itr -> second.first > h){
            m[i]=make_pair(h, root -> data);
        }
    }
    if(root -> left != NULL){
        store_view(root -> left, i-1, h+1);
    }
    if(root -> right != NULL)
        store_view(root -> right, i+1, h+1);
     
}

void print_map()
{
    for(itr = m.begin(); itr != m.end(); ++itr)
        cout<<itr->second.second<<" ";
}

void topView(Node * root)
{
   store_view(root,0,0);
   print_map();
   return;
}

}; //End of Solution

int main() {
  
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  
    myTree.topView(root);
    return 0;
}