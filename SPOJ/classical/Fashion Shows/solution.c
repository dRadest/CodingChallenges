#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// comparator for qsort
int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int main(){
	int t, n, i, sum;
	int *x = (int*)malloc(sizeof(int)); // men's hotness
	int *y = (int*)malloc(sizeof(int)); // women's hotness
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		x = (int*)realloc(x, n*sizeof(int));
		for(i=0; i<n; i++){
			scanf("%d", (x+i));
		}
		y = (int*)realloc(y, n*sizeof(int));
		for(i=0; i<n; i++){
			scanf("%d", (y+i));
		}
		qsort(x, n, sizeof(int), cmpfunc);
		qsort(y, n, sizeof(int), cmpfunc);
		sum = 0;
		for(i=0; i<n; i++){
			sum += (*(x+i)) * (*(y+i));
		}
		printf("%d\n", sum);
	}
	return 0;
}