#include <bits/stdc++.h>

using namespace std;

int N, K, A[100011];
long long prefixSum[100011];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> K;
    for (int i = 1; i <= N; ++i)
        cin >> A[i];
    
    prefixSum[0] = 0;
    for (int i = 1; i <= N; ++i)
        prefixSum[i] = prefixSum[i - 1] + A[i];

    long long res = 0;
    for (int i = 1; i + K - 1 <= N; ++i) {
        long long sum = prefixSum[i + K - 1] - prefixSum[i - 1];
        res = max(res, sum);
    }
    cout << res;
}