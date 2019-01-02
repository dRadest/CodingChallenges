/*
* https://www.codechef.com/problems/HS08TEST
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
	int x;
	float y;
	scanf("%d %f", &x, &y);
	if(x%5 == 0 && y >= (x+0.5)){
		y -= (x+0.5);
	}
	printf("%.1f\n", y);
	return 0;
}