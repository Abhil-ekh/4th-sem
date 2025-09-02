CREATE DATABASE lab13;
USE lab13;
CREATE TABLE Employees (
    emp_id INT PRIMARY KEY,
    NAME VARCHAR(100),
    department VARCHAR(50),
    salary INT
);

CREATE TABLE Departments (
    dept_id INT PRIMARY KEY,
    dept_name VARCHAR(50)
);
INSERT INTO Employees (emp_id, NAME, department, salary) VALUES
(1, 'Jonah Pulice', 'Initiator', 50000),
(2, 'Trent Cairns', 'Initiator', 60000),
(3, 'Jacob Batio', 'Controller', 55000),
(4, 'Nathan Orf', 'Sentinal', 70000),
(5, 'Alexander Mor', 'Duelist', 62000),
(6, 'Peter Beley', 'Coach', 80000),

INSERT INTO Departments (dept_id, dept_name) VALUES
(1, 'Initiator'),
(2, 'Duelist'),
(3, 'Controller'),
(4, 'Sentinal'),
(5, 'Coach'); 

SELECT NAME
FROM Employees
WHERE salary > ALL (
    SELECT salary
    FROM Employees
    WHERE department = 'Initiator'
);
SELECT NAME
FROM Employees
WHERE salary > ANY (
    SELECT salary
    FROM Employees
    WHERE department = 'Initiator'
);
SELECT NAME
FROM Employees
WHERE department IN (
    SELECT department
    FROM Employees
    WHERE NAME = 'Nathan Orf'
);

SELECT dept_name
FROM Departments D
WHERE NOT EXISTS (
    SELECT *
    FROM Employees E
    WHERE E.department = D.dept_name
);
