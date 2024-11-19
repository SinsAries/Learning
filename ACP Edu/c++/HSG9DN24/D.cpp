#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define MXN 100011
#define INF 1000000001

ll N, A[MXN];

ll LIS(ll n, ll array[]) {
    ll dp[n];
    for (ll i = 0; i < n; ++i)
        dp[i] = INF;
    for (ll i = 0; i < n; ++i) {
        ll pos = lower_bound(dp, dp + n, array[i]) - dp;
        dp[pos] = array[i];
    }
    for (ll i = 0; i < n; ++i)
        if (dp[i] == INF)
            return i;
    return n;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> A[i];
    cout << N - LIS(N, A);
}