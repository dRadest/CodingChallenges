/* 
* https://www.spoj.com/problems/COINS/
*/

#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXVAL 1000000

long long int* dp;

long long int exchange(int n){
	if(n==0){
		return 0;
	}
	if (n<MAXVAL)
	{
		if(*(dp+n) != -1){
			return *(dp+n);
		}
		long long int ex = exchange(n/2)+exchange(n/3)+exchange(n/4); 
		if(ex > n){
			*(dp+n) = ex;
		}else{
			*(dp+n) = n;
		}
		return *(dp+n);
	}else{
		long long int ex = exchange(n/2)+exchange(n/3)+exchange(n/4);
		return n>ex ? n : ex;
	}
}

int main(){
	// initialize dp
	dp = (long long*)malloc(MAXVAL*sizeof(long long));
	for(int i=1; i<MAXVAL; i++){
		*(dp+i) = -1;
	}
	*dp = 0;

	int n;
        
	while(scanf("%d",&n)==1){
		printf("%lld\n", exchange(n));
	} 
	
	return 0;
}