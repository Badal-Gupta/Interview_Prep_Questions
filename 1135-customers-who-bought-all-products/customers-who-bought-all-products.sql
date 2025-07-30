-- Select customer_id from Customer 
-- group by customer_id
-- having count(distinct product_key) = (select count(*) from Product); 
SELECT customer_id
FROM (
    SELECT customer_id, product_key
    FROM Customer
    GROUP BY customer_id, product_key
) AS grouped_pairs
GROUP BY customer_id
HAVING COUNT(*) = (SELECT COUNT(*) FROM Product);