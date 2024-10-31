#include <bits/stdc++.h>

using namespace std;

#define ll long long

int n, A[100011];
ll chi_phi[100011], H[100011];
ll chi_phi2[100011], H2[100011];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i) 
        cin >> A[i];
    
    chi_phi[0] = 0;
    for (int i = 1; i <= n; ++i) {
        if (A[i] > H[i - 1]) 
            H[i] = A[i];
        else 
            H[i] = H[i - 1] + 1;

        chi_phi[i] = chi_phi[i - 1] + H[i] - A[i];
    }
    
    chi_phi2[n + 1] = 0;
    for (int i = n; i >= 1; --i) {
        if (A[i] > H2[i + 1]) 
            H2[i] = A[i];
        else 
            H2[i] = H2[i + 1] + 1;

        chi_phi2[i] = chi_phi2[i + 1] + H2[i] - A[i];
    }

    ll res = 1000000000000000000;
    for (int i = 2; i < n; i++) {
        int tmp = max(H[i - 1], H2[i + 1]) + 1;
        ll cost = chi_phi[i - 1] + chi_phi2[i + 1] + max(0, tmp - A[i]);
        res = min(res, cost);
    }
    cout << res;

    return 0;
}