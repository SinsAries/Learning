#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll N, A[100011], Q;
ll pref[100011];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> Q;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    pref[0] = 0;
    for (int i = 1; i <= N; i++) {
        pref[i] = pref[i - 1] + A[i];
    }

    for (int query = 1; query <= Q; query++) {
        int L, R;
        cin >> L >> R;
        cout << pref[R] - pref[L - 1] << '\n';
    }

    return 0;
}