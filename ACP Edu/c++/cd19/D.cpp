#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll n, a[200011];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    ll res = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        res = __gcd(res, a[i]);
    }
    cout << res;
}