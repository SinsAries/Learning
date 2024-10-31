#include <bits/stdc++.h>

using namespace std;

int N, Q, A[100011];
long long prefixSum[100011];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> Q;
    for (int i = 1; i <= N; ++i)
        cin >> A[i];
    
    prefixSum[0] = 0;
    for (int i = 1; i <= N; ++i)
        prefixSum[i] = prefixSum[i - 1] + A[i];

    for (int query = 1; query <= Q; ++query) {
        int u, v;
        cin >> u >> v;

        cout << prefixSum[v] - prefixSum[u - 1] << '\n';
    }
}