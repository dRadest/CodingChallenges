/*
* https://www.interviewbit.com/problems/implement-strstr/
* strstr - locate a substring ( needle ) in a string ( haystack ). 
*/

int Solution::strStr(const string A, const string B) {
    int n=A.length(); // length of haystack
    int z=B.length(); // length of needle
    if(n==0 || z==0)
        return -1;
    int i,j;
    // traverse haystack
    for(i=0;i<n;i++){
        // char in haystack matches first char in needle
        if(A[i]==B[0]){
            j=0;
            // check if the rest match
            while(j<z && A[j+i]==B[j]){
                j++;
            }
            if(j==z){
                return i;
            }
        }
    }
    return -1;
}
