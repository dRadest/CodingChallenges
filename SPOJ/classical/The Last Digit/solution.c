/*
* https://www.spoj.com/problems/LASTDIG/
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

// using right to left binary method of modular exponatiation

int main(){
	int t, a, b, result;
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &a, &b);

		if(a == 0){
			printf("%d\n", 0);
			continue;
		}
		if(b == 0){
			printf("%d\n", 1);
			continue;
		}

		result = 1;
		a = a % 10;
		while(b > 0){
			if(b % 2 == 1){
				result = (result*a)%10;
			}
			b = b >> 1;
			a = (a*a)%10;
		}
		printf("%d\n", result);
	}
	return 0;
}