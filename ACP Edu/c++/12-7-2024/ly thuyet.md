# Độ phức tạp thời gian

## Giới thiệu
- 1 giây có thể chạy khoảng $10^8$ phép tính, chính xác hơn thì là gần $5 * 10^8$ phép tính
## Tính toán độ phức tạp thời gian
- Thường thì đầu vào sẽ có độ lớn là n
- Độ phức tạp thời gian sẽ là số phép tính để chạy thuật toán trong tính huống xấu nhất
- Độ phức tạp thời gian thường được kí hiệu bằng $O(f(n))$
- Những code sau sẽ có độ phức tạp là $O(1)$, hay chính xác hơn thường gọi là độ phức tạp hằng số 
```cpp
    int a = 10;
    int b = 7;
    int c = a + b + 10;
    cin >> a;
    cout << a;
```
- Độ phức tạp của vòng lặp thì là số lần lặp lại mà vòng lặp lặp, ví dụ, độ phức tạp của những đoạn code sau là $O(n)$ (quy ước những đoạn code bên trong vòng lặp sẽ có độ phức tạp là $O(n)$)
```cpp
    for (int i = 1; i <= n; i++) {
        // Code có độ phức tạp O(1)
    }
```
```cpp
    int i = 0;
    while(i < n) {
        // Code có độ phức tạp O(1)
        i++;
    }
```
```cpp
    for (int i = 1; i <= 5 * n + 17; i++) {
        // Code có độ phức tạp O(1)
    }
```
```cpp
    for (int i = 1; i <= n + 231232; i++) {
        // Code có độ phức tạp O(1)
    }
```
- Chúng ta có thể tính độ phức tạp của những vòng lặp lồng vào nhau bằng cách nhân độ phức tạp của từng vòng lặp với nhau. Ví dụ sau đây có độ phức tạp là $O(nm)$, vì vòng lặp bên ngoài chạy n lần và vòng lặp bên trong chạy $m$ lần
```cpp
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            // Code có độ phức tạp O(1)
        }
    }
```
- Độ phức tạp trong ví dụ sau là $O(n^2)$
```cpp
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            // Code có độ phức tạp O(1)
        }
    }
```
- Độ phức tạp trong ví dụ sau là $O(n^2 + m)$
```cpp
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            // Code có độ phức tạp O(1)
        }
    }

    for (int i = 1; i <= m; i++) {
        // Code có độ phức tạp O(1)
    }
```

## Các độ phức tạp thời gian thường gặp
|$n$           |Độ phức tạp có thể dùng                       |
|--------------|----------------------------------------------|
|$n \le 10$    |$O(n!), O(n^7), O(n^6)$                       |
|$n \le 20$    |$O(2^n * n), O(n^5)$                          |
|$n \le 80$    |$O(n^4)$                                      |
|$n \le 400$   |$O(n^3)$                                      |
|$n \le 7500$  |$O(n^2)$                                      |
|$n \le 7*10^4$|$O(n*{\sqrt n})$                              |
|$n \le 5*10^5$|$O(n*\log(n))$                                |
|$n \le 5*10^6$|$O(n)$                                        |
|$n \le 10^8$  |$O({\log^2(n)}, O(\log(n)), O(\sqrt n), O(1))$|
