# Giới thiệu về mảng tổng tiền tố (Prefix sums)
- Bài toán cơ sở:
  - Cho mảng A có N phần tử là các số nguyên $(N <= 500000)$
  - Các phần tử của mảng A được đánh số từ 1 tới N
  - Có $Q$ truy vấn $(Q <= 50000)$
  - Mỗi truy vấn cho 2 số $L, R (1 \le L \le R \le N)$, yêu cầu tính tổng các phần tử của mảng $A$ có chỉ số từ L đến R - 1
- Bài toán
  - Dòng đầu tiên chứa 2 số N và Q, lần lượt là số phần tử của mảng A và số lượng truy vấn
  - Dòng thứ hai là N số nguyên A[1], A[2], ... A[N]
  - Q dòng tiếp theo, mỗi dòng chứa hai số l, r là truy vấn
  - Yêu cầu: với mỗi truy vấn, in ra tổng các số A[l], A[l + 1], ... A[r], kết quả của mỗi truy vấn in trên 1 dòng
- Thuật toán ngây thơ:
  - Với mỗi truy vấn, ta duyệt từ L đến R để tính tổng và trả lời truy vấn
- Code
  ```cpp
  #include <bits/stdc++.h>

  using namespace std;

  int N, Q, A[500011];

  int main() {
      cin >> N >> Q;
      for (int i = 0; i < N; ++i)
          cin >> A[i];
      for (int query = 0; query < Q; ++query) {
          int l, r;
          cin >> l >> r;
          int res = 0;
          for (int i = l; i < r; ++i) {
              res += A[i];
          }
          cout << res << '\n';
      }
  }
  ```
- Thuật toán đúng:
  - Ví dụ mảng A có 6 phần tử lần lượt có giá trị là 1, 6, 4, 2, 5, 3
  - Gọi mảng $prefix$ có $N$ phần tử, với $prefix[i] = A[1] + A[2] + ... + A[i]$
<center>

| Chỉ số $i$           | 0   | 1   | 2   | 3   | 4   | 5   | 6   |
| -------------------- | --- | --- | --- | --- | --- | --- | --- |
| $\texttt{prefix}[i]$ | 0   | 1   | 7   | 11  | 13  | 18  | 21  |

</center>
- Cách xây dựng mảng $prefix$:
  - Khởi tạo $prefix[0] = 0$