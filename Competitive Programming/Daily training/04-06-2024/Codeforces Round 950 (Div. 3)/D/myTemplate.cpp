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

ll TC;
ll n, k;
str S;

void init(void) {
    cin >> n >> k >> S;
}

void solve(void) {
    vpl tmp;
    F0R(i, n) {
        ll j;
        for (j = i; j + 1 < n && S[i] == S[j + 1]; ++j);
        tmp.pb(mp(j - i + 1, S[i] - '0'));
        i = j;
    }
    ll m = sz(tmp);
    if(tmp[m - 1].f >= k) {
        cout << "-1\n";
        return;
    }
    F0R(i, m) {
        if(tmp[i].f > 2 * k) {
            cout << "-1\n";
            return;
        }
        if(tmp[i].f == k) 
            continue;
        if(tmp[i].f == 2 * k && tmp[i].s == tmp[m - 1].s) {
            cout << "-1\n";
            return;
        }
        if(tmp[i].f == 2 * k && tmp[m - 1].f % k != 0) {
            cout << "-1\n";
            return;
        }

        if(tmp[m - 1].f > k) {
            cout << "-1\n";
            return;
        }
        if(tmp[m - 1].f == k && tmp[i].s == tmp[m - 1].s) {
            cout << "-1\n";
            return;
        }
        if((tmp[m - 1].f + tmp[i].f) % k == 0 && tmp[m - 1].s != tmp[i].s){
            cout << "-1\n";
            return;
        }
        if((tmp[i].f % k + tmp[m - 1].f) % k) {
            // cout << tmp[i].f << ' ' << tmp[i].s << ' ' << tmp[m - 1].f << ' ' << tmp[m - 1].s << '\n';
            cout << "-1\n";
            return;
        }
        FOR(j, i + 1, m - 1) if(tmp[j].f % k) {
            cout << "-1\n";
            return;
        }
        // cout << tmp[i].f << ' ' << tmp[i].s << ' ' << tmp[m - 1].f << ' ' << tmp[m - 1].s << '\n';
        ll res = tmp[i].f % k;
        F0R(j, i)
            res += tmp[i].f;
        cout << res << '\n';
        rtn;
    } 
    cout << "-1\n";
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
