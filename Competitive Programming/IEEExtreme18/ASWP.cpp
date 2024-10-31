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

#define MXN 100011

ll N, Q, A[MXN], x[101], pref[MXN];

void init(void) {
	cin >> N >> Q;
	F0R(i, N) {
		cin >> A[i];
		pref[i] = (i ? pref[i - 1] : 0) + A[i];
	}
	F0R(i, Q)
		cin >> x[i];
}

bool ok(ll l, ll r, ll val) {
	if((r - l + 1) & 1)
		if(A[r--] > val)
			return false;
	while(l < r) 
		if(A[l++] + A[r--] > val)
			return false;
	return true;
}

ll calcSum(ll l, ll r) { rtn (pref[r] - (l ? pref[l - 1] : 0)); }

void solve(void) {
	F0R(IDX, Q) {
		ll X = x[IDX];
		ll res = 0;
		ll maxR[MXN];
		R0F(i, N) {
			ll l = i, r = N;
			while(l + 1 < r) {
				ll m = l + (r - l + 1) / 2;
				if(ok(i, m, X))
					l = m;
				else
					r = m;
			}
			maxR[i] = l;
			if(ok(i, maxR[i], X)) 
				res += calcSum(i + 1, maxR[i]) - A[i] * (maxR[i] - i);
		}
		cout << res << '\n';
	}
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
   	// setIO( "file");
	setIn("file.in");
    
	init();
	solve();

    rtn 0;
}

// (i, j) thỏa mãn:
// 	1. đoạn chẵn:
// 		y = (i + j + 1) / 2
// 		->  a[y - 1] + a[y] <= x
// 			a[y - 2] + a[y + 1] <= x
// 			...
// 	2. đoạn lẻ:
// 		số thừa là số lớn nhất
// đi ngược:
// 	maxr[i] = min(maxr[i], maxr[i + 1] + 1)
// 	mỗi vị trí i:
// 		đoạn i -> maxr[i] thỏa mãn
// 		i -> maxr[i] - 1 thỏa mãn
// 		i -> maxr[i] - 2 thỏa mãn
// 		...
// 		i -> i + 1 thỏa mãn
