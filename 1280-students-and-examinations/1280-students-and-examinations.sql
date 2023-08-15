# Write your MySQL query statement below
select st.student_id , st.student_name ,s.subject_name, count(e.student_id) as attended_exams from students as st cross join subjects as s
left join examinations e
on e.student_id = st.student_id and e.subject_name=s.subject_name
group by student_id,subject_name
order by student_id, subject_name;