/*
* https://www.interviewbit.com/problems/length-of-last-word/
* Given a string s consists of upper/lower-case alphabets and empty space characters ' ', 
* return the length of last word in the string.
* If the last word does not exist, return 0.
* Note: A word is defined as a character sequence consists of non-space characters only.
*/

int Solution::lengthOfLastWord(const string A) {
    if(A.length() == 0){
        return 0;
    }
    int i=A.length()-1;
    int len = 0;
    // skip trailing whitespaces
    while(i>=0 && A[i]==' '){
        i--;
    }
    // start of the string reached
    if(i==0 && A[i]==' '){ 
        return len;
    }else{
        // move towards beginning of the string
        while(i>=0 && A[i]!=' '){
            i--;
            len++;
        }
        return len;
    }
    return len;
}
