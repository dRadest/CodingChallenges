#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define F first
#define S second
#define mp make_pair
#define eb emplace_back
const int N = 1e5+10;
ll f[2][N];
bool machine[N];
vector<pii> con[N];
const ll inf = 1e18;
void dfs(int s, int p){
	ll x = 0;
	for(auto it: con[s]){
		int v = it.F, w = it.S;
		if(v == p) continue;
		dfs(v, s);
		x += min(w + f[1][v], f[0][v]);
	}
	if(machine[s]){
		f[1][s] = x;
		f[0][s] = inf;
		return;
	}
	f[0][s] = x;
	for(auto it: con[s]){
		int v = it.F, w = it.S;
		if(v != p) f[1][s] = min(f[1][s], x + f[1][v] - min(f[1][v] + w, f[0][v]));
	}
}
int main(){
	for(int i = 0;i<N;i++) f[1][i] = f[0][i] = inf;
	int n, k, u, v, w;
	cin >> 	n >> k;
	for(int i = 0; i < n - 1; i++){
		cin >> u >> v >> w;
		con[u].eb(mp(v,w));
		con[v].eb(mp(u,w));
	}
	int rt = -1;
	for(int i  = 0; i < k; i++){
		int node;
		cin >> node;
		machine[node] = 1;
		rt = node;
	}
	dfs(rt, -1);
	cout << min(f[0][rt], f[1][rt]) << endl;
}