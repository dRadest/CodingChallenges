/*
* https://www.interviewbit.com/problems/longest-common-prefix/
* Write a function to find the longest common prefix string amongst an array of strings.
* Longest common prefix for a pair of strings S1 and S2 is the longest string S which is the prefix of both S1 and S2.
* As an example, longest common prefix of "abcdefgh" and "abcefgh" is "abc".
* Given the array of strings, you need to find the longest S which is the prefix of ALL the strings in the array.
*/

string Solution::longestCommonPrefix(vector<string> &A) {
    string ans;
    int len = A.size();
    // find shortest string
    int min_size = A[0].length();
    for(int i=1; i<len; i++){
        if(A[i].length() < min_size){
            min_size = A[i].length();
        }
    }
    char cur_char;
    // traverse all chars up to min_size index
    for(int i=0; i<min_size; i++){
        cur_char = A[0][i];
        // all other strings should have the same char at this index
        for(int j=1; j<A.size(); j++){
            if(A[j][i] != cur_char){
                return ans;
            }
        }
        ans += cur_char;
    }
    return ans;
    
}
