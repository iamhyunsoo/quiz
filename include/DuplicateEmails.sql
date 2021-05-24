/*
Table: Person
+----+---------+
| Id | Email   |
+----+---------+
| 1  | a@b.com |
| 2  | c@d.com |
| 3  | a@b.com |
+----+---------+

Answer be like
+---------+
| Email   |
+---------+
| a@b.com |
+---------+
*/

SELECT Email FROM Person GROUP BY Email HAVING COUNT(Email) > 1;