#include <bits/stdc++.h>

using namespace std;

int x, y;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> x >> y;

    if(x == y) {
        cout << x + y - 1;
        return 0;
    }

    cout << max(x, y);
}