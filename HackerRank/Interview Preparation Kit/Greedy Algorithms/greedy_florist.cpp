#include<iostream>
#include<queue>
using namespace std;

int main(void){
    int N, K, price;
    long long int totalAmount = 0;
    priority_queue<int> prices;
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        cin >> price;
        prices.push(price);
    }

    int x;
    for (x = 0; x < N; ++x) {
            totalAmount += (x / K + 1) * prices.top();
            prices.pop();

    }

    cout << totalAmount << "\n";
    return 0;
}