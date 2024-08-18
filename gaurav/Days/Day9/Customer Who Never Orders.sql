# Write your MySQL query statement below
with temp as(
SELECT id, name as Customers from Customers 
except all
SELECT Customers.id, name from Customers 
join Orders where Customers.id = Orders.customerId)
select Customers from temp;

#Better approach
#select name as Customers from Customers 
#where id not in (
#    select customerId from Orders
#);