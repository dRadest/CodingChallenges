#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
#define mp make_pair
#define pb push_back
#define sz(x) ((int) (x).size())


#define X first
#define Y second

const int maxn = 3005;
ll a[maxn];
ll dp[2][maxn]; // minimal possible (unfairness - coef * (sum of Li's integers))

int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    for (int i = 0; i <= 1; i++)
       for (int j = 0; j <= k; j++)

              dp[i][j] = (i==0 && j==0?0ll:(ll)1e18);
    ll psum = 0ll;
    int coef;
    for (int i = 1; i <= n; i++)
    {
       for (int j = 0; j <= k; j++)
         {
            coef = (k-j)*2 - (n-i);
            dp[i&1][j] = min(dp[(i-1)&1][j] + (ll)j * a[i-1],  //Lu's
              (j>0 ? dp[(i-1)&1][j-1] - psum + (ll)coef * a[i-1] + (ll)(i-j) * a[i-1] : (ll)1e18));

         }
       psum += a[i-1];
    }
    cout << dp[n&1][k] << endl;
    return 0;
}