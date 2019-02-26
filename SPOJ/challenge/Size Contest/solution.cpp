/*
*
* https://www.spoj.com/problems/SIZECON/
* score: 128
*
*/

#include <iostream>
using namespace std;

int main() {
	int t, sum=0, a;
	for(cin>>t; t>0; t--){
		cin >> a;
		if(a>0)
		{
			sum+=a;
		}
	}
	cout << sum << endl;
	return 0;
}