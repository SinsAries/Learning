#include <bits/stdc++.h>

using namespace std;

#define ll long long

int n, A[50011], Q;
ll pref[50011];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i) 
        cin >> A[i];
    
    pref[0] = 0;
    for (int i = 1; i <= n; ++i) 
        pref[i] = pref[i - 1] + A[i];   
    
    cin >> Q;
    while(Q--) {
        int L, R;
        cin >> L >> R;
        cout << fixed << setprecision(6) << double(pref[R - 1] - pref[L - 1]) / (R - L) << '\n';
    }

    return 0;
}