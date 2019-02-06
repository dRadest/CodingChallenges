/*
* https://www.interviewbit.com/problems/number-of-1-bits/
* Write a function that takes an unsigned integer and returns the number of 1 bits it has.
*
* idea: 
* bitwise and of 1 and any number results in 1 if last bit of the number is 1, 0 otherwise
* so we keep shifting the bits to the right until we reach zero
*/

int Solution::numSetBits(unsigned int A){
    unsigned int count = 0; 
    while (A) 
    { 
        count += A & 1; 
        A >>= 1; 
    } 
    return count; 
}
