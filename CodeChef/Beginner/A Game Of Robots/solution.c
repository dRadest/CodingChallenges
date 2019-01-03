/*
* https://www.codechef.com/problems/ROBOGAME
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
	char s[50]; // input string
	scanf("%d",&t);
	while(t--)
	{	
		scanf("%s",&s);
		int i=0,j=0; char result[7]="safe";

			while(s[i]!='\0') // traverse input string
			{
				if(s[i]!='.') // robot reached
				{
					// find next robot
					j=i+1;
					while(s[j]=='.')
					{
						j++;
					}
					if(s[j]=='\0') // no robot to the end
					{
						break;
					}
					// if cells covered >= cells between robots
					// unsafe
					else if((s[i]-'0')+(s[j]-'0')>=(j-i))
						{strcpy(result,"unsafe");break;}
					
					i=j;
				}
				else i++;
			}
			printf("%s\n",result);
			
	}
	return 0;
}