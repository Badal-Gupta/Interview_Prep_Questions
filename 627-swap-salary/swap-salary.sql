# Write your MySQL query statement below
-- Update Salary 
-- set sex=case 
-- when sex = 'f' then 'm'
-- when sex = 'm' then 'f'
-- -- else sex = 'm'
-- end;

update Salary
set sex=if(sex='f','m','f');