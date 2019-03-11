/*
*
* https://www.spoj.com/problems/SUMUP/
* score: 159
*
* PROBLEM:
* sum the following series: 1/3 + 2/21 + 3/91 + 4/273 + ...
*
* SOLUTION
* Nominator is straightforward: 1, 2, 3, ...
* Denominator is product of two consecutives in series 1, 3, 7, 13, 21, 31, ...
* 3 = 1*3
* 21 = 3*7
* 91 = 7*13
* 273 = 13*21
*
*/
#include<stdio.h>
int main()
	{
	int i,n;
	scanf("%d",&i);
	while(i--)
	{
	scanf("%d",&n);
	printf("%.5f\n",(1.0/2.0)*(1.0-(1.0/(n*n+n+1.0))));
	}
	return 0;
}