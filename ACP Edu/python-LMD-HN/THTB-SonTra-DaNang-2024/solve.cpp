#include<bits/stdc++.h>

using namespace std;

long long n;
long long a[10000001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (long long i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a + n);
    
    long long s = -1;
    long long cost = 1000000001;

    for (long long i = 0; i < n; ++i) {
        long long doanh_thu = a[i] * (n - i);

        if(doanh_thu > s) {
            s = doanh_thu;
            cost = a[i];
        }
        if(doanh_thu == s && a[i] < cost)
            cost = a[i];
    }

    cout << s << ' ' << cost;

    return 0;
}