#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll N, k, res = 0;
map<ll, ll> cnt;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> N >> k;
    ll cur = 0;
    cnt[0] = 1;
    for (int i = 0; i < N; ++i) {
        ll A;
        cin >> A;
        cur += A;

        res += cnt[cur - k];
        
        cnt[cur]++;
    }
    cout << res;

    return 0;
}
