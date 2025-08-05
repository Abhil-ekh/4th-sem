CREATE DATABASE db8;
USE db8;

CREATE TABLE department (
    department_id INT PRIMARY KEY,
    department_name VARCHAR(50)
);

CREATE TABLE employee (
    emp_id INT PRIMARY KEY,
    NAME VARCHAR(50),
    department_id INT,
    manager_id INT
);

INSERT INTO department VALUES
(10, 'Devloper'),
(20, 'Designer'),
(30, 'DevOps');

INSERT INTO employee  VALUES
(1, 'Abilekh', 10, NULL),
(2, 'Alisha', 20, 1),
(3, 'Anshu', 10, 1),
(4, 'Anush', 30, 2);


SELECT e.name AS employee_name, d.department_name
FROM employee e
CROSS JOIN department d;


SELECT e.name AS employee_name, d.department_name
FROM employee e
JOIN department d ON e.department_id = d.department_id;


SELECT e.name AS employee_name, m.name AS manager_name
FROM employee e
JOIN employee m ON e.manager_id = m.emp_id;
