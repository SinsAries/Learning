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
ll n, a[MX];

void init(void) {
    cin >> n;
    F0R(i, n) a[i] = nxt();
}

str bin(ll x) {
    str ans = "";
    ll tmp = 0;
    while((1 << tmp) <= x) 
        ans.pb(((x >> (tmp++)) & 1) ? '1' : '0');
    reverse(all(ans));
    return ans;
}

void process(pl prev, pl cur) {
    if(prev.f == -1) {
        bool ok = (cur.f == 1);
        ROF(i, prev.s + 1, cur.s) if(ok) {
            a[i] = a[i + 1] * 2;
            ok = 1 - ok;
        } else {
            a[i] = a[i + 1] / 2;
            ok = 1 - ok;
        }
        return;
    }
    if(cur.f == -1) {
        bool ok = (prev.f == 1);
        FOR(i, prev.s + 1, cur.s) if(ok) {
            a[i] = a[i - 1] * 2;
            ok = 1 - ok;
        } else {
            a[i] = a[i - 1] / 2;
            ok = 1 - ok;
        }
        return;
    }
    str prevBin = bin(prev.f), curBin = bin(cur.f);
    ll L1 = sz(prevBin), L2 = sz(curBin);
    ll maxSamePrefixLength = 0;
    while(maxSamePrefixLength < min(L1, L2) && prevBin[maxSamePrefixLength] == curBin[maxSamePrefixLength])
        maxSamePrefixLength++;
    ll operations = cur.s - prev.s;
    ll minNeed = L1 + L2 - maxSamePrefixLength * 2;
    if(operations < minNeed || (operations - minNeed) % 2)
        return;
    FOR(i, prev.s + 1, cur.s) {
        if(i - prev.s <= L1 - maxSamePrefixLength) {
            a[i] = a[i - 1] / 2;
            continue;
        }
        if(i - prev.s <= minNeed) {
            if(curBin[maxSamePrefixLength - 1 + (i - prev.s) - (L1 - maxSamePrefixLength)] == '0')
                a[i] = a[i - 1] * 2;
            else
                a[i] = a[i - 1] * 2 + 1;
            continue;
        }
        process(mp(a[i - 1], i - 1), mp(-1, cur.s));
        return;
    }
}

void solve(void) {
    vpl numAndPos(1, {-1, -1});
    F0R(i, n) if(a[i] != -1)
        numAndPos.pb(mp(a[i], i));
    numAndPos.pb(mp(-1, n));
    if(sz(numAndPos) == 2) {
        F0R(i, n)
            cout << (i % 2 ? 1 : 2) << ' ';
        cout << '\n';
        return;
    }
    FOR(i, 1, sz(numAndPos)) {
        pl prev = numAndPos[i-1];
        pl cur = numAndPos[i];
        process(prev, cur);
    }

    bool ok = 1;
    F0R(i, n) if((a[i] == -1) || (i < n - 1 && !((a[i] / 2 == a[i + 1]) || (a[i + 1] / 2 == a[i]))))
        ok = 0;
    if(ok) {
        F0R(i, n) cout << a[i] << ' ';
        cout << '\n';
    } else 
        cout << "-1\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
   	// setIO("file");

    TC = 1;
    cin >> TC;
    while(TC--) {
        init();
        // cout << "CAC";
        solve();
    }

    // cout << calc(4, 2);

    rtn 0;
}
