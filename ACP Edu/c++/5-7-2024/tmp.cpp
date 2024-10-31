#include<bits/stdc++.h>

using namespace std;

int main() {
    string n;
    cin >> n;
    int sum = 0;

    for (int i = 0; i < n.size(); ++i) {
        sum += n[i] - '0';
    }

    cout << sum;

    long long n;
    cin >> n;
    long long sum = 0;
    cout << n << '\n';
    while(n > 0) {
        int lastDig = n % 10;
        sum += lastDig;
        n /= 10;
    }
    cout << sum;

}
