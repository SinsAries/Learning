/**
 *    author:  longvu
 *    created: 06/09/24 22:07:52
**/
#include<bits/stdc++.h>

using namespace std;

#define int long long
#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
const int INF = numeric_limits<int>::max();
const int nax = (int)(2010001);
const int mod = 998244353;

template<class X, class Y>
bool maximize(X& x, const Y y) {
    if (y > x) {x = y; return true;}
    return false;
}
template<class X, class Y>
bool minimize(X& x, const Y y) {
    if (y < x) {x = y; return true;}
    return false;
}

struct Fenwick_tree {
    int n, BIT[nax];
    void reseter(int _n) {
        n = _n;
        for (int i = 1; i <= n; ++i) {
            BIT[i] = 0;
        }
    }

    void update(int idx, int val) {
        for (int i = idx; i <= n; i += i & (-i)) {
            BIT[i] += val;
        }
    }
    int get(int r) {
        int res = 0;
        for (int i = r; i > 0; i -= i & (-i)) {
            res += BIT[i];
        }
        return res;
    }
};

template<int MOD>
struct ModInt {
    unsigned x;
    ModInt() : x(0) { }
    ModInt(signed long long sig) : x(sig % MOD + (sig < 0 ? MOD : 0)) { }
    int get() const { return (int)x; }

    ModInt &operator+=(ModInt that) { if ((x += that.x) >= MOD) x -= MOD; return *this; }
    ModInt &operator-=(ModInt that) { if ((x += MOD - that.x) >= MOD) x -= MOD; return *this; }
    ModInt &operator*=(ModInt that) { x = (unsigned long long)x * that.x % MOD; return *this; }

    ModInt expo(ModInt a, int b) {
        if (!b) {
            return 1;
        }
        ModInt tmp = expo(a, b >> 1);
        if (b & 1) {
            return tmp * tmp * a;
        }
        return tmp * tmp;
    }
    ModInt &operator/=(ModInt that) { return (*this) *= expo(that, MOD - 2); }

    ModInt operator+(ModInt that) const { return ModInt(*this) += that; }
    ModInt operator-(ModInt that) const { return ModInt(*this) -= that; }
    ModInt operator*(ModInt that) const { return ModInt(*this) *= that; }
    ModInt operator/(ModInt that) const { return ModInt(*this) /= that; }
    ModInt operator^(int that) { return expo(ModInt(*this), that); } // BE CAREFUL
    bool operator<(ModInt that) const { return x < that.x; }
    friend ostream& operator<<(ostream &os, ModInt a) { os << a.x; return os; }
};
typedef ModInt<mod> mint;

int a[nax], pre[nax];
mint pw[nax];
Fenwick_tree fen;
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("file.in", "r", stdin);
    freopen("file.out", "w", stdout);
    pw[0] = 1;
    for (int i = 1; i < nax; ++i) {
        pw[i] = mint(2) * pw[i - 1];
    }
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            pre[i] = a[i] + pre[i - 1];
        }
        vector<int> value = {-INF};
        for (int i = 1; i <= n; ++i) {
            value.push_back(pre[i]);
            if (pre[i] < 0) {
                value.push_back(2 * pre[i] - 1);
            }
        }
        sort(all(value));
        value.resize(unique(all(value)) - value.begin());
        int mx = 0, sum = 0;
        for (int i = 1; i <= n; ++i) {
            sum += a[i];
            mx += a[i];
            maximize(mx, abs(sum));
        }
        int d = 0;
        for (int i = 1; i <= n; ++i) {
            d += (pre[i] >= 0);
        }
        mint ans = 0;
        if (pre[n] == mx) {
            ans += pw[d];
        }
        // cout << mx << '\n';
        fen.reseter(sz(value) + 7);
        for (int i = n; i >= 1; --i) {
            d -= (pre[i] >= 0);
            if (pre[i] < 0 && pre[n] - 2 * pre[i] == mx) {
                int z = lower_bound(all(value), 2 * pre[i] - 1) - value.begin();
                ans += pw[d] * pw[fen.get(sz(value)) - fen.get(z)];
            }
            int z = lower_bound(all(value), pre[i]) - value.begin();
            fen.update(z, 1);
        }
        cout << ans << '\n';
    }
    return 0;
}