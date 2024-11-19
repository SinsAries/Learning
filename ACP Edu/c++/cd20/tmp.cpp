#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int numberOfDivisors = 1;
    for (int i = 2; i * i <= n; i++) if(n % i == 0) {
        int p = i;
        int k = 0;

        while(n % p == 0) {
            n /= p;
            k++;
        }

        numberOfDivisors *= (k + 1);

        cout << p << '^' << k;
        if(n != 1)
            cout << " * ";
    }    
    if (n > 1)
        cout << n << '^' << 1;

    cout << '\n' << "So uoc cua n la " << numberOfDivisors << '\n';
}