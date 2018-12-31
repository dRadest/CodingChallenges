#include <bits/stdc++.h>

using namespace std;

int rate [100000 + 10];
long long values [100000 + 10];   // use long long

int main()
{
    int n;
    long long ans = 0, tmp = 0;

    cin >> n;

    for(int i = 0; i < n; i++) cin >> rate[i];

    values[0] = 1;
                                        // case 1
    for(int i = 1; i < n; i++){         // scan input array from left to right

        if(rate[i] > rate[i - 1]){

            values[i] = values[i - 1] + 1;  // case 1, a

        } else values[i] = 1;               // case 1,b
    }

    ans = values[n - 1];                // case 2

    for(int i = n - 2; i >= 0; i--){    // scan input array from right to left

        if(rate[i] > rate[i + 1]){

            tmp = values[i + 1] + 1;        // case 2, a

        } else tmp = 1;                     // case 2, b

        ans += max(tmp, values[i]);   // maximum of the two values for child (i)
        values[i] = tmp;
    }

    cout << ans;

    return 0;
}