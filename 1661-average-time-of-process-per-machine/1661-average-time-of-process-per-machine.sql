# Write your MySQL query statement below
select distinct a1.machine_id , round(avg(a2.timestamp - a1.timestamp),3)  as processing_time from activity as a1 join activity as a2 
on a1.machine_id = a2.machine_id and a1.process_id = a2.process_id
where a1.activity_type="start" and a2.activity_type="end"
group by machine_id;