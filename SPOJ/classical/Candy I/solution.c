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
	int* a = (int*)malloc(sizeof(int));
	int sum;
	scanf("%d", &n);
	while(n != -1){
		a = (int*)realloc(a, n*sizeof(int));
		sum = 0;
		for(int i=0; i<n; i++){
			scanf("%d", (a+i));
			sum += *(a+i);
		}
		int med = sum / n;
		// median value has to be whole number
		if(sum % n != 0){
			printf("%d\n", -1);
		}else{
			int move = 0; // candies moved
			// traverse a
			for(int i=0; i<n; i++){
				// add difference to median to the total number of moved candies
				if(*(a+i) < med){
					move += (med - *(a+i));
				}
			}
			printf("%d\n", move);
		}
		scanf("%d", &n);
	}
	return 0;
}