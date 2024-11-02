## GCD & LCM

### GCD

Ước số chung lớn nhất (GCD) của hai số nguyên a và b là số nguyên lớn nhất chia hết cho cả a và b. Để tìm GCD của hai số nguyên không âm, ta sử dụng Thuật toán Euclid, như sau:

gcd(a, b) = a nếu b = 0 và gcd(b, a mod b) nếu b ≠ 0

Thuật toán này có thể được triển khai bằng một hàm đệ quy như sau:  
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

Đối với C++14, bạn có thể dùng hàm tích hợp __gcd(a,b).

Trong C++17, có sẵn std::gcd và std::lcm trong thư viện <numeric>, nên nếu bạn đang dùng phiên bản này, không cần phải tự viết hàm GCD và LCM.

Hàm này chạy với thời gian O(log(ab)) vì nếu a ≤ b thì b mod a < b / 2.

Trường hợp xấu nhất của thuật toán Euclid là khi a và b là hai số Fibonacci liên tiếp F(n) và F(n + 1). Trong trường hợp này, thuật toán sẽ tính:  
gcd(F(n), F(n + 1)) = gcd(F(n - 1), F(n)) = ... = gcd(0, F(1)).  
Điều này yêu cầu (n+1) lượt gọi hàm, tỷ lệ với log(F(n) * F(n+1)).

### LCM

Bội số chung nhỏ nhất (LCM) của hai số nguyên a và b là số nguyên nhỏ nhất chia hết cho cả a và b. Ta có thể tính LCM bằng cách sử dụng GCD với công thức:

lcm(a, b) = (a * b) / gcd(a, b)

Chú ý: Việc mã hóa hàm LCM dưới dạng a * b / gcd(a, b) có thể gây ra tràn số nguyên nếu giá trị của a * b lớn hơn kích thước tối đa của kiểu dữ liệu của a * b (ví dụ: kích thước tối đa của int trong C++ và Java là khoảng 2 tỷ). Chia a cho gcd(a, b) trước, rồi nhân với b sẽ tránh được tràn số nguyên nếu kết quả nằm trong phạm vi của int.

Ngoài ra, hai hàm này có tính kết hợp, nghĩa là nếu muốn tính GCD hoặc LCM của nhiều hơn hai phần tử, ta có thể thực hiện từng hai một, theo bất kỳ thứ tự nào. Ví dụ:

gcd(a1, a2, a3, a4) = gcd(a1, gcd(a2, gcd(a3, a4)))
