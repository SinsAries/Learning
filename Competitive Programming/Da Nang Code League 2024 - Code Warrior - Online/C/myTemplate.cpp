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
const int MX = 2e5+5;
const ll INF = 1e9 + 1;
const db PI = acos((db)-1);
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
template<class T> using pqg = priority_queue<T,vector<T>,greater<T>>;
 
// modulo, exponentiation, inverse
ll pow_mod(ll a, ll b, ll m) { ll res = 1; while(b){ res = res * (b & 1 ? a : 1) % m; a = a * a % m; b >>= 1; } rtn res; }
ll inv(ll a, ll m) { rtn pow_mod(a, m - 2, m); }
 
ll nxt(){
	int s=0; char c=getchar();bool f=0;
	while(c<'0'||c>'9'){if(c=='-') f=1;c=getchar();}
	while(c>='0'&&c<='9') s=(s<<1)+(s<<3)+c-48,c=getchar();
	return f?-s:s;
}
 
ll a, b, c, d;
unsigned long long n;

struct Matrix {
    ll val[5][5];
    Matrix() {
        memset(val, 0, sizeof val);
    }
};
 
Matrix mul(Matrix a, Matrix b) {
    Matrix res;
    F0R(i, 5) F0R(j, 5) F0R(t, 5)
        res.val[i][j] = (res.val[i][j] + a.val[i][t] * b.val[t][j] % MOD) % MOD;
    rtn res;
}
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
   setIO("file");
 
    cin >> a >> b >> c >> d >> n;
     ll G[3];
    ll F[2];
    G[0] = d;
    G[1] = c;
    G[2] = G[1] + 2 * G[0];
    F[0] = b;
    F[1] = a;
    if(n < 2) {
        cout << F[n];
        return 0;
    }

    n--;
    Matrix base;
    Matrix res;
    F0R(i, 5) res.val[i][i] = 1;
    vector<vl> tmp = {{0, 0, 0, 0, 1},
             {1, 0, 2, 0, 1},
             {0, 1, 1, 0, 1},
             {0, 0, 0, 0, 2},
             {0, 0, 0, 1, 3}};
    F0R(i, 5) F0R(j, 5)
        base.val[i][j] = tmp[i][j];
    while(n) {
        if(n & 1)
            res = mul(res, base);
        base = mul(base, base);
        n >>= 1;
    }
    ll ans = G[0] * res.val[0][4] % MOD;
    ans = (ans + G[1] * res.val[1][4] % MOD) % MOD;
    ans = (ans + G[2] * res.val[2][4] % MOD) % MOD;
    ans = (ans + F[0] * res.val[3][4] % MOD) % MOD;
    ans = (ans + F[1] * res.val[4][4] % MOD) % MOD;
    cout << ans;
 
    rtn 0;
}