# Write your MySQL query statement below

select t2.name as Department, t1.name as Employee, salary
from Employee  as t1
join Department as t2
on t2.id = t1.departmentId
where(t1.departmentId, salary) in 
(
  select departmentId, max(salary)
  from Employee
  group by 1
);
