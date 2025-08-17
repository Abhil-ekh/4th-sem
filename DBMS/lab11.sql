CREATE databas0e lab11;
USE lab11;
CREATE TABLE teacher (
    teacher_id INT PRIMARY KEY,
    teacher_name VARCHAR(100),
    department VARCHAR(50),
    salary DECIMAL(10, 2),
    years_of_experience INT
);
INSERT INTO teacher (teacher_id, teacher_name, department, salary, years_of_experience) VALUES
(1, 'Alice Smith', 'Math', 50000, 12),
(2, 'Bob Johnson', 'Computer', 60000, 9),
(3, 'Carol Lee', 'Math', 55000, 7),
(4, 'David Kim', 'Computer', 62000, 11),
(5, 'Eva Brown', 'Physics', 52000, 15),
(6, 'Frank White', 'Computer', 58000, 4),
(7, 'Grace Green', 'Math', 49000, 10);
UPDATE teacher
SET salary = salary * 1.30
WHERE department = 'Computer';

UPDATE teacher
SET salary = salary * 1.50
WHERE years_of_experience > 10;

SELECT *
FROM teacher
WHERE department = 'Math'
  AND salary = (SELECT MAX(salary) FROM teacher WHERE department = 'Math');


SELECT *
FROM teacher
WHERE department = 'Math'
  AND salary = (SELECT MIN(salary) FROM teacher WHERE department = 'Math');


SELECT 
    teacher_id AS ID,
    teacher_name AS NAME,
    department AS Dept,
    salary AS Salary,
    years_of_experience AS Experience
FROM 
    teacher;
