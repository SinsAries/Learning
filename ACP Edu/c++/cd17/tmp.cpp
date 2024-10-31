#include <bits/stdc++.h>

using namespace std;

int n, m, a[511][511], q;

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> a[i][j];
    cin >> q;
    while(q--) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;

        int ans = 0;
        for (int j = 0; j < m; ++j)
            ans += a[u][j];
        
        for (int i = 0; i < n; ++i)
            ans += a[i][v];
        
        ans -= a[u][v];

        cout << ans << '\n';
    }
}
