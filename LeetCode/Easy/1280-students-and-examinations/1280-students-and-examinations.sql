# Write your MySQL query statement below
select st.student_id ,st.student_name, sub.subject_name, count(ex.student_id) as attended_exams  
from Students st
join Subjects sub
left join Examinations ex
on ex.student_id =  st.student_id
and ex.subject_name = sub.subject_name
group by student_id,student_name , subject_name
order by student_id asc , subject_name asc, attended_exams desc