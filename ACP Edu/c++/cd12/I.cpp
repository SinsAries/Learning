#include<bits/stdc++.h>

using namespace std;

string s;

bool is_A_greater_than_B(string A, string B) {
    // cout << A << ' ' << B << '\n';
    if(A[0] == '-' && B[0] == '-') {
        string newA = "";
        string newB = "";

        int i = 1;
        while(i + 1 < A.size() && A[i] == '0' && A[i + 1] == '0')
            i++;
        if(i + 1 < A.size() && A[i] == '0' && A[i + 1] != '0')
            i++;
        while(i < A.size()) {
            newA.push_back(A[i]);
            i++;
        }

        i = 1;
        while(i + 1 < B.size() && B[i] == '0' && B[i + 1] == '0')
            i++;
        if(i + 1 < B.size() && B[i] == '0' && B[i + 1] != '0')
            i++;
        while(i < B.size()) {
            newB.push_back(B[i]);
            i++;
        }

        if(newA.size() > newB.size()) {
            return false;
        }
        if(newA.size() < newB.size()) {
            return true;
        }
        for (int i = 0; i < newA.size(); ++i) 
            if(newA[i] > newB[i]) {
                return false;
            }
        return true;
    }
    if(A[0] == '-' && B[0] != '-') {
        return false;
    }
    if(A[0] != '-' && B[0] == '-') {
        return true;
    }
    if(A[0] != '-' && B[0] != '-') {
        string newA = "";
        string newB = "";

        int i = 0;
        while(i + 1 < A.size() && A[i] == '0' && A[i + 1] == '0')
            i++;
        if(i + 1 < A.size() && A[i] == '0' && A[i + 1] != '0')
            i++;
        while(i < A.size()) {
            newA.push_back(A[i]);
            i++;
        }

        i = 0;
        while(i + 1 < B.size() && B[i] == '0' && B[i + 1] == '0')
            i++;
        if(i + 1 < B.size() && B[i] == '0' && B[i + 1] != '0')
            i++;
        while(i < B.size()) {
            newB.push_back(B[i]);
            i++;
        }

        if(newA.size() > newB.size()) {
            return true;
        }
        if(newA.size() < newB.size()) {
            return false;
        }
        for (int i = 0; i < newA.size(); ++i) 
            if(newA[i] > newB[i]) {
                return true;
            }
        return false;
    }
}

int main() {
    getline(cin, s);
    // cout << s << '\n';
    string res = "?";
    for (int i = 0; i < s.size(); ++i) {
        if((s[i] >= '0' && s[i] <= '9') || (s[i] == '-')) {
            // cout << s[i] << ' ' << i + 1 << '\n';
            string curNum = "";
            curNum.push_back(s[i]);
            int j = i;
            while(j + 1 < s.size() && '0' <= s[j + 1] && s[j + 1] <= '9') {
                j++;
                curNum.push_back(s[j]);
                // cout << curNum << '\n';
            }
            
            // cout << curNum << '\n';
            if((curNum[0] == '-' && curNum.size() > 1) || curNum[0] != '-')
                if(res == "?" || is_A_greater_than_B(curNum, res))
                    res = curNum;
            // cout << i << ' ' << j << '\n';
            i = j;
        }
    }
    // cout << res << '\n';

    string newRes = "";
    int i = 0;
    if(res[0] == '-') {
        newRes.push_back('-');
        i = 1;
    }
    while(i + 1 < res.size() && res[i] == '0' && res[i + 1] == '0')
        i++;
    if(i + 1 < res.size() && res[i] == '0' && res[i + 1] != '0')
        i++;
    while(i < res.size()) {
        newRes.push_back(res[i]);
        i++;
    }
    if(newRes == "-0")
        newRes = "0";
    cout << newRes;
}