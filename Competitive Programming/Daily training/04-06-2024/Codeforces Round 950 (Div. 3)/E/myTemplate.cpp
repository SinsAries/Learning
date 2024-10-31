#include<bits/stdc++.h>

using namespace std;

// type
#define int long long
using ld = long double;
using db = double;
using str = string;

// pairs
using pi = pair<int,int>;
using pd = pair<db,db>;

// vector
using vi = vector<int>;
using vb = vector<bool>;
using vd = vector<db>;
using vs = vector<str>;
using vpi = vector<pi>;
using vpd = vector<pd>;
#define pb push_back
#define pf push_front
#define all(x) x.begin(), x.end()
#define SZ(x) x.size()
#define sor(x) sort(all(x))
#define rsz resize
#define rtn return

// pairs
#define mp make_pair

// FILE I/O
void setIn(str s) { freopen(s.c_str(),"r",stdin); }
void setOut(str s) { freopen(s.c_str(),"w",stdout); }
void setIO(str s) {
    setIn(s+".in"); setOut(s+".out");
}

const int MOD = 1e9 + 7; //998244353;
const int LOG = 18;
const int INF = 1e9 + 7;
const int d4x[4] = {-1, 1, 0, 0};
const int d4y[4] = {0, 0, 1, -1};
const char c4[4] = {'U', 'D', 'R', 'L'};
const int d8x[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int d8y[8] = {1, 1, 0, -1, -1, -1, 0, 1};

#define LENGTH 100005
#define NMOD 2
#define BASE 256
const int HashMod[] = {(int)1e9 + 7, (int)1e9 + 2277, (int)1e9 + 5277, (int)1e9 + 8277, (int)1e9 + 9277};

int pw[NMOD][LENGTH + 1];

void calcpw() {
    for (int i = 0; i < NMOD; i++) {
        pw[i][0] = 1;
        for (int j = 1; j <= LENGTH; j++) {
            pw[i][j] = pw[i][j - 1] * BASE % HashMod[i];
        }
    }
}



struct Hash {
    string s;
    int sz;
    vector<vector<int>> f;
    vector<vector<int>> g;
    Hash(string _s = "") {
        s = _s;
        sz = SZ(s);
    }
    void input() {
        cin >> s;
        sz = SZ(s);
    }
    void calcf() {
        f.assign(NMOD, vector<int>(sz + 5, 0));
        for (int i = 0; i < NMOD; i++) {
            for (int j = 1; j <= sz; j++) {
                f[i][j] = (f[i][j - 1] + pw[i][j] * s[j - 1] % HashMod[i]) % HashMod[i];
            }
        }
    }
    void calcg() {
        g.assign(NMOD, vector<int>(sz + 5, 0));
        for (int i = 0; i < NMOD; i++) {
            for (int j = sz; j >= 1; j--) {
                g[i][j] = (g[i][j + 1] + pw[i][sz - j + 1] * s[j - 1] % HashMod[i]) % HashMod[i];
            }
        }
    }
    void output() {
        cout << s << " " << sz << endl;
    }
};

struct ValueHash {
    int value[NMOD];
    ValueHash() {
        for (int i = 0; i < NMOD; i++) value[i] = -1;
    }
    ValueHash(Hash &a, const int &l, const int &r, const bool &type) {
        if (l <= r) {
            if (type) {
                for (int i = 0; i < NMOD; i++) {
                    value[i] = (a.f[i][r] - a.f[i][l - 1] + HashMod[i]) % HashMod[i] * pw[i][LENGTH - r] % HashMod[i];
                }
            }
            else {
                for (int i = 0; i < NMOD; i++) {
                    value[i] = (a.g[i][l] - a.g[i][r + 1] + HashMod[i]) % HashMod[i] * pw[i][LENGTH - (a.sz - l + 1)] % HashMod[i];
                }
            }
        }
    }
    bool operator == (const ValueHash &other) const {
        for (int i = 0; i < NMOD; i++) {
            if (value[i] != other.value[i]) return false;
        }
        return true;
    }
    bool operator != (const ValueHash &other) const {
        for (int i = 0; i < NMOD; i++) {
            if (value[i] == other.value[i]) return false;
        }
        return true;
    }
    bool operator < (const ValueHash &other) const {
        for (int i = 0; i < NMOD; i++) {
            if (value[i] != other.value[i]) return value[i] < other.value[i];
        }
        return false;
    }
    void output() {
        for (int i = 0; i < NMOD; i++) {
            cout << value[i] << " ";
        }
        cout << endl;
    }
};

bool IsPalindrome(Hash &a, int l, int r) {
    if (l > r) return false;
    int mid = (l + r) / 2;
    return ((r - l + 1) % 2 == 0) ? ValueHash(a, l, mid, 1) == ValueHash(a, mid + 1, r, 0)
                                  : ValueHash(a, l, mid, 1) == ValueHash(a, mid, r, 0);
}

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;


    Hash h(s);

    h.calcf();
    h.calcg();
    

    string t;
    bool type = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            t += (type + '0');
        }
        i += k - 1;
        type ^= 1;
    }
    //cout << t << endl;
    
    Hash h0(t);
    h0.calcf();

  
    //cout << t << endl; 
    for (int i = 1; i <= n; i++) {
        if (ValueHash(h, i + 1, n, 1) == ValueHash(h0, 1, n - i, 1) 
        && ValueHash(h, 1, i, 0) == ValueHash(h0, n - i + 1, n, 1)) {
            cout << i << endl;
            return;
        }
    }

    t = "";
    type = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            t += (type + '0');
        }
        i += k - 1;
        type ^= 1;
    }
    //cout << t;
    
    h0 = Hash(t);
    h0.calcf();

    for (int i = 1; i <= n; i++) {
        if (ValueHash(h, i + 1, n, 1) == ValueHash(h0, 1, n - i, 1) 
        && ValueHash(h, 1, i, 0) == ValueHash(h0, n - i + 1, n, 1)) {
            cout << i << endl;
            return;
        }
    }

    cout << -1 << endl;

}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
   	// setIO("file");

    int TC;
    cin >> TC;
    calcpw();
    while(TC--) {
        solve();
    }

    rtn 0;
}
