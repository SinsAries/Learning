#include <bits/stdc++.h>

using namespace std;

int N, Q, A[500011];

int main() {
    cin >> N >> Q;
    for (int i = 0; i < N; ++i)
        cin >> A[i];
    for (int query = 0; query < Q; ++query) {
        int l, r;
        cin >> l >> r;
        int res = 0;
        for (int i = l; i < r; ++i) {
            res += A[i];
        }
        cout << res << '\n';
    }
}