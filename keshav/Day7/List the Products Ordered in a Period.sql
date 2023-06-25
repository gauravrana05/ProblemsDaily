# Write your MySQL query statement below

select product_name, sum(unit) as unit
from Products
inner join Orders on Products.product_id = Orders.product_id
where order_date > '2020-01-31' AND order_date < '2020-03-01' 
group by(product_name)
having(unit>99)
