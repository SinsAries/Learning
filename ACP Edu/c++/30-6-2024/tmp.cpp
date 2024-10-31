#include <bits/stdc++.h>
using namespace std;

string cs(const string& S) {
    string c = "";
    int n = S.length();
    
    int count = 1;
    for (int i = 1; i < n; ++i) {
        if (S[i] == S[i - 1]) {
            ++count;
        } else {
            c += to_string(count) + S[i - 1];
            count = 1;
        }
    }
    c += to_string(count) + S[n - 1];
    
    return c;
}

int main() {
    string S;
    cin >> S;
    
    string result = cs(S);
    cout << result << endl;
}