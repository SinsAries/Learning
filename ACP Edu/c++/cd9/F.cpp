#include <bits/stdc++.h>

using namespace std;

int TC, a, b, c;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> TC;
    for (int i = 0; i < TC; ++i) {
        cin >> a >> b >> c;
        cout << max({max(a, b) % min(a, b), max(b, c) % min(b, c), max(a, c) % min(a, c)}) << '\n';
    }
}