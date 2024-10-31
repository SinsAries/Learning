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
const int MOD = 1e9 + 7;
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

struct SegmentTree {
    ll n;
    vl seg;
    const ll ID = 0;
    ll comb(ll A, ll B) { rtn min(1000000001LL, A*B/__gcd(A, B)); }
    void recalc(ll p) { seg[p] = comb(seg[p * 2], seg[p * 2 + 1]); }

    void init(ll _n) {
        n = _n;
        seg.assign((n + 1) * 2, ID);
    }
    void build(vl& a) {
        F0R(i, n)
            seg[i + n] = a[i];
        R0F(i, n)
            recalc(i);
    }
    ll query(ll L, ll R) {
        ll resL = 1, resR = 1;
        for(L += n, R += n; L <= R; L >>= 1, R >>= 1) {
            if(L % 2 == 1) 
                resL = comb(resL, seg[L++]);
            if(R % 2 == 0)
                resR = comb(resR, seg[R--]);
        }
        return comb(resL, resR);
    }
};

ll TC;
ll n;
vl a;
map<ll, bool> isInA;
SegmentTree st;
void init(void) {
    cin >> n;
    a.rsz(n);
    isInA.clear();
    F0R(i, n) {
        cin >> a[i];
        isInA[a[i]] = true;
    }
}

void solve(void) {
    st.init(n);
    st.build(a);
    ll res = 0;
    cout << st.query(0, 0) << '\n';
    F0R(i, n)
        FOR(j, i, n)
            cout << i + 1 << ' ' << j + 1 << ' ' << st.query(i, j) << '\n';
    // F0R(i, n)
    //     FOR(j, i, n)
    //         if(!isInA[st.query(i, j)])
    //             res = max(res, j - i + 1);
    // cout << res << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
   	setIO("file");

    TC = 1;
    cin >> TC;
    while(TC--) {
        init();
        solve();
    }

    rtn 0;
}
