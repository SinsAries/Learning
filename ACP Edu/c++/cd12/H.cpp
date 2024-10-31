#include<bits/stdc++.h>

using namespace std;

string s;
int res = 0;

int main() {
    cin >> s;
    for (int i = 1; i < s.size(); i += 2) {
        int j = i;
        int num = s[i - 1] - '0';
        while(j + 2 < s.size() && s[j + 2] == s[i]) {
            j += 2;
            num += s[j - 1] - '0';
        }
        res = max(res, num);
        i = j;
    }
    cout << res;
}