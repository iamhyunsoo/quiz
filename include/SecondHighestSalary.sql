
/*
Id   | Salary
-------------
1    |  100 |
2    |  200 |
3    |  300 |
-------------
*/

SELECT IFNULL(
    (SELECT DISTINCT Salary FROM Employee ORDER BY Salary DESC LIMIT 1, 1), NULL
) AS SecondHighestSalary