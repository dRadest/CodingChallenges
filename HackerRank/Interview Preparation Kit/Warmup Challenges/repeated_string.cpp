#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
typedef long long ll;

int main(){
    string s;
    cin >> s;
    ll n;
    cin >> n;
    
	ll numas = 0;
	for(ll i = 0; i < s.length(); i++)
		if(s.at(i) == 'a')
			numas++;

	ll totalas = (n / s.length()) * numas;

	if(n%s.length()){
		for(ll i=0; i<n%s.length(); i++){
			if(s.at(i) == 'a')
				totalas++;
		}
	}
	cout << totalas << endl;

    return 0;
}
