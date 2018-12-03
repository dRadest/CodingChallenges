#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {
    int t;
cin >> t;
while(t--) {
    int n;
    cin >> n;

    // take care of 0 case
    if (!n) {
        cout << 0 << endl;
        continue;
    }

    // input n skills and calc freq
    map <long,int> s;
    for (int i=0;i<n;i++) {
        long skill;
        cin >> skill;
        s[skill]++;
    }

    // init vars
    map <long,int>::iterator it;
    it=s.end();
    it--;
    long prev=it->first;
    int prev_freq=it->second;
    (it->second)--;
    map <long,int>::iterator it_anchor=it;
    int count=1;
    int mincount=0;

    while(true) {
        // gather contestants into teams
        while(true) {
            it--;
            if (it->second<prev_freq) break;

            // choose those with skill difference of 1
            if (it->first==prev-1) {
                prev_freq=it->second;
                prev=it->first;
                (it->second)--;
                count++;
                continue;
            }
            else break;
        }

        // does this team has min count?
        if (!mincount) mincount=count;
        else if (count<mincount) mincount=count;                   

        // skip skills with zero freq
        while (it_anchor->second==0 && it_anchor!=s.begin()) it_anchor--;

        // start gathering a new team
        if (it_anchor->second!=0) {
            it=it_anchor;
            prev=it->first;
            prev_freq=it->second;
            (it->second)--;  
            count=1;
        }
        else break;
    }
    cout << mincount << endl;  
}
    return 0;
}
