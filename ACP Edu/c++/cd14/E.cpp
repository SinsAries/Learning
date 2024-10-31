#include <bits/stdc++.h>

using namespace std;

#define ll long long

int N, K, A[100011];
ll pref[100011];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> K;
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }

    pref[0] = 0;
    for (int i = 1; i <= N; ++i) {
        pref[i] = pref[i - 1] + A[i];
    }

    ll res = 0;
    for (int i = 1; i + K - 1 <= N; ++i) 
        res = max(res, pref[i + K - 1] - pref[i - 1]);
    cout << res;

    return 0;
}