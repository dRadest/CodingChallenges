/*
* https://www.interviewbit.com/problems/hotel-reviews/
*
* Given a set of reviews provided by the customers for different hotels and a string containing “Good Words”, 
* you need to sort the reviews in descending order according to their “Goodness Value” (Higher goodness value first). 
* We define the “Goodness Value” of a string as the number of “Good Words” in that string.
*
* Note: Sorting should be stable. If review i and review j have the same “Goodness Value” then their original order would be preserved.
*
* You are expected to use Trie in an Interview for such problems 
*
* Constraints:
*
*	1.   1 <= No.of reviews <= 200
*	2.   1 <= No. of words in a review <= 1000
*	3.   1 <= Length of an individual review <= 10,000
*	4.   1 <= Number of Good Words <= 10,000
*	5.   1 <= Length of an individual Good Word <= 4
*	6.   All the alphabets are lower case (a - z)
*
* S : A string S containing "Good Words" separated by  "_" character. (See example below)
* R : A vector of strings containing Hotel Reviews. Review strings are also separated by "_" character.
*
* Output:
*
*	A vector V of integer which contain the original indexes of the reviews in the sorted order of reviews. 
*
* V[i] = k  means the review R[k] comes at i-th position in the sorted order. (See example below)
* In simple words, V[i]=Original index of the review which comes at i-th position in the sorted order. (Indexing is 0 based)
*
* Example:
* 
* Input: 
*	S = "cool_ice_wifi"
*	R = ["water_is_cool", "cold_ice_drink", "cool_wifi_speed"]
*
* Output:
*
*	ans = [2, 0, 1]
*   Here, sorted reviews are ["cool_wifi_speed", "water_is_cool", "cold_ice_drink"]
*/

const int ALPHABET_SIZE = 26; // lowercase English letters
  
// trie node 
struct TrieNode { 
    struct TrieNode *children[ALPHABET_SIZE]; 
  
    // isEndOfWord is true if the node represents 
    // end of a word 
    bool isEndOfWord; 
}; 
  
// Returns new trie node (children initialized to NULL) 
struct TrieNode* getNode(void) { 
    struct TrieNode *pNode =  new TrieNode; 
  
    pNode->isEndOfWord = false; 
  
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        pNode->children[i] = NULL; 
    }
  
    return pNode; 
} 
  
// If not present, inserts key into trie 
// If the key is prefix of trie node, 
// just marks leaf node 
void insert(struct TrieNode* root, string key) 
{ 
    struct TrieNode* pCrawl = root; 
  
    for (int i = 0; i < key.length(); i++) 
    { 
        int index = key[i] - 'a'; 
        if (!pCrawl->children[index]) 
            pCrawl->children[index] = getNode(); 
  
        pCrawl = pCrawl->children[index]; 
    } 
  
    // mark last node as leaf 
    pCrawl->isEndOfWord = true; 
} 
  
// Returns true if key presents in trie, else false 
bool search(struct TrieNode* root, string key) 
{ 
    struct TrieNode *pCrawl = root; 
  
    for (int i = 0; i < key.length(); i++) 
    { 
        int index = key[i] - 'a'; 
        if (!pCrawl->children[index]) {
            return false; 
        }
  
        pCrawl = pCrawl->children[index]; 
    } 
  
    return (pCrawl != NULL && pCrawl->isEndOfWord); 
} 

// splits string s into tokens around the delimiter
// returns vector of tokens
vector<string> split(const string &s, char delimiter){
   vector<string> tokens;
   string token;
   istringstream tokenStream(s);
   while (getline(tokenStream, token, delimiter)){
      tokens.push_back(token);
   }
   return tokens;
}
// string A contains good words, B contains reviews
vector<int> Solution::solve(string A, vector<string> &B) {
    vector<int> ans;
    vector<string> tokens;
    // construct a trie of good words
    TrieNode* root = getNode();
    tokens = split(A, '_');
    // insert tokens in trie
    for(int i=0; i<tokens.size(); i++){
        insert(root, tokens[i]);
    }

    // map goodness to reviews
    map<int, vector<int>> m;
    int goodness;
    string review;
    // traverse reviews
    for(int i=0; i<B.size(); i++){
        review = B[i];
        goodness = 0;
        tokens.clear();
        tokens = split(review, '_');
        // count number of good words in current review
        for(int j=0; j<tokens.size(); j++){
            if(search(root, tokens[j])){
                goodness++;
            }
        }
        m[goodness].push_back(i);
    }
    // traverse map in reverse order
    for(auto it = m.rbegin(); it != m.rend(); ++it ){
        vector<int> revs = it->second;
        for(int i=0; i<revs.size(); i++){
            ans.push_back(revs[i]);
        }
    }
    
    return ans;
}


