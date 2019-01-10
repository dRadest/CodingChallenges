/*
* guide: https://codegeeksblog.wordpress.com/2013/05/30/spoj-fctrl2-small-factorials/
* https://www.spoj.com/problems/FCTRL2/
*/

#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int num;
        int i,k=0,j,carry=0,arr[1000]={1};
        scanf("%d",&num);
        for(i=1;i<=num;i++)
        {
            for(j=0;j<=k;j++)
             {
                arr[j]=arr[j]*i+carry;
                carry=arr[j]/10;
                arr[j]=arr[j]%10;
             }
             while(carry)
             {
                 k++;
                 arr[k]=carry%10;
                 carry/=10;
             }
         }
         for(i=k;i>=0;i--)
            printf("%d",arr[i]);
        printf("\n");
    }
    return 0;
}