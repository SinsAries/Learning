#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll a, b;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b;
    cout << __gcd(a, b) << ' ' << a / __gcd(a, b) * b;
}