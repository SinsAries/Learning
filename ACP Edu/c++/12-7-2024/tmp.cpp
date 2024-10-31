#include<bits/stdc++.h> 

using namespace std;

long long n, a, res;

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        if(a % 2)
            res += a;
    }
    cout << res;
}