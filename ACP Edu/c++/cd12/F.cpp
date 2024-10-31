#include<bits/stdc++.h>

using namespace std;

string s;

int main() {
    cin >> s;
    for (int i = 0; i < s.size(); ++i) if(s[i] >= '0' && s[i] <= '9') {
        int num = 0;
        int j = i;
        num = s[i] - '0';
        while(j + 1 < s.size() && '0' <= s[j + 1] && s[j + 1] <= '9') {
            j++;
            num = num * 10 + s[j] - '0';
        }
        for (int k = 0; k < num; ++k) {
            cout << s[j + 1];
        }
        i = j + 1;
    } else
        cout << s[i];
}