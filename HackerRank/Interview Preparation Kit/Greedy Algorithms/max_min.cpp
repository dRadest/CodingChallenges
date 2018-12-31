#include <bits/stdc++.h>
    
using namespace std;
    
int main() 
{
    long long int i,n,k,min=999999999,temp;
    cin >> n >> k;
    long long int a[n];
for(i=0;i<n;i++)
cin >> a[i];
sort(a,a+n);
for(i=0;i<=n-k;i++)
{
temp = a[i+k-1]-a[i];
if(temp < min)
min = temp;
}
cout << min << endl;
    
return 0;
}