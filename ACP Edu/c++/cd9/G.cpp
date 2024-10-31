#include <bits/stdc++.h>

using namespace std;

long long n, m, uocChung[200000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    int soUocChung = 0;
    for (long long i = 1; i * i <= n; ++i) {
        if(n % i == 0) {
            if(m % i == 0) {
                uocChung[soUocChung] = i;
                soUocChung++;
            }

            if(m % (n / i) == 0) {
                uocChung[soUocChung] = n / i;
                soUocChung++;
            }
        }
    }
    sort(uocChung, uocChung + soUocChung);
    for (int i = 0; i < soUocChung; ++i) {
        cout << uocChung[i] << ' ';
    }
}