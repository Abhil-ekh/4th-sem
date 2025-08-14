CREATE DATABASE db1;
USE db1;

CREATE TABLE student(
sid INT(3) PRIMARY KEY,
fname VARCHAR(15),
lname VARCHAR(15),
address VARCHAR(30),
marks INT(3),
phone_no NUMERIC);

CREATE TABLE employee(
eid INT(3) PRIMARY KEY,
ename VARCHAR(30),
eaddress VARCHAR(30),
ephone NUMERIC,
ecity VARCHAR(10),
eage INT(2),
edetails VARCHAR(20),
esalary NUMERIC);

INSERT INTO employee VALUES
(1,'Abilekh','Banasthali',9712345678,'Myagdi',22,'C Developer',95000),
(2,'Alisha','Chettrapati',9728374651,'Kathmandu',23,'C Developer',95000),
(3,'Anshu','Putalisadak',9819283746,'Kathmandu',22,'Java Developer',91738),
(4,'Anush','Banasthali',9812349087,'Kathmandu',21,'C Developer',95000),
(5,'Ashlesha','Swoyambhu',9734567123,'Kathmandu',26,'Java Developer',91738),
(6,'AyushR','Asan',9801928374,'Kathmandu',30,'Java Developer',91738),
(7,'AyushT','Swoyambhu',9720193847,'Kathmandu',27,'C Developer',95000),
(8,'Barsha','Banasthali',9845632190,'Lamjung',33,'Rust Developer',130100),
(9,'Diya','Kalanki',9782301945,'Kathmandu',26,'Rust Developer',130100),
(10,'Gaurav','Kapan',9810234789,'Jhapa',30,'C Developer',95000),
(11,'Hrikesh','Kaldhara',9701283947,'Kabre',28,'C Developer',95000),
(12,'Kamana','Shorakhutte',9710923846,'Chitwan',29,'C Developer',95000),
(13,'Krish','Dhungedhara',9732109845,'Pokhara',21,'Rust Developer',130100),
(14,'Krishma','Jarangkhu',9823456710,'Kathmandu',29,'Rust Developer',130100),
(15,'Manila','Shivapuri',9803452198,'Syangja',29,'Java Developer',91738),
(16,'Shreesha','Shorakhutte',9723845610,'Kathmandu',20,'Rust Developer',130100),
(17,'Sudip','Shorakhutte',9709234816,'Gorkha',23,'Rust Developer',130100),
(18,'Sangam','Manamaiju',9819023471,'Bhaktapur',22,'Rust Developer',130100),
(19,'Upendra','Shivapuri',9709234816,'Latitpur',25,'Java Developer',91738);

SELECT * FROM employee

SELECT ename FROM employee WHERE ename LIKE 's%';

SELECT *FROM employee WHERE ecity='Kathmandu';

SELECT * FROM employee WHERE ephone LIKE '97%';



