CREATE DATABASE db3;
USE db3;

CREATE TABLE student(
sid INT(3),
sname VARCHAR(20),
smarks INT(3),
sgrade NUMERIC);

INSERT INTO student VALUES
(1,'Robot',72,7),
(2,'Richard',62,10),
(3,'Bob',92,12),
(4,'Tom',55,11),
(5,'Cameron',60,9),
(6,'Lily',59,12),
(7,'Sera',63,8);

SELECT * FROM student;
ALTER TABLE student ADD saddress VARCHAR (20);
ALTER TABLE student DROP COLUMN saddress;
ALTER TABLE student MODIFY COLUMN sgrade INT(2);
SELECT *FROM student WHERE sgrade=12 AND smarks>90;