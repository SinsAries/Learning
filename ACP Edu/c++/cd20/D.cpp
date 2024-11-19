#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define SQRT(X) (ll)(sqrt(X))

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll N, V, H;
    cin >> N >> V >> H;
    cout << SQRT(H) - (SQRT(V)  + (SQRT(V) * SQRT(V) != V)) + 1;
}