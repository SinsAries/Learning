#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll a, b, c;

ll addMod(ll X, ll Y, ll M) { return (X % M + Y % M) % M; }
ll subMod(ll X, ll Y, ll M) { return (X % M - Y % M + M) % M; }
ll mulMod(ll X, ll Y, ll M) { return (X % M * Y % M) % M; }

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b >> c;

    cout << addMod(a, b, c) << ' ' << subMod(a, b, c) << ' ' << mulMod(a, b, c) << '\n';
}