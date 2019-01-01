/* 
The structure of the node is

typedef struct node
{
    int freq;
    char data;
    node * left;
    node * right;
    
}node;

*/


void decode_huff(node * root,string s)
{
    node* c = root;
    for(int i=0; i<s.length(); i++){
        c = s.at(i) == '1' ? c->right : c-> left;
        if(c->left == NULL && c->right == NULL){
            cout << c->data;
            c = root;
        }
    }
    
}
