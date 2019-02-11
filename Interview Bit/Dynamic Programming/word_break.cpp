/*
*
* https://www.interviewbit.com/problems/word-break/
*
* Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.
*
* For example, given
*
*   s = "myinterviewtrainer",
*   dict = ["trainer", "my", "interview"].
*
*   Return 1 ( corresponding to true ) because "myinterviewtrainer" can be segmented as "my interview trainer".
*
* Return 0 / 1 ( 0 for false, 1 for true ) for this problem
*/

// returns true if string A is present in a dictionary B
bool search(string A, vector<string> B){
    for(int i = 0; i < B.size(); i++){
        if(B[i] == A){
            return true;
        }
    }
    return false;
}

int Solution::wordBreak(string A, vector<string> &B) {
    int n = A.size();
 
    vector<int> temp(n+1, 0);
    temp[n] = 1;
    
    for(int i = n-1; i >= 0; i--){
        for(int j = i; j < n; j++){
            string s = A.substr(i, j-i+1);
            if(search(s, B) && temp[j+1] == 1){
                temp[i] = 1;
                break;
            }
        }
    }
    
    return temp[0];
}
