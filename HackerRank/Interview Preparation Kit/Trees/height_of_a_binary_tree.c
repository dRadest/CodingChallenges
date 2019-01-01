/* you only have to complete the function given below.  
node is defined as  

struct node {
    
    int data;
    struct node *left;
    struct node *right;
  
};

*/
int getHeight(struct node* root) {
    if(root == NULL){
        return -1;
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