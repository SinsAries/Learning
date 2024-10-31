-- INNER JOIN: Chỉ lấy những hàng mà có dữ liệu khớp ở cả hai bảng
SELECT s.name, c.course_name 
FROM students s 
INNER JOIN courses c ON s.course_id = c.id;

-- LEFT JOIN: Lấy tất cả học sinh, kể cả khi không có khóa học
SELECT s.name, c.course_name 
FROM students s 
LEFT JOIN courses c ON s.course_id = c.id;

-- RIGHT JOIN: Lấy tất cả khóa học, kể cả khi không có học sinh đăng ký
SELECT s.name, c.course_name 
FROM students s 
RIGHT JOIN courses c ON s.course_id = c.id;
