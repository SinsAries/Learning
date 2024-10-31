#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    int lights[n + 1] = {0};
    for (int t = 1; t <= b; ++t) {
        for (int i = a; i <= n; i += a) {
            lights[i] = !lights[i];
        }
        a++;
    }

    // Đếm số bóng đèn đang bật
    int count = 0;
    for (int i = 1; i <= n; ++i) {
        if (lights[i] == 1) {
            count++;
        }
    }
    cout << count << endl;
    return 0;
}