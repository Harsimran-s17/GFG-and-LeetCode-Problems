# Write your MySQL query statement below
select name as customers from  Customers Left join orders on customers.id=orders.customerId where orders.customerid is null;

# OR

# select name as customers from customers where id not in(select customerid from orders);