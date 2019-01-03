/*
* https://www.codechef.com/problems/BITOBYT
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

int main(){
	int t, n;
	scanf("%d", &t);

	while(t--){
		scanf("%d", &n);
		n--;
		int cycles = n / 26;
		int left = n - cycles * 26;
		double result = pow(2, cycles);
		if(left >= 10){
			printf("0 0 %.0f", result);
		}else if(left >= 2){
			printf("0 %.0f 0", result);
		}else{
			printf("%.0f 0 0", result);
		}
	}
	return 0;
}