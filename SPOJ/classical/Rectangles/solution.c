/* 
* https://www.spoj.com/problems/AE00/
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

int nor(int n){
	int sf = sqrt(n);
	int nf = 1;
	for(int i=2; i<=sf; i++){
		if(n%i==0){
			nf++;
		}
	}
	return nf;
}

int main(){
	int n, rect, i;
	while(scanf("%d", &n)==1){
		rect = 0;
		for(i=1; i<=n; i++){
			rect += nor(i);
		}
		printf("%d\n", rect);

	}
	return 0;
}