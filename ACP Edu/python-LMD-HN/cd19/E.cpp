#include<bits/stdc++.h>

using namespace std;

int main() {
    long long a, b;
    cin >> a >> b;
    long long d = __gcd(a, b);
    long long res = a / d * b;
    cout << d << ' ' << res;
}