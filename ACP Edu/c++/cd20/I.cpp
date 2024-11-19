#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll X;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> X;
    ll cnt_2 = 0, cnt_5 = 0;
    while(X % 2 == 0)
        X /= 2, cnt_2++;
    while(X % 5 == 0)
        X /= 5, cnt_5++;
    if(X > 1) 
        cout << "-1";
    else {
        cout << "1";
        for (int i = 0; i < max(cnt_2, cnt_5); i++) 
            cout << "0";
    }
}