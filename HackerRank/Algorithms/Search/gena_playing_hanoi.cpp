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
using namespace std;
typedef long long ll;

#define INF 0x3fffffff
#define repp(i, n, m) for (int i = n; i <= m; i++)
#define rep(i, n, m) for (int i = n; i < m; i++)
#define sa(n) scanf("%d", &(n))

const int maxn = 1e3 + 5;
const ll mod = 1000000;
const double PI = acos(-1.0);

int n;
int d[1 << 20];
queue<int>que;

void solve()
{
	int i, j, k;
	int mask = 0;
	sa(n);
	rep(i, 0, n)
	{
		sa(k);
		k--;
		mask |= ((k) << 2 * i);
	}
	rep(i, 0, 1 << 20)
	{
		d[i] = INF;
	}
	d[mask] = 0;
	que.push(mask);

	while (!que.empty())
	{
		k = que.front();
		que.pop();

		if (k == 0)
			break;
		vector<int>b[4];
		rep(i, 0, n)
		{
			b[(k >> (2 * i)) & 3].push_back(i);
		}
		rep(i, 0, 4)
		{
			b[i].push_back(INF);
		}
		rep(i, 0, 4)
		{
			rep(j, 0, 4)
			{
				if (b[i][0] >= b[j][0])
				{
					continue;
				}
				int p = b[i][0];
				int to = k ^ ((i^j) << (2 * p));
				if (d[to] < INF)
				{
					continue;
				}
				d[to] = d[k] + 1;
				que.push(to);
			}
		}
	}
	printf("%d\n", d[0]);
}

int main()
{
	solve();
	return 0;
}