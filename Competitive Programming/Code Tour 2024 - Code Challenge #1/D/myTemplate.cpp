#include <iostream>
#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define fi first
#define se second
using namespace std;

typedef pair <int, int> ii;
int const N = 5e3 + 5;
int n, k, d;
int t[N], a[N], b[N];
ll f[N][N];

void Enter()
{
    cin >> n >> k >> d;
    for (int i = 1; i <= n; i++) cin >> t[i];
    for (int i = 1; i <= k; i++) cin >> a[i];
    for (int i = 1; i <= k; i++) cin >> b[i];
}

void Process()
{
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) f[i][j] = 1e18;

    f[1][1] = a[t[1]];
    for (int i = 2; i <= n; i++){
        for (int j = max(0, i - d + 1); j < i; j++){
            if (t[i] == t[i-1]) f[i][j] = min(f[i][j], f[i-1][j] + b[t[i]]);
            f[i][j] = min(f[i][j], f[i-1][j] + a[t[i]]);
            if (t[i] == t[j]) f[i][i] = min(f[i][i], f[i-1][j+1] + b[t[i]]);
            f[i][i] = min(f[i][i], f[i-1][j+1] + a[t[i]]);
        }
    }
    ll res = 1e18;
    for (int i = 1; i <= n; i++) res = min(res, f[n][i]);
    cout << res << "\n";
}
// f[i][j] la keo dai mot nguoi lam tu j -> i
// f[i][j] = f[i-1][j+1] + b[t[i]]
// f[i][j] = f[i-1][j] + a[t[i]]

int main()
{
    #define task "I"
    if (fopen(task".INP", "r")){
        freopen(task".INP", "r", stdin);
        freopen(task".OUT", "w", stdout);
    }
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--){
        Enter();
        Process();
    }
    return 0;
}
////////////////////////////////////////////////////////////////////////////
//  Nhân quả không nợ chúng ta thức gì, cho nên xin đừng oán giận   ////////
//                                   _
//                                oo0oo
//                               o8888888o
//                               88” . “88
//                               (| 😑 |)
//                               O\  =  /O
//                            ___/'---'\___
//                          .'  \\|     |//  '.
//                         /  \\|||  :  |||//  \
//                        /  ||||| -:- |||||  \
//                        |   | \\\  -  /'| |   |
//                        | \_|  `\`---'//  |_/ |
//                        \  .-\__ `-. -'__/-.  /
//                      ___. .'  /--.--\  . . '___
//                   ."" '<  `.___\_<|>_/___.'  _> \"".
//                  | | :  - \. ;`. _/; .'/  /  .' ; |
//                  \  \ -.   \_\_. _.' _/_/  -' _.' /
//===================`-.`___`-.__\ \___   /__.-'.'.-'===================//
//                                `=--=-'

// Đức Phật nơi đây phù hộ code con chạy không Bugs. Nam mô a di đà Phật.

//
//                      _.-/`)
//                     // / / )
//                  .=// / / / )
//                 //`/ / / / /
//                // /    `  /
//               ||         /
//              ||         /
//               \\       /
//                ))    .'
//               //     /
//