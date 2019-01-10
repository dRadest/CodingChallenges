/*
* logic: https://algorithm3.wordpress.com/2012/03/29/11-factorial/
* https://www.spoj.com/problems/FCTRL/
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
	int t, n, trail;
	scanf("%d", &t);
	for(int i=0; i<t; i++){
		scanf("%d", &n);
		trail = 0;
		int fivefac = 5;
		while(n/fivefac > 0){
			trail += (n/fivefac);
			fivefac *= 5;
		}
		printf("%d\n", trail);
	}
	return 0;
}