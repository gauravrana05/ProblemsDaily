CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      # Write your MySQL query statement below.

SELECT
  MAX(salary) AS SecondHighestSalary
FROM
  (
    SELECT
      salary,
      ROW_NUMBER() OVER (ORDER BY salary DESC) AS rowNum
    FROM
      Employee
      group by salary
  ) temp
WHERE
  rowNum = N


      
  );
END