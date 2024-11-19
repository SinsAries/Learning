#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll a, b, res = 0;

ll sumDigit(ll x) {
    ll res = 0;
    while(x != 0) {
        res += x % 10;
        x /= 10;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b;
    for (ll i = 1; i * i <= a; i++) if(a % i == 0) {
        if(b % i == 0) 
            res = max(res, sumDigit(i));

        ll j = a / i;
        if(b % j == 0)
            res = max(res, sumDigit(j));
    }

    cout << res;
}