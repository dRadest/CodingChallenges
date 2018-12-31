#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

void solve()
{
    ll N,M;
    ll x,prefix=0,maxim=0;
    cin>>N>>M;
    set<ll> S;
    S.insert(0);
    for(int i=1;i<=N;i++){
        cin>>x;
        prefix = (prefix + x)%M;
        maxim = max(maxim,prefix);
        set<ll>::iterator  it = S.lower_bound(prefix+1);
        if( it != S.end() ){
            maxim = max(maxim,prefix - (*it) + M );
        }
        S.insert(prefix);
    }
    cout<<maxim<<endl;
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)    solve();
    return 0;
}