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

struct lazySegmentTree {
	ll n;
	vl t, lz;
	lazySegmentTree(ll sz) {
		n = sz;
		t.rsz(4*n);
		lz.rsz(4*n);
	}
	void push(ll v, ll l, ll r) {
		t[v] += lz[v];
		if(l != r) {
			lz[2*v] += lz[v];
			lz[2*v+1] += lz[v];
		}
		lz[v] = 0;
	}
	void update(ll v, ll l, ll r, ll tl, ll tr, ll add) {
		if(tl > tr) rtn;
		if(tl == l && tr == r) {
			lz[v] += add;
			push(v, l, r);
			rtn;
		}
		ll tm = (l+r)/2;
		push(v, l, r);
		update(2*v, l, tm, tl, min(tr, tm), add);
		update(2*v+1, tm+1, r, max(tl, tm+1), tr, add);
		t[v] = max(t[2*v], t[2*v+1]);
	}
	ll query(ll v, ll l, ll r, ll tl, ll tr) {
		if(tl > tr) rtn -INF;
		if(tl == l && tr == r) {
			push(v, l, r);
			rtn t[v];
		}
		ll tm = (l+r)/2;
		push(v, l, r);
		rtn max(query(2*v, l, tm, tl, min(tr, tm)), query(2*v+1, tm+1, r, max(tl, tm+1), tr));
	}
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
   	// setIO( "file");

    init();
	solve();

    rtn 0;
}
