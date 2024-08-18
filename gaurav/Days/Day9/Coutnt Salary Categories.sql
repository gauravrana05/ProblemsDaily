select category,count(*) - 1 as accounts_count 
from (
    select
        case
            when income < 20000 then "Low Salary"
            when income <= 50000 then "Average Salary"
            else "High Salary"
  end as category
from
  Accounts
    union all 
    select 'Average Salary' as category
    union all 
    select 'Low Salary' as category
    union all 
    select 'High Salary' as category)temp 
group by 1;
