/*
* https://www.interviewbit.com/problems/simplify-directory-path/
*
* Given an absolute path for a file (Unix-style), simplify it.
*
* examples:
* path = "/home/", => "/home"
* path = "/a/./b/../../c/", => "/c"
*
* Note that absolute path always begin with ‘/’ ( root directory )
* Path will not have whitespace characters.
*/

string Solution::simplifyPath(string A) {
    stack<string> st;
    
    int len = A.length();
    
    // traverse input string
    for(int i=0;i<len;i++){
        if(A[i]=='/'){ // skip /
            continue;
        }
        if(A[i]=='.'){
            // next char also dot 
            if(i+1<len && A[i+1]=='.'){
                // skip both
                if(!st.empty())
                    st.pop();
                i++;
            }
        }
        else{
            // construct a string temp
            string temp="";
            while(i<len && A[i]!='/'){
                temp += A[i];
                i++;
            }
            st.push(temp);
        }
    }
    // construct ans
    string ans = "";
    while(!st.empty()){
        ans = "/"+st.top()+ans;
        st.pop();
    }

    return (ans=="")?"/":ans;
}
