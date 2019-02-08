/*
* https://www.interviewbit.com/problems/substring-concatenation/
*
* You are given a string, S, and a list of words, L, that are all of the same length.
*
* Find all starting indices of substring(s) in S that is a concatenation of each word in L exactly once and without any intervening characters.
*
* Example:
*   S: "barfoothefoobarman"
*   L: ["foo", "bar"]
*
* You should return the indices: [0,9].
* (order does not matter).
*/

vector<int> Solution::findSubstring(string A, const vector<string> &B) {
    vector <int> ans;
    // words mapped to number of occurance
    map <string, int> M;
    // number of words in B
    int bwords=B.size();
 
    // map each word to number of occurance
    for(int j=0; j<bwords;j++){
        M[B[j]]+=1;
    }
    
    // traverse input string
    for(int i=0;i<A.size();i++){
        int index = i;
        map <string, int> F;
        int count = 0;
        // construct F 
        for(int j=i; j+B[0].length()<=A.size() && count<bwords; j+=B[0].length()){
            F[A.substr(j,B[0].length())]+=1;
            count++;
        }
        
        if(F==M){
            ans.push_back(index);
        }
                
    }

    return ans;
}
