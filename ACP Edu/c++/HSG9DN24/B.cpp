#include <bits/stdc++.h>

using namespace std;

#define ll long long

string S;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> S;
    ll Duc = 0, Nhi = 0;
    for (int i = 0; i < S.size(); i++) {
        Duc += (S[i] == 'D');
        Nhi += (S[i] == 'N');
    }
    cout << Duc << ' ' << Nhi;
}