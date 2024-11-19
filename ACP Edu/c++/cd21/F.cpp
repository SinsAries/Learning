#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll MOD = 1e9 + 7;

ll addMod(ll X, ll Y, ll M) { return (X % M + Y % M) % M; }
ll subMod(ll X, ll Y, ll M) { return (X % M - Y % M + M) % M; }
ll mulMod(ll X, ll Y, ll M) { return X % M * (Y % M) % M; }

ll pow_mod(ll a, ll b, ll M) {
    if(b == 0) return 1;
    ll val = pow_mod(a, b / 2, M);
    if(b % 2 == 0)
        return mulMod(val, val, M);
    else
        return mulMod(mulMod(val, val, M), a, M);
}

ll inv(ll a, ll M) { return pow_mod(a, M - 2, M); }

ll N;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    cout << mulMod(mulMod(N, N + 1, MOD), inv(2, MOD), MOD);
}