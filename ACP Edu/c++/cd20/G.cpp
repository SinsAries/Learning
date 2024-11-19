#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll TC;

ll calc(ll x) {
    ll res = 1;
    for (int i = 2; i * i <= x; i++) if(x % i == 0) {
        ll cnt = 0;
        while(x % i == 0) {
            x /= i;
            cnt++;
        }
        if(cnt % 2 == 1)
            res *= i;
    }
    if(x > 1)
        res *= x;
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> TC;
    while(TC--) {
        ll N;
        cin >> N;
        map<ll, ll> cnt;
        ll res = 0;
        while(N--) {
            ll A;
            cin >> A;
            ll val = calc(A);
            res += cnt[val];
            cnt[val]++;
        }
        cout << res << '\n';
    }
}