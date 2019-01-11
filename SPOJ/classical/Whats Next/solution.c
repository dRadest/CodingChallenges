/*
* https://www.spoj.com/problems/ACPC10A/
*/

#include<stdio.h>
int main()
{
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    while(a||b||c)
    {
        if(b-a==c-b)
        {
            printf("AP %d\n",c+(c-b));
        }
        else
        {
            printf("GP %d\n",c*(c/b));
        }
        scanf("%d%d%d",&a,&b,&c);
    }
    return 0;
}