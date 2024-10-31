#include <bits/stdc++.h>

using namespace std;

int a[3], b[3];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 3; ++i)
        cin >> a[i];
    for (int i = 0; i < 3; ++i)
        cin >> b[i];
    int AlicePoints = 0, BobPoints = 0;
    for (int i = 0; i < 3; ++i) {
        if (a[i] > b[i])
            AlicePoints++;
        else if (a[i] < b[i])
            BobPoints++;
    }
    cout << AlicePoints << " " << BobPoints;
}