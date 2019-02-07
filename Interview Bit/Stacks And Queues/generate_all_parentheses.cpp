/*
* https://www.interviewbit.com/problems/generate-all-parentheses/
* Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
*
* The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*
* Return 0 / 1 ( 0 for false, 1 for true ) for this problem
*
* mycodeschool
* https://youtu.be/QZOLb0xHB_Q
*/

// Function to check whether two characters are opening 
// and closing of same type. 
bool ArePair(char opening, char closing)
{
    if(opening == '(' && closing == ')') return true;
    else if(opening == '{' && closing == '}') return true;
    else if(opening == '[' && closing == ']') return true;
    return false;
}
int Solution::isValid(string A) {
    stack<char>  S;
    for(int i =0; i<A.length();i++)
    {
        // current char is opening bracket
        if(A[i] == '(' || A[i] == '{' || A[i] == '['){
            S.push(A[i]);
        }
        // current char is closing brackets
        else if(A[i] == ')' || A[i] == '}' || A[i] == ']')
        {
            // no matching closing brackets
            if(S.empty() || !ArePair(S.top(),A[i])){
                return 0; // false
            }
            else{ // brackets match, remove top from stack
                S.pop();
            }
        }
    }
    // if any closing brackets left on stack
    // i.e. not paired, return 0 (false)
    return S.empty() ? 1 : 0;
}
