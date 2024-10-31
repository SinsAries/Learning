#include <bits/stdc++.h>
using namespace std;
int n, t;
string s;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    for (int testCase = 1; testCase <= t; testCase++) {
        cin >> n >> s;
        bool ok1 = true;
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if('a' <= c && c <= 'z') {
                continue;
            }
            if('0' <= c && c <= '9') {
                continue;
            }
            ok1 = false;
        }
        bool ok2=true;
        for(int i=0;i<s.size()-1;++i){
            if ('a'<=s[i]&&s[i]<='z'&&'0'<=s[i+1]&&s[i+1]<='9'){
                ok2=false;
            }
        }
        bool ok3=true;
        for(int i=0;i<s.size()-1;++i) if('0'<=s[i]&&s[i]<='9'&&'0'<=s[i+1]&&s[i+1]<='9'){
                if(s[i+1]>=s[i]){
                    continue;
                }
            ok3=false;
        }
        bool ok4=true;
        for(int i=0;i<s.size()-1;++i)if('a'<=s[i]&&s[i]<='z'&&'a'<=s[i+1]&&s[i+1]<='z'){
                if(s[i+1]>=s[i]){
                    continue;
                }
            }
            ok4=false;
        if ((ok1==true)&&(ok2==true)&&(ok3==true)&&(ok4==true)){
            cout<<"YES"<<'\n';
        }
        else cout<<"NO"<<'\n';
        }
}