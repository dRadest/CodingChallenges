/*
* https://www.codechef.com/problems/TWTCLOSE
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
	// keep track of total tweets opened
	int total_open = 0;
	// read number of tweets n and clicks k
	int n, k;
	scanf("%d %d\n", &n, &k);
	// tweet status, 0 - closed, 1 - opened
	int tweets[n];
	for(int i=0; i<n; i++){ // initally, all closed
	    tweets[i] = 0;
	}
	char inputs[8];
	int index;
	// process the clicks
	for(int m=0; m<k; m++){
		scanf("%s%d", inputs, &index);
		if(inputs[2] == 'I'){
		    if(tweets[index-1]){ // tweet open
		        // close it
		        total_open--;
		        tweets[index-1]=0;
		    }else{ // tweet closed
		        // open it
		        total_open++;
		        tweets[index-1]=1;
		    }
		}else{ // close all tweets
		    for(int i=0; i<n; i++){
		        tweets[i] = 0;
		    }
		    total_open = 0;
		}
		printf("%d\n", total_open);

	}
}