#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll MOD = 1000000007;

ll A, B;

ll gt(ll x) {
    ll res = 1;
    for (ll i = 2; i <= x; i++) 
        res = res * (i % MOD) % MOD;
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> A >> B;
    cout << gt(min(A, B));
}