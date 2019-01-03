/*
* https://www.codechef.com/problems/NOMATCH
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

// compare function for qsort
int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int main(){
	int t, n;
	int* a = (int*)(malloc(sizeof(int)));
	scanf("%d", &t);

	while(t--){
		// save the array of integers
		scanf("%d", &n);
		a = (int*)realloc(a, n*sizeof(int));
		for(int i=0; i<n; i++){
			scanf("%d", &a[i]);
		}
		// sort the array
		qsort(a, n, sizeof(int), cmpfunc);
		double sum = 0;
		for(int i=0; i<n/2; i++){
			double diff = a[i] - a[n-1-i];
			sum += abs(diff);
		}
		printf("%.0f\n", sum);
	}
	return 0;
}