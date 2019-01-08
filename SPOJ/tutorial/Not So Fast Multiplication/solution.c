/*
* https://www.spoj.com/problems/TMUL/
*/

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

long long multiply(int a, int b)
{
	if(b == 0)
	{
		return 0;
	}
	long long ret = multiply(a, b >> 1); // b >> 1 gives quotient when b is divided by 2
	ret = (ret + ret); 
	if(b & 1) // b is odd, add a
	{
		ret += a;
	}
	return ret;
}

int main(){
	int t, num1, num2;
	long long int sum;
	scanf("%d", &t);
	
	for(int j=0; j<t; j++){
		sum = 0;
		scanf("%d%d", &num1, &num2);

		sum = multiply(num1, num2);
		
		printf("%lld\n", sum);
	}
	
	return 0;
}