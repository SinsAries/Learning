#include<bits/stdc++.h>

using namespace std;

string s, result;
vector<char> tmp;

int main() {
    cin >> s;
    for (int i = 0; i < s.size(); ++i) if('0' <= s[i] && s[i] <= '9') 
        tmp.push_back(s[i]);
    sort(tmp.begin(), tmp.end());
    int index = 0;
    for (int i = 0; i < s.size(); ++i) if('0' <= s[i] && s[i] <= '9') {
        cout << tmp[index];
        index++;
    } else 
        cout << s[i];
}