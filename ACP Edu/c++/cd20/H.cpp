#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll calc(ll x) {
    ll res = 0;
    for (int i = 2; i * i <= x; i++) if(x % i == 0) 
        while(x % i == 0) {
            x /= i;
            res++;
        }
    if(x > 1)
        res++;
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll res = 0;
    ll mx = 0;
    ll N, A;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A;
        res += calc(A);
        mx = max(mx, calc(A));
    }
    cout << res - mx;
}