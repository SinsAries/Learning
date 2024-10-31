#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)

int n;
map<string, int> cnt;

signed main()
{
    fast;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cout << i << '\n';
        string a, b;
        int c;
        cin >> a >> b >> c;
        cnt[a] += c;
        cnt[b] += c;
    }

    // for (auto i : cnt) {
    //     cout << i.first << ' ' << i.second << endl;
    // }

    return 0;
}   