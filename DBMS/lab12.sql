CREATE DATABASE db12;
USE db12;

CREATE TABLE Employees (
    emp_id INT PRIMARY KEY,
    NAME VARCHAR(100),
    salary INT,
    department VARCHAR(100),
    dob DATE,
    dept_id INT
);

CREATE TABLE Departments (
    dept_id INT PRIMARY KEY,
    dept_name VARCHAR(100)
);


INSERT INTO Employees VALUES
(1, 'Patrick Mendoza', 120000, 'Initiator', '2001-12-05', 1),     
(2, 'Wang Jing Jie', 110000, 'Dualist', '2003-07-27', 3), 
(3, 'Jason Susanto', 105000, 'Controller', '2004-03-25', 2),  
(4, 'Khalish Rusyaidee', 95000, 'Initiator', '1998-10-14', 1),    
(5, 'Spencer Martin', 90000, 'Dualist', '1995-6-27', 3);

INSERT INTO Departments VALUES
(1, 'Initiator'),
(2, 'Controller'),
(3, 'Dualist');

CREATE VIEW EmployeeDetails AS
SELECT emp_id, NAME, salary, department, dob
FROM Employees;

SELECT * FROM EmployeeDetails;

SELECT * FROM EmployeeDetails
WHERE salary > 100000;

SELECT * FROM EmployeeDetails
WHERE NAME LIKE 'W%';

SELECT * FROM EmployeeDetails
WHERE dob BETWEEN '1996-01-01' AND '2002-01-01';

SELECT * FROM EmployeeDetails
WHERE department IN ('Initiator', 'Controller');

CREATE VIEW EmployeeWithDept AS
SELECT 
    E.emp_id,
    E.name,
    E.salary,
    D.dept_name
FROM 
    Employees E
JOIN 
    Departments D ON E.dept_id = D.dept_id;
    
SELECT * FROM EmployeeWithDept;
DROP DATABASE db12