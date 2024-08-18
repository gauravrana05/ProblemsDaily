with temp as(
    select user_id as id, sum(distance) as travelled_distance
    from Rides 
    group by 1 
)
select name,COALESCE(travelled_distance,0) as travelled_distance from Users 
left join temp using(id)
order by travelled_distance desc, name;