#include <bits/stdc++.h>

using namespace std;

#define ll long long

int n, A[200011];
ll pref[200011];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> A[i];
    
    pref[0] = 0;
    for (int i = 1; i <= n; ++i) 
        pref[i] = pref[i - 1] + A[i];
    
    int dem = 0;
    for (int i = 1; i <= n - 1; i++) {
        ll L = pref[i];
        ll R = pref[n] - pref[i];

        if(L == R) 
            dem++;
    }

    cout << dem;

    return 0;
}