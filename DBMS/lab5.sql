CREATE DATABASE db5;
USE db5;

CREATE TABLE employee(
id INT(3),
fname VARCHAR(30),
address VARCHAR(30),
salary NUMERIC);

INSERT INTO employee VALUES
(1,'Kapil','Kanchanpur',60000),
(2,'Rose','Myagdi',56000),
(3,'Kamal','Mustang',70000),
(4,'Salina','Jhapa',30000),
(5,'Prashna','Kantapur',87000),
(6,'Jose','Solukhumbu',67000),
(7,'Sahara','Kantipur',77000),
(8,'Pascle','Lalitpur',30000);

SELECT * FROM employee;

SELECT * FROM employee
WHERE fname LIKE 'p%';

SELECT * FROM employee
WHERE fname LIKE '%e';

SELECT * FROM employee
WHERE fname LIKE 'k%l';

SELECT * FROM employee
WHERE address LIKE '%pur%';

SELECT * FROM employee
WHERE fname LIKE 's%a' AND address LIKE 'Kantipur';

DROP TABLE employee;

