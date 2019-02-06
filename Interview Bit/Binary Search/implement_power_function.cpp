/*
* https://www.interviewbit.com/problems/implement-power-function/
* Implement pow(x, n) % d.
* In other words, given x, n and d,
* find (xn % d)
* Note that remainders on division cannot be negative.
* In other words, make sure the answer you return is non negative.
*
* geeksforgeeks:
* https://www.interviewbit.com/problems/implement-power-function/
*/

int Solution::pow(int x, int n, int d) {
    long long int rem = 1;
    int check = 0; // odd
    
    if(x == 0){ // base 0 
        return 0;
    }
    if(n == 0){ // anything to the power of 0 is 1
        return 1;
    }
    
    if(x < 0){ // for negative base
        x = abs(x);
        if(n%2 != 0){
            check = 1;
        }
    }
    
    long long int temp = x%d;
    
    while(n != 0){
        if(n%2 != 0){
            rem = (rem*temp)%d;
        }
        
        temp = temp*temp;
        temp = temp%d;
        
        n = n/2;
        if(rem > d){
            rem = rem%d;
        }
    }
    
    if(check == 1){
        return d-(int)rem;
    }
    
    return (int)rem;
}
