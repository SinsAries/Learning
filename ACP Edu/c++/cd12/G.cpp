#include<bits/stdc++.h>

using namespace std;

string a, b;

int main() {
    cin >> a >> b;
    int l = 0, r = 0;
    while(l < a.size() && r < b.size()) {
        if(a[l] == b[r])
            r++;
        l++;
    }
    if(r == b.size())
        cout << "YES";
    else
        cout << "NO";
}