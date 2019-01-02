/*
* https://www.codechef.com/problems/TEMPLELA
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

#include<bits/stdc++.h>
using namespace std;
 
int main() {
	// standarc c++ streams NOT synchronized to the standard c streams
	ios_base::sync_with_stdio(false);
	// tie cin to NULL
	cin.tie(NULL);
	int t,n,i,j,f;
	int a[1000];
	cin>>t;
	while(t--)
	{
		// scan the input array
	    cin>>n;
	    for(i=1;i<=n;i++)
	    	cin>>a[i];
	    if(n%2==0) // has to be odd to have centre point
	    {
	        cout<<"no"<<endl;
	        continue;
	    }
	    f=0; // flag to inciate if the strip is valid
	    n++;
	    // up to the centre point value equal to index
	    for(i=1;i<=n/2;i++)
		    if(a[i]!=i)
		    {
		        cout<<"no"<<endl;
		        f=1;
		        break;
		    }
		// haven't gone all the way to the centre
	    if(i!=(n/2)+1)
	    	continue;
	    // from centre point to the end
	    for(;i<n;i++)
		    if(a[i]!=n-i)
		    {
		        cout<<"no"<<endl;
		        f=1;
		        break;
		    }
	    if(f==0)
	    	cout<<"yes"<<endl;
	}
	return 0;
} 