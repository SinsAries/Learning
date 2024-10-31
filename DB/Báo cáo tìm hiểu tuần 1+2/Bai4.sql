-- Tạo bảng 'students' với khóa chính (Primary Key)
CREATE TABLE students (
    id INT PRIMARY KEY,
    name VARCHAR(100),
    age INT
);

-- Tạo bảng 'courses' với khóa chính (Primary Key)
CREATE TABLE courses (
    id INT PRIMARY KEY,
    course_name VARCHAR(100)
);

-- Tạo bảng 'students' có khóa ngoại (Foreign Key) từ bảng 'courses'
CREATE TABLE students (
    id INT PRIMARY KEY,
    course_id INT,
    FOREIGN KEY (course_id) REFERENCES courses(id)
);

-- Tạo chỉ mục (Index) để tăng tốc độ truy vấn dựa trên cột 'age'
CREATE INDEX idx_age ON students(age);

-- Tạo bảng 'users' với cột 'email' có ràng buộc giá trị duy nhất (Unique)
CREATE TABLE users (
    id INT PRIMARY KEY,
    email VARCHAR(100) UNIQUE
);
