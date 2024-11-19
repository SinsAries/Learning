#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    ll res = n;
    for (ll a = 1; a * a <= n; a++) if(n % a == 0) {
        ll b = n / a;
        if(__gcd(a, b) == 1) 
            res = min(res, b);
    }
    cout << n / res << ' ' << res; 
}