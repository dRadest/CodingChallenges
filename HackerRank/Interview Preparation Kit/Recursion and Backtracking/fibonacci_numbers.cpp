#include <iostream>

using namespace std;

int fibonacci(int n) {
    // Complete the function.
    return (n > 2) ? fibonacci(n - 1) + fibonacci(n - 2) : 1;
}

int main() {
    int n;
    cin >> n;
    cout << fibonacci(n);
    return 0;
}

