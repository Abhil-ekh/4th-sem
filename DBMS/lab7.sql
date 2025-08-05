CREATE DATABASE db7;
USE db7;

CREATE TABLE student (
    Sid INT(3) PRIMARY KEY,
    Sname VARCHAR(30),
    Saddress VARCHAR(50),
    Sage INT(3),
    Sclass INT(2),
    Smarks NUMERIC(5,2) 
);

INSERT INTO student VALUES
 (1, 'Anshu', 'Putalisadak', 14, 12, 99),
 (2, 'Anush', 'Balaju', 16, 12, 56),
 (3, 'Abilekh', 'Banasthali', 15, 12, 96),
 (4, 'Diya', 'Kalanki', 17, 12, 14),
 (5, 'Barsha', 'Banasthali', 16, 12, 45),
 (6, 'Alisha', 'Chettrapati', 18, 12, 34),
 (7, 'Gaurav', 'Kapan', 18, 12, 12),
 (8, 'AyushT', 'Swoyambhu', 16, 12, 19),
 (9, 'AyushR', 'Asan', 17, 12, 21),
 (10, 'Ashlesha', 'Swoyambhu', 19, 12, 76);
 
CREATE TABLE employee(
	Eid INT(3) PRIMARY KEY,
	Ename VARCHAR(30),
	Eaddress VARCHAR(30),
	Ephone NUMERIC,
	Epost VARCHAR(20),
	Esalary NUMERIC
);
INSERT INTO EMPLOYEE VALUES 
(1,'Abilekh','Banasthali',9712345678,'C Developer',95000),
(2,'Alisha','Chettrapati',9728374651,'C Developer',95000),
(3,'Anshu','Putalisadak',9819283746,'Rust Developer',20000),
(4,'Anush','Banasthali',9812349087,'Manager',100000),
(5,'Ashlesha','Swoyambhu',9734567123,'Java Developer',91738),
(6,'AyushR','Asan',9801928374,'Java Developer',91738),
(7,'AyushT','Swoyambhu',9720193847,'C Developer',95000),
(8,'Barsha','Banasthali',9845632190,'Rust Developer',20000),
(9,'Diya','Kalanki',9782301945,'Manager',100000),
(10,'Gaurav','Kapan',9810234789,'C Developer',95000);

SELECT s.Sname, s.Sage, e.Eaddress, e.Ephone, e.Epost
FROM student AS s
INNER JOIN EMPLOYEE AS e ON s.Sname = e.Ename;

SELECT s.Sname, s.Sage, s.Smarks, e.Ephone, e.Esalary
FROM student AS s
LEFT OUTER JOIN EMPLOYEE AS e ON s.Sname = e.Ename;

SELECT s.Sname, s.Sage, s.Smarks, e.Ephone
FROM employee AS e
RIGHT OUTER JOIN Student AS s ON s.Sname = e.Ename;




