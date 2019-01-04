/*
* https://www.codechef.com/problems/SUBLD
*/

#include <stdio.h>

// utility function that returns the length of the sequence of numbers 
// produced by reduction starting from n
long int get_seqlen(long int n)
{
    long int seqlen=0;
    long int d;
    long int l; // store power of 10 number n is of
    long int rounded, remainder, decade, seqcnt;
    
    while (n>0)
    {

        d = n; l = 0;
        // divide by ten and count number of times (=power)
        while (d >= 10) 
        {
            d /= 10;
            l += 1;
        }
        // round n to the lowest power of 10
        rounded = d;
        while(l--) 
        {
            rounded *= 10;
        }  
        // remainder = number of steps from rounded to n  
        remainder = n % rounded;
        seqcnt = remainder / d;
        // substract number of steps from n
        n -= seqcnt*d;
        // increment sequence length by number of steps
        seqlen += seqcnt;

        // one final substraction to get to the new cycle
        n -= d;
        ++seqlen;
    }
    return(seqlen+1);
}

// utility function to return the maximum number to start with
// to get the desired sequence of numbers
long int find_sequence(long int desired)
{
    long int left, right, mid, sl;
    
    left = desired;
    right = desired * 10;
    mid = (left + right) / 2;
    // get the sequence length of the mid point
    sl = get_seqlen(mid);
    
    // until desired sequence length is reached
    while(sl != desired)
    {	// update mid point
        mid = (left+right)/2;
        // get sequence length of the new mid point
        sl = get_seqlen(mid);
        if (sl > desired){
        	// move right down
        	right = mid;
        }   
        else{
        	// move left up
        	left = mid;
        }
    }

    // increment mid point by one while sequence length is equal to the desired one
    // to get the maximum value of mid point
    while(sl == desired)
    {
        if (sl != get_seqlen(mid+1)){
        	break;
        }
        mid++; 
    }
    return(mid);
}

int main()
{
    long int t, k;
    
    scanf("%ld", &t);
    while (t--)
    {
        scanf("%ld", &k);
        long int result = find_sequence(k);
        printf("%ld\n", result);
    }
}