#include<bits/stdc++.h>

using namespace std;

#define MXN 100011

int N, a[MXN], Q;
long long pref[MXN];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
    }
    cin >> Q;
    while(Q--) {
        int L, R, U, V;
        cin >> L >> R >> U >> V;
        cout << (((pref[R] - pref[L - 1]) > (pref[V] - pref[U - 1])) ? "YES\n" : "NO\n");
    }
}