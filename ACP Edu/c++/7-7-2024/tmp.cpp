#include <bits/stdc++.h>

using namespace std;

int n, t;
string s;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    for (int testCase = 1; testCase <= t; testCase++) {
        // Nhập liệu
        cin >> n >> s;

        // kiểm tra điều kiện 1
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
        // kiểm tra điều kiện 2
        bool ok2 = true;
        for (int i = 0; i < s.size() - 1; ++i) {
            if('a' <= s[i] && s[i] <= 'z' && '0' <= s[i + 1] && s[i + 1] <= '9') {
                continue;
            }

            ok2 = false;
        }
        // kiểm tra điều kiện 3

        // kiểm tra điều kiện 4

        // kết luận

    }
}