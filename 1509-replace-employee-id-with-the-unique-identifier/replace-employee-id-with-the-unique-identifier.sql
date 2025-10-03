# Write your MySQL query statement below
select e.unique_id, a.name from Employees as a
left join EmployeeUNI as e on a.id = e.id;