/*
* https://www.codechef.com/problems/COINS
*/

#include <stdio.h>

// store calculated results in array a
long long a[10000000]={0};

// function to calculate the maximum coins 
// we can obtain from coin with value n
long long calc(long long n) {

	// up to n = 13 result straighforward
	if(n<12)
		return n;
		
	if(n==12)
		return 13;
		
	if(n<1000000) {
		if(a[n]!=0) // result already calculated
			return a[n];
			
	}

	// calculate, store and return the result
    long long k = calc(n/2)+calc(n/3)+calc(n/4);
    if(n<1000000)
     	a[n]=k;
    return k;
}

int main() {
    
    long long n=0, m=0;

    while(scanf("%lld", &n)!=EOF) {
    
        
        printf("%lld\n", calc(n));
        
        
    }
    
    return 0;   
}

