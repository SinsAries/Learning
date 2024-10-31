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

#define N 1011

ll n;
ll c[1002];
map<ll, vl> cnt;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
   	// setIO( "file");

    cin >> n;
	F0R(i, n * n) {
		ll color;
		cin >> color;
		c[color]++;
	}
	F0R(i, 1002) if(c[i] != 0)
		cnt[c[i]].push_back(i);
	cout << "YES\n";
	F0R(i, n) {
		for (auto& x : cnt)
			cout << x.first << ' ' << sz(x.second) << '\n';
		auto it = cnt.begin();
		if(it->first >= n) {
			ll color = it->second.back();
			ll left = it->first - n;
			F0R(j, n) cout << color << ' ';
			cout << '\n';
			it->second.pop_back();
			if(it->second.empty()) cnt.erase(it);
			if(left != 0)
				cnt[left].push_back(color);
		} else {
			ll color = it->second.back();
			ll left = it->first;
			F0R(j, left) cout << color << ' ';
			it->second.pop_back();
			if(it->second.empty()) cnt.erase(it);

			auto it1 = cnt.rbegin();
			ll color1 = it1->second.back();
			ll left1 = it1->first - (n - left);
			F0R(j, n - left) cout << color1 << ' ';
			it1->second.pop_back();
			if(it1->second.empty()) cnt.erase(it1);
			cnt[left1].push_back(color1);
		}
	}

    rtn 0;
}
