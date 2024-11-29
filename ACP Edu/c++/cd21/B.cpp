#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll MOD = 2004010501;

ll addMod(ll X, ll Y, ll M) { return (X % M + Y % M) % M; }
ll subMod(ll X, ll Y, ll M) { return (X % M - Y % M + M) % M; }
ll mulMod(ll X, ll Y, ll M) { return (X % M * Y % M) % M; }

ll Q, S, x;
char type;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> Q;
    while(Q--) {
        cin >> type >> x;
        if(type == '+') {
            S = addMod(S, x, MOD);
        } else {
            S = subMod(S, x, MOD);
        }
    }
    cout << S;
}