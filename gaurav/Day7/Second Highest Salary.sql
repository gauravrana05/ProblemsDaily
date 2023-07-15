

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
  rowNum = 2 and salary <> (select max(salary) from Employee);


#better appraoch
#select max(salary) AS SecondHighestSalary from employee 
where salary not in (select max(salary) from employee)