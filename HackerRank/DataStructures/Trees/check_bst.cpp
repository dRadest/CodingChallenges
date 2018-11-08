#define INT_MIN 0
#define INT_MAX 10000

bool isBst(Node* node, int min, int max){
    if(node == NULL){
        return true;
    }
    if(node -> data < min || node -> data > max){
        return false;
    }
    return isBst(node -> left, min, node -> data - 1) &&
        isBst(node -> right, node -> data + 1, max);
}
bool checkBST(Node* root) {
		return(isBst(root, INT_MIN, INT_MAX));
}