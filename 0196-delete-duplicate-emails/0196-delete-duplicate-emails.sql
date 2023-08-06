# Write your MySQL query statement below

# delete p from person as p, person as s where p.id>s.id and p.email=s.email;

# OR
with cte as (select * from person)
delete from person where id not in(select min(id) from cte group by email);