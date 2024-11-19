#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll MOD = 1e9 + 7;

ll addMod(ll X, ll Y, ll M) { return (X % M + Y % M) % M; }
ll subMod(ll X, ll Y, ll M) { return (X % M - Y % M + M) % M; }
ll mulMod(ll X, ll Y, ll M) { return X % M * (Y % M) % M; }

ll N;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll A = N, B = N + 1, C = 2 * N + 1;
    if(N % 2 == 0) A /= 2;
    else B /= 2;

    if(N % 3 == 0) A /= 3;
    else if(N % 3 == 1) C /= 3;
    else B /= 3;

    cout << mulMod(mulMod(A, B, MOD), C, MOD); 
}