#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll A, B, C;

map<ll, ll> cnt;

void process(ll x) {
    for (ll i = 2; i * i <= x; i++) if(x % i == 0)
        while(x % i == 0) {
            x /= i;
            cnt[i]++;
        }
    if(x > 1)
        cnt[x]++;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> A >> B >> C;
    process(A);
    process(B);
    process(C);

    ll res = 0;
    for (auto i : cnt) 
        res = __gcd(res, i.second);
    cout << res;
}