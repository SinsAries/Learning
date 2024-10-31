-- Lấy tên và tuổi từ bảng 'students'
SELECT name, age FROM students;

-- Lọc các học sinh có tuổi lớn hơn 18
SELECT name FROM students WHERE age > 18;

-- Kết hợp hai bảng 'students' và 'courses' để lấy tên học sinh và tên khóa học
SELECT s.name, c.course_name 
FROM students s 
JOIN courses c ON s.course_id = c.id;

-- Nhóm học sinh theo tuổi và đếm số lượng học sinh mỗi nhóm tuổi
SELECT age, COUNT(*) 
FROM students 
GROUP BY age;

-- Sắp xếp kết quả theo tuổi, từ nhỏ đến lớn
SELECT name FROM students 
ORDER BY age ASC;

-- Giới hạn kết quả chỉ hiển thị 5 học sinh đầu tiên
SELECT name FROM students 
LIMIT 5;

-- Lấy danh sách các độ tuổi khác nhau (không trùng lặp)
SELECT DISTINCT age FROM students;
