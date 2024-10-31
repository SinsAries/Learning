#include <bits/stdc++.h>

using namespace std;

#define ll long long

int N, Q, A[100011];
ll pref[100011];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> Q;
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }

    pref[0] = 0;
    for (int i = 1; i <= N; ++i) {
        pref[i] = pref[i - 1] + A[i];
    }

    while(Q--) {
        int u, v;
        cin >> u >> v;
        cout << pref[v] - pref[u - 1] << '\n';
    }

    return 0;
}