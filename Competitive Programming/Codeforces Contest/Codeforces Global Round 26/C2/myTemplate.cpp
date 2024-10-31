#include<bits/stdc++.h>

using namespace std;

// type
using ll = long long;
using ld = long double;
using db = double;
using str = string;

// pairs
using pi = pair<int,int>;
using pl = pair<ll,ll>;
using pd = pair<db,db>;

// vector
using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<ll>;
using vd = vector<db>;
using vs = vector<str>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using vpd = vector<pd>;
#define pb push_back
#define pf push_front
#define all(x) x.begin(), x.end()
#define sz(x) x.size()
#define sor(x) sort(all(x))
#define rsz resize
#define rtn return

// binary search
#define lb lower_bound
#define ub upper_bound
template<class T> ll lwb(vector<T>& a, const T& b) { rtn lb(all(a), b) - a.begin(); }
template<class T> ll upb(vector<T>& a, const T& b) { rtn ub(all(a), b) - a.begin(); }

// pairs
#define mp make_pair
#define f first
#define s second

// loops
#define FOR(i,a,b) for (ll i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (ll i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define each(a,x) for (auto& a: x)
#define cont continue
#define bre break

// FILE I/O
void setIn(str s) { freopen(s.c_str(),"r",stdin); }
void setOut(str s) { freopen(s.c_str(),"w",stdout); }
void setIO(str s) {
    setIn(s+".in"); setOut(s+".out");
}
const int MOD = 998244353;
const int MX = 3e5+5;
const ll INF = 1e18 + 7;
const db PI = acos((db)-1);
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
template<class T> using pqg = priority_queue<T,vector<T>,greater<T>>;

// modulo, exponentiation, inverse
ll pow_mod(ll a, ll b, ll m) { ll res = 1; while(b){ res = res * (b & 1 ? a : 1) % m; a = a * a % m; b >>= 1; } rtn res; }
ll inv(ll a, ll m) { rtn pow_mod(a, m - 2, m); }

ll nxt(){
	ll x;
	cin >> x;
	rtn x;
}

struct FenwickTree {
    ll n;
    vl BIT;
    void init(ll _n) {
        n = _n;
        BIT.assign(n + 1, 0);
    }
    void update(ll x, ll d) {
        for (; x <= n; x += x & -x)
            BIT[x] += d;
    }
    ll query(ll x) {
        ll res = 0;
        for (; x > 0; x -= x & -x)
            res += BIT[x];
        rtn res;
    }
};

ll TC;
ll n, a[MX], pref[MX];
FenwickTree ft;

void init(void) {
    cin >> n;
    F0R(i, n)
        cin >> a[i];
}

ll calcK(void) {
    ll x1[2] = {0, 0}, x2[2] = {0, 0}, y[2] = {0, 0};
    F0R(i, n) {
        y[1] = max(abs(x1[0] + a[i]), abs(x2[0] + a[i]));
        x1[1] = min(x1[0] + a[i], y[0] + a[i]);
        x2[1] = max(x2[0] + a[i], y[0] + a[i]);
        x1[0] = x1[1];
        x2[0] = x2[1];
        y[0] = y[1];
    }
    rtn max({x1[0], x2[0], y[0]});
}

void solve(void) {
    vl vals(1, -INF);
    ll K = calcK();
    ll d = 0;
    FOR(i, 1, n + 1) {
        pref[i] = pref[i - 1] + a[i - 1];
        if(pref[i] >= 0)
            d++;
        else 
            vals.pb(2 * pref[i] - 1);
        vals.pb(pref[i]);
    }
    sor(vals);
    vals.erase(unique(all(vals)), vals.end());
    
    ll res = (pref[n] == K ? pow_mod(2, d, MOD) : 0);
    ft.init(sz(vals) + 7);
    ROF(i, 1, n + 1) {
        if(pref[i] >= 0)
            d--;
        else if(pref[n] == K + 2 * pref[i]) {
            ll idx = lwb(vals, 2 * pref[i] - 1);
            res = (res + pow_mod(2, d, MOD) * pow_mod(2, ft.query(sz(vals)) - ft.query(idx), MOD) % MOD) % MOD;
        }
        ll idx = lwb(vals, pref[i]);
        ft.update(idx, 1);
    }
    cout << res << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
   	// setIO("file");

    TC = 1;
    cin >> TC;
    while(TC--) {
        init();
        solve();
    }

    rtn 0;
}
