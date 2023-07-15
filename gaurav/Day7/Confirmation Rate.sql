# Write your MySQL query statement below

# (count(case when action='confirmed' 1 else 0 end)/count(user_id))as confirmation_rate

# select user_id, count(case when action='confirmed' then 1 else 0 end) as confirmation_rate,count(*) from Confirmations as c 
# group by user_id;

#count(case when action='confirmed' then 1 else 0 end  as asd , count( c.user_id)as fds,

# select user_id,action, count(case when action=1 then 1 else 0 end)  as asd 
# from Confirmations
# group by 1;

select s.user_id, round(avg(case when c.action='confirmed' then 1 else 0 end),2)  as confirmation_rate
from Signups as s
left join Confirmations as c
on s.user_id=c.user_id
group by s.user_id;


