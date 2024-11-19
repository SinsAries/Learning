#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll x, y;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> x >> y;
    ll d = __gcd(x, y);
    cout << (x / d) * (y / d);
}