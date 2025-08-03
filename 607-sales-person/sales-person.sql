# Write your MySQL query statement below
Select name from SalesPerson as s
where sales_id not in (
    select sales_id from Orders as o 
    join Company as c on o.com_id = c.com_id
    where c.name ='RED'
);