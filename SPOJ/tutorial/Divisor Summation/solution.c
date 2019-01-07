/*
* https://www.spoj.com/problems/DIVSUM/
*/

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

int main(){
	int t, n;
	long long int sum;
	scanf("%d", &t);
	
	for(int j=0; j<t; j++){
		sum = 0;
		scanf("%d", &n);
		
		for(int i=1; i<n/2+1; i++){
			if(n%i == 0){
				sum += i;
			}
		}
		
		printf("%lld\n", sum);
	}
	
	return 0;
}