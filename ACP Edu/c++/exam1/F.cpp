#include <bits/stdc++.h>

using namespace std;

string S, T;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> S >> T;
    int N = S.size(), M = T.size(), res = 0;

    for (int i = 0; i + M - 1 < N; i++) {
        bool ok = 1;
        for (int j = i; j < i + M; j++)
            if (S[j] != T[j - i]) {
                ok = 0;
                break;
            }
        res += ok;
    }
    
    cout << res;
}