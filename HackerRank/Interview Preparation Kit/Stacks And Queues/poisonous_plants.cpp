#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <limits>
#include <tuple>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>
using namespace std;


#define MAX 100005

typedef struct ele
{
    int v1,v2;
}ele;



int  main()
{
    int n;
    cin>>n;
    assert(n>=1&&n<=100000);
    vector<int>a(n);


    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        assert(a[i]>=0 && a[i]<=1000000000);
        a[i]=-a[i];
    }


    stack<ele>s;
    int maxa=0;

    for(int  i=0;i<n;i++)
    {
        if(s.empty())
        {
            s.push({a[i],0});
        }
        else
        {
            ele temp=s.top();

            if(a[i]<temp.v1)
            {
                int sc=1;
                maxa=max(maxa,sc);
                s.push({a[i],sc});
            }
            else
            {

                ele v=s.top();
                int pr=v.v2;
                while(!s.empty()&&v.v1<=a[i])
                {
                    s.pop();
                    if(s.empty())
                        break;
                    pr=max(pr,v.v2);
                    v=s.top();
                }

                if(s.empty())
                {
                    s.push({a[i],0});
                }

                else
                {
                    s.push({a[i],pr+1});
                    maxa=max(maxa,pr+1);
                }


            }
        }
    }
    cout<<maxa<<endl;
}