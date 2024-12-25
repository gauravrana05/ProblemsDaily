
select product_name, sum(O.unit) as unit from Products 
join Orders as O using(product_id)
where order_date between '2020-02-01' and '2020-02-29'
group by product_id having unit >= 100;