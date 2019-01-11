#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int n;
	long long int sum;
	scanf("%d", &n);
	while(n){
		sum = 0;
		// iterative solution
		while(n >= 1){
			sum += (n*n);
			n--;
		}
		/* 
		* direct calculation using formula
		* sum = (n*(n+1)*(2*n+1))/6;
		*/
		
		printf("%lld\n", sum);
		scanf("%d", &n);
	}
	return 0;
}