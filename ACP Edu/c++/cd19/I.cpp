#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll m, n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;
    ll d = __gcd(m, n);
    cout << m / d << '/' << n / d;
}