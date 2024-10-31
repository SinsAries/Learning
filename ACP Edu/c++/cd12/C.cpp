#include<bits/stdc++.h>

using namespace std;

string s, result;

int main() {
    // s = "0123456789";
    // for (int i = 0; i < s.size(); ++i) {
    //     cout << s[i] - '0' << '\n';
    // }
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        int num;
        if(s[i] == '9') {
            num = (s[i] - '0') * 10 + s[i + 1] - '0';
            i += 1;
        } else if(s[i] == '1') {
            num = (s[i] - '0') * 100 + (s[i + 1] - '0') * 10 + s[i + 2] - '0';
            i += 2;
        }
        result.push_back(char(num));
    }
    cout << result;
}