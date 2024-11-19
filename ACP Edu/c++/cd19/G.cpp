#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll n, a[200011];

ll lcm(ll a, ll b) {
    return a / __gcd(a, b) * b;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    ll res = 1;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        res = lcm(res, a[i]);
    }
    cout << res;
}