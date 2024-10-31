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

struct Beam  {
	char edge;
	ll c;	
};

struct BIT {
	vl bit;
	ll n;
	void init(ll sz) {
		n = sz;
		bit.assign(n + 1, 0);
	}
	void upd(ll i, ll x) {
		for(; i <= n; i += i & -i)
			bit[i] += x;
	}
	ll qry(ll i) {
		ll res = 0;
		for(; i; i -= i & -i)
			res += bit[i];
		rtn res;
	}
};

#define MXN 100011

ll L, N, M, res = 1;
Beam beamsFromA[MXN], beamsFromB[MXN];
vl vals;

void init(void) {
	cin >> L >> N >> M;
	F0R(i, N) 
		cin >> beamsFromA[i].edge >> beamsFromA[i].c;
	F0R(i, M)
		cin >> beamsFromB[i].edge >> beamsFromB[i].c;
}

void solve(void) {
	res += N;
	ll R = 0;
	F0R(i, N)
		if(beamsFromA[i].edge == 'U')
			vals.pb(beamsFromA[i].c);
		else
			R++;
	F0R(i, M) 
		if(beamsFromB[i].edge == 'U')
			vals.pb(beamsFromB[i].c);
		else
			res += N + 1;

	sor(vals);
	vals.erase(unique(all(vals)), vals.end());
	F0R(i, N)
		if(beamsFromA[i].edge == 'U') {
			ll idx = lwb(vals, beamsFromA[i].c) + 1;
			beamsFromA[i].c = idx;
		}
	F0R(i, M)
		if(beamsFromB[i].edge == 'U') {
			ll idx = lwb(vals, beamsFromB[i].c) + 1;
			beamsFromB[i].c = idx;
		}

	BIT bit;
	bit.init(sz(vals));
	// F0R(i, N) if(beamsFromA[i].edge == 'U')
	// 	cout << beamsFromA[i].c << '\n';
	F0R(i, N) if(beamsFromA[i].edge == 'U')
		bit.upd(beamsFromA[i].c, 1);
	// cout << bit.qry(2) << '\n';
	F0R(i, M) if(beamsFromB[i].edge == 'U') {
		// cout << beamsFromB[i].c << ' ' << bit.qry(beamsFromB[i].c) << ' ' << N - R << '\n';
		res += (N - R - bit.qry(beamsFromB[i].c)) + R + 1;
	}
	cout << res;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
   	// setIO( "file");
	// setIn("file.in");
    
	init();
	solve();

    rtn 0;
}
