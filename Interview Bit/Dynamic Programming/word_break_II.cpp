/*
*
* https://www.interviewbit.com/problems/word-break-ii/
*
* Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.
*
* Return all such possible sentences.
*
* For example, given
*
*	s = "catsanddog",
*	dict = ["cat", "cats", "and", "sand", "dog"].
*
*	A solution is
*
*	[
*	  "cat sand dog", 
*	  "cats and dog"
*	]
*
* Make sure the strings are sorted in your result.
*/

#define MAX 50002
struct node {
  bool fin;
  int sons[26];
};
node trie[MAX];
int m;
vector<string> res;
// add word to trie
void add(string v){
    int pos=1;
    for(int i=0;i<v.size();i++){
        int l=v[i]-'a';
        if(!trie[pos].sons[l]){
            trie[pos].sons[l]=++m;
        }
        pos=trie[pos].sons[l];
    }
    trie[pos].fin=true;
}
void solve(string v,string uso,int pos,int i){
    if(i==v.size()){
        res.push_back(uso);
        return;
    }
    while(i<v.size()){
        if(trie[pos].sons[v[i]-'a']){
            uso.push_back(v[i]);
            pos=trie[pos].sons[v[i]-'a'];
            if(trie[pos].fin){
                string uso2;
                if(i<v.size()-1)uso2=uso+' ';
                else uso2=uso;
                solve(v,uso2,1,i+1);
            }
        }
        else break;
        i++;
    }
}
vector<string> Solution::wordBreak(string A, vector<string> &B) {
    // clear global variables
    memset(trie,0,sizeof(trie));
    res.clear();
    m=1;
    // add dictionary words to trie
    for(int i=0;i<B.size();i++){
        add(B[i]);
    }
    solve(A,"",1,0);
    sort(res.begin(),res.end());
    return res;
}

