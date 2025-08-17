CREATE DATABASE lab9;
USE lab9;
CREATE TABLE student(
eid INT(3),
ename VARCHAR(20),
eaddress VARCHAR(20),
ephone NUMERIC(10),
eage INT(3)
);
INSERT INTO student VALUES 
(1, '  Anshu Hada  ', '  Dhobidhara-30  ', 9812345601, 22),
(2, ' Barsha Pandey ', ' Dillibazar-5  ', 9812345602, 25),
(3, ' Gaurav Thapa  ', '  Baneshwor-2', 9812345603, 30),
(4, '  Manila Aryal', 'Kalanki-1  ', 9812345604, 28),
(5, 'Kamana Shrestha  ', '  Putalisadak-4  ', 9812345605, 22),
(6, ' Shrisha Tuladhar ', ' Kirtipur-6 ', 9812345606, 24),
(7, '  Krisma Maharjan', 'Gausala-7 ', 9812345607, 31),
(8, ' Sudip Khadka ', '  Maitidevi-2', 9812345609, 29),
(9, 'Ayush Tuladhar  ', 'Balkot-3  ', 9812345609, 26),
(10, ' Sangam Adhikari  ', ' Sankhamul-9 ', 9812345610, 23),
(11, ' Abhilekh Sudebi', ' Gongabu-4 ', 9812345611, 32),
(12, 'Hrikesh Aran ', ' Balaju-10  ', 9812345612, 30),
(13, ' Upendra Panta  ', '  Samakhushi-5', 9812345613, 33),
(14, '  Anush Shrestha', 'New Baneshwor-8 ', 9812345614, 28),
(15, ' Ashlesha Shrestha ', ' Jorpati-3  ', 9812345615, 27);
SELECT *FROM student WHERE ename LIKE '%a%';
SELECT *FROM student WHERE eaddress LIKE '%kathmandu%';
SELECT *FROM student WHERE ephone LIKE '%15';
SELECT eid, SUBSTRING(ename,1,5) AS Name5 FROM student;
SELECT CONCAT(eid, ' ', ename) AS primarykey FROM student;
SELECT eaddress, LENGTH(eaddress) AS Addresslength FROM student;
SELECT ename, UPPER(ename) AS UpperName, LOWER(ename) AS LowerName FROM student;
SELECT 
    TRIM(ename) AS TrimmedName,
    LTRIM(eaddress) AS LeftTrimmed,
    RTRIM(ename) AS RightTrimmed
FROM student;
SELECT
    ename,
    ASCII(SUBSTRING(LTRIM(ename), 1, 1)) AS firstcharASCII
FROM student;
SELECT
    ename,
    eage,
    CHAR(SUBSTRING(LTRIM(age,1,1))) AS FirstChar
FROM student;





