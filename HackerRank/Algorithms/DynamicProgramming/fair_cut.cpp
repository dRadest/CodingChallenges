#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <deque>
using namespace std;


int main() {
    // input
    int cnt; cin >> cnt;
    int k; cin >> k;
    deque<long long> a(cnt);
    copy_n(istream_iterator<long long>(cin), cnt, a.begin());
    
    // sort and organize in lines. O(n*log(n))
    sort(a.begin(), a.end());
    deque<long long> lens;
    while (!a.empty())
    {
        // right end of the line
        auto r = a.back(); a.pop_back();
        if (a.empty())
        {
            // no points left for new line - insert line with 0 length
            lens.push_back(0);
        }
        else
        {
            auto l = a.front();a.pop_front();
            lens.push_back(r - l);
        }
    }
    
    long long t = 0;
    // calculate sum(every number to every number using lines). O(n)
    for (int i = 0; i < lens.size(); i ++)
    {
        t += lens[i] * (cnt - 2*i - 1);
    }
    
    // check if we should split the smallest line of two with 0-length
    if (k % 2 == 1)
    {
        if (cnt % 2 == 0)
        {
            lens[lens.size() - 1] = 0;
            lens.push_back(0);
        }
    }
    
    int s = k; // number to select
    vector<long long> sl; // selected lines
    int r = cnt - k; // numbers to remain 
    vector<long long> rl; // non-selected lines
    // greedy approach to place line in required group O(n)
    while (s > 0 || r > 0)
    {
        if (s > r)
        {
            sl.push_back(lens.front());
            s -= 2;
        }
        else
        {
            rl.push_back(lens.front());
            r -= 2;
        }
        lens.pop_front();
    }
    
    // result -= sum(selected to selected) O(n)
    for (int i = 0; i < sl.size(); i ++)
        t -= sl[i] * (k - 2*i - 1);
    // result -= sum(non-selected to non-selected) O(n)
    for (int i = 0; i < rl.size(); i ++)
        t -= rl[i] * ((cnt-k) - 2*i - 1);
    cout << t;
    return 0;
}