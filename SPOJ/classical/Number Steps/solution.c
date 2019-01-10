/*
* https://www.spoj.com/problems/NSTEPS/
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

int main()
{
    int x,y,r,t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &x, &y);
        if(x==y)
        {
            if(x%2==0)
                r=2*x;
            else
                r=2*x-1;
            printf("%d\n", r);
        }
        else if(x==y+2)
        {
            if(x%2==0)
                r=x+y;
            else
                r=x+y-1;
            printf("%d\n", r);
        }
        else
            printf("No Number\n");
    }
}