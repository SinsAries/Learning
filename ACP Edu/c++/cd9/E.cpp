#include <bits/stdc++.h>

using namespace std;

int N, A[100011], B[100011], C[100011];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }
    for (int i = 0; i < N; i++) {
        C[i] = A[i] + B[i];
    }
    for (int i = 0; i < N; i++) {
        cout << C[i] << " ";
    }
}