CREATE DATABASE lab14;
USE lab14;
CREATE TABLE Students (
    student_id INT PRIMARY KEY,
    NAME VARCHAR(100)
);

-- Create Enrollments table
CREATE TABLE Enrollments (
    enrollment_id INT PRIMARY KEY,
    student_id INT,
    course_name VARCHAR(100)
);
-- Create Scores table
CREATE TABLE Scores (
    student_id INT,
    marks INT
);

-- Insert into Students
INSERT INTO Students (student_id, NAME) VALUES
(1, 'Alice'),
(2, 'Bob'),
(3, 'Charlie'),
(4, 'David');

-- Insert into Enrollments
INSERT INTO Enrollments (enrollment_id, student_id, course_name) VALUES
(101, 1, 'Math'),
(102, 3, 'Science');

-- Insert into Scores
INSERT INTO Scores (student_id, marks) VALUES
(1, 90),
(2, 85),
(3, 95),
(4, 70),
(5, 88),
(6, 85),
(7, 91),
(8, 92),
(9, 75),
(10, 89),
(11, 93),
(12, 84),
(13, 82),
(14, 77),
(15, 78);

SELECT s.*
FROM Students s
WHERE NOT EXISTS (
    SELECT 1
    FROM Enrollments e
    WHERE e.student_id = s.student_id
);
SELECT student_id, marks
FROM Scores s1
WHERE (
    SELECT COUNT(DISTINCT marks)
    FROM Scores s2
    WHERE s2.marks > s1.marks
) = 9;
