#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll MOD = 2004010501;

ll addMod(ll X, ll Y, ll M) { return (X % M + Y % M) % M; }
ll subMod(ll X, ll Y, ll M) { return (X % M - Y % M + M) % M; }
ll mulMod(ll X, ll Y, ll M) { return X % M * (Y % M) % M; }

ll X, K, N;

vector<ll> tmp;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> X >> K >> N;
    X %= 100;
    bool vis[100] = {0};
    ll sumInCycle = 0;
    while(vis[X] == false) {
        sumInCycle = addMod(sumInCycle, X, 100);
        tmp.push_back(X);
        vis[X] = true;
        X = addMod(X, K, 100);
    }

    ll res =  mulMod(N / tmp.size(), sumInCycle, 100);
    for (int i = 0; i < (N % tmp.size()); i++)
        res = addMod(res, tmp[i], 100);
    cout << res;
}