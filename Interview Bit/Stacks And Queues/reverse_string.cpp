/*
* https://www.interviewbit.com/problems/reverse-string/
*
* Given a string S, reverse the string using stack.
*
* mycodeschool
* https://youtu.be/hNP72JdOIgY
*/

string Solution::reverseString(string A) {
	// push all chars onto stack
    stack<char> st;
    for(int i=0; i<A.length(); i++){
        st.push(A[i]);
    }
    // pop all chars from stack and append them to the output string
    string revA = "";
    while(!st.empty()){
        revA += st.top();
        st.pop();
    }
    return revA;
}
