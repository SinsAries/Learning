#include<bits/stdc++.h>

using namespace std;

string sB, sE;

bool ok(int len) {
    int l = sB.size() - len;
    int r = 0;
    while(l < sB.size()) {
        if(sB[l] != sE[r]) 
            return false;
        l++;
        r++;
    }
    return true;
}

int main() {
    cin >> sB >> sE;
    for (int len = sB.size(); len >= 0; --len) {
        if(ok(len)) {
            cout << sB.length() + sE.length() - len;
            return 0;
        }
    }
}