/*
* https://www.interviewbit.com/problems/amazing-subarrays/
* You are given a string S, and you have to find all the amazing substrings of S.
* Amazing Substring is one that starts with a vowel (a, e, i, o, u, A, E, I, O, U).
*/

int Solution::solve(string A) {
    int n = A.length();
    int subs = 0; // count of amazing subarrays
    char cur_char;
    for(int i=0; i<n; i++){
        cur_char = A[i];
        if(cur_char == 'A' || cur_char == 'E' || cur_char == 'I' || cur_char == 'O' || 
        cur_char == 'U' || cur_char == 'a' || cur_char == 'e' || cur_char == 'i' || 
        cur_char == 'o' || cur_char == 'u'){
        	// number of subarrays equals number of chars left from current index on
            subs += (n-i);
        }
    }
    return subs%10003;
}

