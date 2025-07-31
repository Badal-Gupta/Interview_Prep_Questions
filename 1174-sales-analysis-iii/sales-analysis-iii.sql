# Write your MySQL query statement below
Select p.product_id, p.product_name from Product as p
join Sales as s on p.product_id = s.product_id
group by s.product_id
having MIN(s.sale_date)>='2019-01-01' and  MAX(s.sale_date)<='2019-03-31';