# Write your MySQL query statement below
select a.id as Id from Weather as a
join Weather as w on datediff(a.recordDate,w.recordDate) = 1
where (a.temperature > w.temperature);