#include <bits/stdc++.h>
#define MAX 1000003
using namespace std;

vector<int> v[MAX];
bool visit[MAX];
int a[MAX],c,id;

void bfs(int i)
{
    memset(visit, false, sizeof visit);
    queue<pair<int,int> > q;
    pair<int,int> p;
    q.push({i,0});
    visit[i]=true;

    while(!q.empty()) {
        p=q.front();
        q.pop();
        for(auto x: v[p.first]) {
            if(!visit[x]) {
                if(a[x] == id) {
                    c=p.second+1;
                    return;
                }
                visit[x]=true;
                q.push({x,p.second+1});
            }
        }
    } 
}

int main()
{
    int n,m,i,x,y;
    cin>>n>>m;

    for(i=0;i<m;++i) {
        cin>>x>>y;
        x-=1,y-=1;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    for(i=0;i<n;++i) {
        cin>>a[i];
    }
    cin>>id;

    int ans=1e9;
    for(i=0;i<n;++i) {
        if(a[i]==id) {
            c=1e9;
            bfs(i);
            ans=min(ans, c);
        }
    }
    if(ans==1e9) {
        ans=-1;
    }
    cout<<ans<<endl;

    return 0;
}