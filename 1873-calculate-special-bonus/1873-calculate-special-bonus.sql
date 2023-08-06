# Write your MySQL query statement below



# USING UNION

# select employee_id, salary as bonus from employees
# where employee_id%2 <> 0 and name not like "M%"

# union

# select employee_id, 0 as bonus from employees
# where employee_id%2 = 0 or name like "M%"

# order by employee_id;


# OR

# USING CASE STATEMENT

select employee_id, 
case
    when employee_id%2=1 and name not like "M%" THEN salary 
    else 0
end
as bonus
from employees
order by employee_id;


