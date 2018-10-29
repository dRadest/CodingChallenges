#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, q, k;
    cin >> n >> q;
    vector<vector<int>> a(n);
    for(int i=0; i<n; i++){
        cin >> k;
        for(int j=0; j<k; j++){
            int elem;
            cin >> elem;
            a[i].push_back(elem);
        }
    }
    int x, y;
    for (int i = 0; i < q; i++){
        cin >> x >> y;
        cout << a[x][y] << endl;
    }
    return 0;
}