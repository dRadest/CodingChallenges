/*
* https://www.interviewbit.com/problems/evaluate-expression/
*
* Evaluate the value of an arithmetic expression in Reverse Polish Notation.
* Valid operators are +, -, *, /. Each operand may be an integer or another expression.
*
* examples:
* ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
* ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
*/

int Solution::evalRPN(vector<string> &A) {
    stack<int> st;
    
    // traverse input string
    for(int i = 0; i < A.size(); i++){
        // operator encountered
        if(A[i] == "+" || A[i] == "-" || A[i] == "*" || A[i] == "/"){
            // get two operands
            int first = st.top();
            st.pop();
            int second = st.top();
            st.pop();
            // perform operation and push onto the stack
            if(A[i] == "+"){
                st.push(second+first);
            }
            else if(A[i] == "-"){
                st.push(second-first);
            }
            else if(A[i] == "*"){
                st.push(second*first);
            }
            else{
                st.push(second/first);
            }
        }
        else{
            // convert string to integer and push onto the stack
            st.push(stoi(A[i]));
            //st.push(atoi(A[i].c_str()));
        }
    }
    
    return st.top();
}
