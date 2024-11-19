#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll N;

map<int, int> cnt;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    while(N--) {
        int type, x;
        cin >> type >> x;
        if(type == 1) 
            cnt[x]++;
        if(type == 2)
            cnt[x]--;
        
        int res = 0;
        for (auto p : cnt) {
            if(p.second > 0)
                res = __gcd(res, p.first);
        }   
        if(res == 0)
            cout << "1\n";
        else
            cout << res << '\n';
    }
}