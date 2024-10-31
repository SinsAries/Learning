#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll n, a[100011];
map<int, ll> dem;

ll f(ll x) {
    return x * dem[x];
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++) {
        cin >> a[i];
        dem[a[i]]++;
    }

    int res = 1000000001;
    for(int i=0;i<n;i++) 
        if(f(a[i]) > f(res) || (f(a[i]) == f(res) && a[i] > res))
            res = a[i];
    cout << res;    

    return 0;
}