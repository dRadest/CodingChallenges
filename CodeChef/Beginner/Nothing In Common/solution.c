/*
* https://www.codechef.com/problems/NOTINCOM
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

// A recursive binary search function. It returns 
// location of x in given array arr[l..r] is present, 
// otherwise -1 
int binarySearch(int arr[], int l, int r, int x) 
{ 
    if (r >= l) { 
        int mid = l + (r - l) / 2; 
  
        // If the element is present at the middle 
        // itself 
        if (arr[mid] == x) 
            return mid; 
  
        // If element is smaller than mid, then 
        // it can only be present in left subarray 
        if (arr[mid] > x) 
            return binarySearch(arr, l, mid - 1, x); 
  
        // Else the element can only be present 
        // in right subarray 
        return binarySearch(arr, mid + 1, r, x); 
    } 
  
    // We reach here when element is not 
    // present in array 
    return -1; 
} 

int main(){
	int t, n, m;
	int* seta = (int*)malloc(sizeof(int));
	int* setb = (int*)malloc(sizeof(int));
	scanf("%d", &t);
	while(t--){
		// read in both sets
		scanf("%d %d", &n, &m);
		seta = (int*)realloc(seta, n * sizeof(int));
		for(int i=0; i<n; i++){
			scanf("%d", &seta[i]);
		}
		setb = (int*)realloc(setb, m * sizeof(int));
		for(int i=0; i<m; i++){
			scanf("%d", &setb[i]);
		}
		// sort set a for binary search
		qsort(setb, m, sizeof(int), cmpfunc);
		int cnt = 0;
		// traverse set a
		for(int i=0; i<n; i++){
			int elem = seta[i];
			if(binarySearch(setb, 0, m-1, elem) >= 0){ // found
				cnt++; // remove
			}
		}
		printf("%d\n", cnt);
	}
}