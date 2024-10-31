#include <bits/stdc++.h>

using namespace std;

#define int long long
#define sz(x) (int)x.size()
#define MASK(i) ((1LL) << (i))
#define all(x) x.begin(), x.end()
#define BIT(x, i) ((x) >> (i) & (1LL))
#define dbg(...) cerr << "#" << __LINE__ << ":[" << #__VA_ARGS__ \
<< "] = [" ,DBG(__VA_ARGS__)

string to_string(const string& s) { return '"' + s + '"'; }
void DBG() { cerr << "]" << endl; }
template<class H, class... T> void DBG(H h, T... t) {
        cerr << to_string(h); if(sizeof...(t)) cerr << ", "; DBG(t...);
}

template <class T>
inline bool maximize(T &a, const T &b) { return (a < b ? (a = b) : 0); }
template <class T>
inline bool minimize(T &a, const T &b) { return (a > b ? (a = b) : 0); }

const int MAXN = 1e5 + 6;
const int MAXM = 1e6 + 5;
const int INF = 1e18;
const int MOD = 1e9 + 9;

typedef pair <int, int> ii;
#define N 5011
int n, k, d;
int t[N], a[N], b[N], dp[N][N];

void solve() {
    cin >> n >> k >> d;
    for (int i = 1; i <= n; i++) 
        cin >> t[i];
    for (int i = 1; i <= k; i++) 
        cin >> a[i];
    for (int i = 1; i <= k; i++) 
        cin >> b[i];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) 
            dp[i][j] = INF;

    for (int i = 1; i <= n; i++) {
        if(i == 1) {
            dp[i][i] = a[t[i]];
            continue;
        }

        for (int j = max(0LL, i - d + 1); j < i; j++){
            if (t[i] == t[i-1]) 
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + b[t[i]]);
            dp[i][j] = min(dp[i][j], dp[i - 1][j] + a[t[i]]);
            if (t[i] == t[j]) 
                dp[i][i] = min(dp[i][i], dp[i - 1][j + 1] + b[t[i]]);
            dp[i][i] = min(dp[i][i], dp[i - 1][j + 1] + a[t[i]]);
        }
    }
    int res = INF;
    for (int i = 1; i <= n; i++) 
        res = min(res, dp[n][i]);
    cout << res << "\n";
}

#define TASK "file"
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // freopen(TASK".in", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    
    int ntest = 1;
    cin >> ntest;
    
    while (ntest--) solve();

    return 0;
}