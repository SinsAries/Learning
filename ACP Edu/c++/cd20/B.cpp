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
        cout << p << ' ' << k << '\n';
    }
    if(N > 1) 
        cout << N << ' ' << 1;
}