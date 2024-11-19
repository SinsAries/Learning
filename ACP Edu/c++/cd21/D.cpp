#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll MOD = 2004010501;

ll addMod(ll X, ll Y, ll M) { return (X % M + Y % M) % M; }
ll subMod(ll X, ll Y, ll M) { return (X % M - Y % M + M) % M; }
ll mulMod(ll X, ll Y, ll M) { return X % M * (Y % M) % M; }

ll a, b, c, d, e, f, g, h, i;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 

    cin >> a >> b >> c >> d >> e >> f >> g >> h >> i;
    ll aei = mulMod(mulMod(a, e, MOD), i, MOD);
    ll bfg = mulMod(mulMod(b, f, MOD), g, MOD);
    ll cdh = mulMod(mulMod(c, d, MOD), h, MOD);
    ll afh = mulMod(mulMod(a, f, MOD), h, MOD);
    ll bdi = mulMod(mulMod(b, d, MOD), i, MOD);
    ll ceg = mulMod(mulMod(c, e, MOD), g, MOD);

    ll res = addMod(aei, bfg, MOD);
    res = addMod(res, cdh, MOD);
    res = subMod(res, afh, MOD);
    res = subMod(res, bdi, MOD);
    res = subMod(res, ceg, MOD);

    cout << res;
}