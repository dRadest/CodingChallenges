#include <bits/stdc++.h>
using namespace std;

int main()
{
    int p,q,r,i,x,y;
    cin>>p>>q>>r;

    int a[p],b[q],c[r];
    for(i=0;i<p;++i) {
        cin>>a[i];
    }
    for(i=0;i<q;++i) {
        cin>>b[i];
    }
    for(i=0;i<r;++i) {
        cin>>c[i];
    }
    sort(a,a+p);
    sort(b,b+q);
    sort(c,c+r);

    long distinct_a[p],distinct_b[q],distinct_c[r];
    set<int> s;
    for(i=0;i<p;++i) {
        s.insert(a[i]);
        distinct_a[i]=s.size();
    }
    s.clear();
    for(i=0;i<q;++i) {
        s.insert(b[i]);
        distinct_b[i]=s.size();
    }
    s.clear();
    for(i=0;i<r;++i) {
        s.insert(c[i]);
        distinct_c[i]=s.size();
    }

    long ans=0;

    x = upper_bound(a,a+p,b[0])-a;
    y = upper_bound(c,c+r,b[0])-c;

    x-=1,y-=1;
    if(x>=0 && y>=0) {
        ans += distinct_a[x]*distinct_c[y];
    }

    for(i=1;i<q;++i) {
        if(b[i]!=b[i-1]) {
            x = upper_bound(a,a+p,b[i])-a;
            y = upper_bound(c,c+r,b[i])-c;

            x-=1,y-=1;
            if(x>=0 && y>=0) {
                ans += distinct_a[x]*distinct_c[y];
            }
        }
    }
    cout<<ans<<endl;

    return 0;
}