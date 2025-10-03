# Write your MySQL query statement below
select customer_id, count(*) as count_no_trans from Visits as v
left join Transactions as t on t.visit_id =  v.visit_id
where t.visit_id is null
group by customer_id