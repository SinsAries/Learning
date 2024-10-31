-- Tạo bảng 'customers' và 'orders' với khóa ngoại (Foreign Key) và hành vi khi xóa, cập nhật
CREATE TABLE customers (
    id INT PRIMARY KEY,
    name VARCHAR(100)
);

CREATE TABLE orders (
    order_id INT PRIMARY KEY,
    customer_id INT,
    FOREIGN KEY (customer_id) REFERENCES customers(id) ON DELETE CASCADE ON UPDATE CASCADE
);

-- Thêm dữ liệu mẫu
INSERT INTO customers (id, name) VALUES (1, 'John Doe'), (2, 'Jane Smith');
INSERT INTO orders (order_id, customer_id) VALUES (1, 1), (2, 2);

-- Xóa một khách hàng, các đơn hàng liên quan cũng sẽ bị xóa tự động
DELETE FROM customers WHERE id = 1;

-- Cập nhật khóa chính của khách hàng, đơn hàng cũng sẽ được cập nhật theo
UPDATE customers SET id = 3 WHERE id = 2;
