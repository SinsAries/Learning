#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll N;
    cin >> N;
    ll numberOfDivisors = 1;

    for (int i = 2; i * i <= N; i++) if(N % i == 0) {
        ll p = i;
        ll k = 0;
        while (N % p == 0) {
            N /= p;
            k++;
        }
        for (int j = 0; j < k - 1; j++)
            cout << p << " * ";
        if(N == 1)
            cout << p;
        else
            cout << p << " * ";

        numberOfDivisors *= (k + 1);
    }
    if(N > 1) {
        cout << N;
        numberOfDivisors *= 2;
    }
    cout << '\n';
    cout << numberOfDivisors;
}