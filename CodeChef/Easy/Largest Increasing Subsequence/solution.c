/*
* https://www.codechef.com/problems/INVLIS
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
	int t; // test cases
	scanf("%d",&t);
	while(t--)
	{	
		int n, k;
		scanf("%d %d", &n, &k);
		int a[k]; // save indicies
		for(int i=0; i<k; i++){
			scanf("%d", &a[i]);
		}
		if(n==0){
			printf("YES\n");
			continue;
		}
		if(n==1){
			printf("YES\n1\n");
			continue;
		}else if(k==1){
			printf("NO\n");
			continue;
		}else if(k==2 && n>2){
			int impossible = 0;
			if(a[0] != a[1]-1){
				impossible = 1;
			}
			if(impossible){
				printf("NO\n");
				continue;
			}
		}
		printf("YES\n");

		int mx = n; // holds current max value
		// prepare answer array and initialize all values to zero
		int ans[n+1];
		for(int i=0; i<=n; i++){
			ans[i] = 0;
		} 
		// make numbers up to first index descending
		for(int i=1; i<a[0]; i++){
			ans[i] = mx--;
		}
		// fill the gap between first and second indecies with descending numbers
		for(int i=a[0]+1; i<a[1]; i++){
			ans[i] = mx--;
		}
		// fill answer array with ascending numbers at required indices
		for(int i=k-1; i>=0; i--){
			ans[a[i]] = mx--;
		}
		// fill any remaining cells with descending numbers
		for(int i=a[0]; i<=n; i++){
			if(!ans[i]){
				ans[i] = mx--;
			}
		}
		// print out the answer array
		for(int i=1; i<=n; i++){
			printf("%d ", ans[i]);
		}
		printf("\n");
			
	}
	return 0;
		
}