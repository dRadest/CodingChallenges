/*
* https://www.codechef.com/problems/FLOW008
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
		if(n < 10){
			printf("What an obedient servant you are!\n");
		}else{
			printf("-1\n");
		}
	}
	return 0;
}