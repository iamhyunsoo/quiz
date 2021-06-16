/*
Id   | Salary
-------------
1    |  100 |
2    |  200 |
3    |  300 |
-------------
*/

CREATE FUNCTION getNthHighestSalary (N INT) RETURNS INT
BEGIN
DECLARE M INT DEFAULT N-1;
RETURN (
    SELECT DISTINCT Salary FROM Employee ORDER BY Salary DESC LIMIT M, 1
);
END