#include <bits/stdc++.h>

using namespace std;

int N, A[200011];
long long prefixSum[200011];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N;
    for (int i = 1; i <= N; ++i)
        cin >> A[i];
    
    prefixSum[0] = 0;
    for (int i = 1; i <= N; ++i)
        prefixSum[i] = prefixSum[i - 1] + A[i];
    
    int res = 0;
    for (int i = 1; i <= N - 1; ++i) {
        long long leftSum = prefixSum[i];
        long long rightSum = prefixSum[N] - prefixSum[i];

        if(leftSum == rightSum) {
            res++;
        }
    }
    cout << res;
}