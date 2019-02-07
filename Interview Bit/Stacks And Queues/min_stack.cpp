/*
* https://www.interviewbit.com/problems/min-stack/
*
* Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
*
* 
    1. push(x) – Push element x onto stack.
    2. pop() – Removes the element on top of the stack.
    3. top() – Get the top element.
    4. getMin() – Retrieve the minimum element in the stack.
*
* Note that all the operations have to be constant time operations.
*
* Questions to ask the interviewer :
*
* Q: What should getMin() do on empty stack? 
* A: In this case, return -1.
*
* Q: What should pop do on empty stack? 
* A: In this case, nothing. 
* 
* Q: What should top() do on empty stack?
* A: In this case, return -1
*/

stack<int> st;
stack<int> minSt;

MinStack::MinStack() {
    // empty both stacks
    while(!st.empty()){
        st.pop();
    }
    while(!minSt.empty()){
        minSt.pop();
    }
}

void MinStack::push(int x) {
    st.push(x);
    // just push the element on min stack if it's empty
    if(minSt.size() == 0){
        minSt.push(x);
    }
    else{
    	// x smaller than what's on top
        if(x <= minSt.top()){
            minSt.push(x);
        }
        else{ // push what's on top onto the stack
            minSt.push(minSt.top());
        }
    }
}

void MinStack::pop() {
	// pop both stacks
    if(st.size() != 0){
        st.pop();
        minSt.pop();
    }
}

int MinStack::top() {
	// return what's on top
    if(st.size() == 0){
        return -1;
    }
    return st.top();
}

int MinStack::getMin() {
	// return what's on top of min stack
    if(minSt.size() == 0){
        return -1;
    }
    return minSt.top();
}

