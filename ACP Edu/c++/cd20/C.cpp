#include <bits/stdc++.h>

using namespace std;

#define ll long long

bool isPrime(ll N) {
    for (int i = 2; i * i <= N; i++) if(N % i == 0)
        return false;
    return true;
}

bool ok(ll N) {
    ll p = sqrt(N);
    if(p * p != N)
        return false;
    return isPrime(p);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll N;
    cin >> N;
    while(N--) {
        ll A;
        cin >> A;
        cout << (ok(A) ? "YES\n" : "NO\n");
    }
}