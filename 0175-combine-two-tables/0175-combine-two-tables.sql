# Write your MySQL query statement below
select firstName, lastName, a.city, a.state from person as p left join address as a on p.personId=a.personId;