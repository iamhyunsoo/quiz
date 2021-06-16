/*
Employee
+----+-------+--------+--------------+
| Id | Name  | Salary | DepartmentId |
+----+-------+--------+--------------+
| 1  | Joe   | 70000  | 1            |
| 2  | Jim   | 90000  | 1            |
| 3  | Henry | 80000  | 2            |
| 4  | Sam   | 60000  | 2            |
| 5  | Max   | 90000  | 1            |
+----+-------+--------+--------------+

Department
+----+----------+
| Id | Name     |
+----+----------+
| 1  | IT       |
| 2  | Sales    |
+----+----------+

Result
+------------+----------+--------+
| Department | Employee | Salary |
+------------+----------+--------+
| IT         | Max      | 90000  |
| IT         | Jim      | 90000  |
| Sales      | Henry    | 80000  |
+------------+----------+--------+
*/

SELECT d.Name AS `Department`, e.Name AS `Employee`, e.Salary FROM Employee AS e
JOIN Department AS d 
ON e.DepartmentId = d.Id
JOIN (
    SELECT DepartmentId, MAX(Salary) AS `Salary` FROM Employee GROUP BY DepartmentId
) AS agg
ON e.Salary = agg.Salary AND e.DepartmentId = agg.DepartmentId;