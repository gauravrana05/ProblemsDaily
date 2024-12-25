select t1.score, (
  select count(distinct t2.score) 
  from Scores as t2
  where t2.score >= t1.score
) as "rank"
from Scores as t1
order by 1 desc;

#Alternative
#dense_rank();

select score, dense_rank() over(order by score desc) as 'rank'
from scores
order by score desc;