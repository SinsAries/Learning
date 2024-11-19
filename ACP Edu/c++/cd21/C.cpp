#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll MOD = 2004010501;

ll addMod(ll X, ll Y, ll M) { return (X % M + Y % M) % M; }
ll subMod(ll X, ll Y, ll M) { return (X % M - Y % M + M) % M; }
ll mulMod(ll X, ll Y, ll M) { return X % M * (Y % M) % M; }

ll a, b, c;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b >> c;
    ll res = a % c;
    for (ll i = a + 1; i <= b; i++)
        res = mulMod(res, i, c);
    cout << res << '\n';
}