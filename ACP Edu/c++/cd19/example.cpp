#include<bits/stdc++.h>

using namespace std;

long long N, p;

int main() {
    cin >> N >> p;

    if(N % p != 0) {
        cout << 0;
        return 0;
    }

    int res = 0;
    for (long long x = p; x <= N; x += p) {
        if(__gcd(x, N) == p)
            res++;
    }

    cout << res;
}