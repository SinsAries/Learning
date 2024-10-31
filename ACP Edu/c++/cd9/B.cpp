#include <bits/stdc++.h>

using namespace std;

string S;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> S;
    int cnt = 0;
    for (int i = 0; i < S.size(); i++) {
        if((S[i] - '0') % 2 == 1) {
            cnt++;
        }
    }
    cout << cnt;
}