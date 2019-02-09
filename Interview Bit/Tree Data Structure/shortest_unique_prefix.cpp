/*
* https://www.interviewbit.com/problems/shortest-unique-prefix/
*
* Find shortest unique prefix to represent each word in the list.
* 
* Example:
* 
*	Input: [zebra, dog, duck, dove]
*	Output: {z, dog, du, dov}
*	where we can see that
*	zebra = z
*	dog = dog
*	duck = du
*	dove = dov
*
*    NOTE : Assume that no word is prefix of another. In other words, the representation is always possible. 
*/

struct TrieNode{
    TrieNode* child[26];
    bool unique; // flag if char has 0 or 1 child
    
    TrieNode(){
        for(int i = 0; i < 26; i++){
            child[i] = NULL;
        }
        unique = true;
    }
};
// function to insert a string in trie rooted at root
void makeTrie(TrieNode* root, string s){
    TrieNode* curr = root;
    
    int i = 0;
    int a = s[i] - 97;
    while(i < s.size()){
        if(curr->child[a] == NULL){
            TrieNode* node = new TrieNode();
            curr->child[a] = node;
        }
        else{
            (curr->child[a])->unique = false;
        }
        curr = curr->child[a];
        i++;
        if(i != s.size()){
            a = s[i] - 97;
        }
    }
}
// returns the shortest prefix of string s
string getPre(TrieNode* root, string s){
    string sol = "";
    
    TrieNode* curr = root;
    
    if(s.size() == 0){
        return sol;
    }
    
    int i = 0;
    
    do{
    	// append current letter to the solution
        curr = curr->child[s[i]-97];    
        sol = sol + s[i];
        i++;   
    }while{
    	// until unique letter encountered
    	(i < s.size() && curr->unique == false);
    }
    
    return sol;
}
vector<string> Solution::prefix(vector<string> &A) {
    vector<string> sol;
    
    TrieNode* root = new TrieNode();
    // insert all strings in trie
    for(int i = 0; i < A.size(); i++){
        makeTrie(root, A[i]);
    }
    
    for(int i = 0; i < A.size(); i++){
        sol.push_back(getPre(root, A[i]));
    }
    
    return sol;
}

