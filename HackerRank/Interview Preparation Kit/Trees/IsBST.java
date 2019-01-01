/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node class is defined as follows:
    class Node {
        int data;
        Node left;
        Node right;
     }
*/
    
    static void inorderTraversal (Node node, List<Integer> treeData){
        if(node == null)
            return;
        inorderTraversal(node.left, treeData);
        treeData.add(node.data);
        inorderTraversal(node.right, treeData);
    }
    boolean checkBST(Node root) {
        List<Integer> treeData = new ArrayList<Integer>();
        inorderTraversal(root, treeData);
        for(int i=1; i<treeData.size(); i++){
            if(treeData.get(i)<=treeData.get(i-1))
                return false;
        }
        return true;
    }
