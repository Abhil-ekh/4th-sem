CREATE DATABASE lab14;
USE lab14;

CREATE TABLE Students (
    student_id INT PRIMARY KEY,
    NAME VARCHAR(100)
);

CREATE TABLE Enrollments (
    enrollment_id INT PRIMARY KEY,
    student_id INT,
    course_name VARCHAR(100)
);

CREATE TABLE Scores (
    student_id INT,
    marks INT
);

INSERT INTO Students (student_id, NAME) VALUES
(1, 'Jay'),
(2, 'Tyson'),
(3, 'Max'),
(4, 'Song');

INSERT INTO Enrollments (enrollment_id, student_id, course_name) VALUES
(101, 1, 'DBMS'),
(102, 3, 'CN');

INSERT INTO Scores (student_id, marks) VALUES
(1, 76),
(2, 88),
(3, 91),
(4, 67),
(5, 80),
(6, 79),
(7, 94),
(8, 87),
(9, 73),
(10, 90),
(11, 86),
(12, 81),
(13, 77),
(14, 69),
(15, 83);

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
