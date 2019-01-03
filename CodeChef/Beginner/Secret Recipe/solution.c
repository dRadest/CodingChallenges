/*
* https://www.codechef.com/problems/CHEFRUN
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
		int x1, x2, x3, v1, v2;
		scanf("%d %d %d %d %d", &x1, &x2, &x3, &v1, &v2);

		// time = distance / speed
		double t1 = (double)(x3-x1)/v1; // Chef's time
		double t2 = (double)(x2-x3)/v2; // Kefa's time

		if(t2<t1)
		{
			printf("Kefa\n");
		}
        else if(t1<t2)
    	{
    		printf("Chef\n");
    	}
        else
        { 
        	printf("Draw\n");
        }
			
	}
	return 0;
}