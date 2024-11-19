#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll MOD = 2004010501;

ll addMod(ll X, ll Y, ll M) { return (X % M + Y % M) % M; }
ll subMod(ll X, ll Y, ll M) { return (X % M - Y % M + M) % M; }
ll mulMod(ll X, ll Y, ll M) { return X % M * (Y % M) % M; }

ll L, R, M;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> L >> R >> M;
    ll res = M - 1;
    for (int i = L; i <= R; i++) {
        for (int j = i + 1; j <= R; j++) {
            res = min(res, mulMod(i, j, M)); 
        }
    }
    cout << res;
}