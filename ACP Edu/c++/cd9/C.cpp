#include <bits/stdc++.h>

using namespace std;

string S;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> S;
    int cnt[26];
    for (int i = 0; i < 26; i++)
        cnt[i] = 0;
    for (int i = 0; i < S.size(); i++) {  
        cnt[S[i] - 'a']++;
    }
    int res = 0;
    for (int i = 0; i < 26; i++) {
        if(cnt[i] == 1) {
            res++;
        }
    }
    cout << res;
}