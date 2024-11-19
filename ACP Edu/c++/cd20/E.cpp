#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll MOD = 1e9 + 7;

ll N;

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

    cin >> N;
    for (int i = 2; i <= N; i++)
        process(i);
    ll res = 1;
    for (int i = 2; i <= N; i++) {
        if(cnt[i] % 2 == 1)
            continue;
        
        res = (res * i) % MOD;
    }
    cout << res;
}