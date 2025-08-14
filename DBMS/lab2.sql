CREATE DATABASE db2;
USE db2;

CREATE TABLE employee(
Empid INT(3) PRIMARY KEY,
Empname VARCHAR(30),
Empaddress VARCHAR(30),
Empphone NUMERIC,
Emppost VARCHAR(20),
Empsalary NUMERIC
);

INSERT INTO employee VALUES
(1,'Abilekh','Banasthali',9712345678,'C Developer',95000),
(2,'Alisha','Chettrapati',9728374651,'C Developer',95000),
(3,'Anshu','Putalisadak',9819283746,'Rust Developer',20000),
(4,'Anush','Dharan',9812349087,'Manager',100000),
(5,'Ashlesha','Swoyambhu',9734567123,'Java Developer',91738),
(6,'AyushR','Asan',9801928374,'Java Developer',91738),
(7,'AyushT','Swoyambhu',9720193847,'C Developer',95000),
(8,'Barsha','Dharan',9845632190,'Rust Developer',20000),
(9,'Diya','Kalanki',9782301945,'Manager',100000),
(10,'Gaurav','Kapan',9810234789,'C Developer',95000);

SELECT * FROM employee WHERE Empsalary>30000;

SELECT * FROM employee WHERE Empsalary<25000 AND Empaddress='Dharan';

SELECT * FROM employee WHERE Empid IN(5,6,7,8);

SELECT * FROM employee WHERE Empid NOT IN(5,6,7,8);

SELECT Empid,Empname,Empsalary,Emppost FROM employee WHERE Emppost='Manager';

