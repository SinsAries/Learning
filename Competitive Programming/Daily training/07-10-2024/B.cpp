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

ll R, C;
string grid[50];
bool vis[50][50];

void init(void) {
	cin >> R >> C;
	F0R(i, R)
		cin >> grid[i];
}

string tmp;
void dfs(ll i, ll j) {
	if(!vis[i][j]) {
		vis[i][j] = 1;
		tmp.push_back(grid[i][j]);
		dfs(R - 1 - i, j);
		dfs(i, C - 1 - j);
	}
}

void solve(void) {
	ll ans = 0;
	F0R(i, R) F0R(j, C) if(!vis[i][j]) {
		tmp = "";
		dfs(i, j);
		// F0R(i1, R) {
		// 	F0R(j1, C) {
		// 		cout << vis[i1][j1];
		// 	}
		// 	cout << '\n';
		// }
		ll res = INF;
		F0R(c, 26) {
			ll cur = 0;
			each(a, tmp) {
				ll d = abs(a - 'A' - c);
				cur += min(d, 26 - d);
			}
			res = min(res, cur);
		}
		ans += res;
		// cout << res << '\n';
		// cout << '\n';
	}
	cout << ans;
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
   	// setIO( "file");

    init();
	solve();

    rtn 0;
}
