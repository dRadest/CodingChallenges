#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long iNum = 0;

void cntInv(vector<int>& a, vector<int>& b, int l, int r){
    if(r - l < 2)
        return;
    int mid = (l + r) / 2;
    cntInv(b, a, l, mid);
    cntInv(b, a, mid, r);
    int i = mid - 1;
    int j = r - 1;
    int k = r - 1;
    while(i >= l && j >= mid){
        if(a[j] >= a[i])
            b[k--] = a[j--];
        else{
            iNum += j - mid + 1;
            b[k--] = a[i--];
        }
    }
    while(i >= l){
        b[k--] = a[i--];
    }
    while(j >= mid){
        b[k--] = a[j--];
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T;
    cin >> T;
    while(T--){
        vector<int> a;
        int n;
        cin >> n;
        for(int i = 0; i < n; ++i){
            int num;
            cin >> num;
            a.push_back(num);
        }
        vector<int> b(a);
        iNum = 0;
        cntInv(a, b, 0, a.size());

        cout << iNum << endl;
    }
    return 0;
}