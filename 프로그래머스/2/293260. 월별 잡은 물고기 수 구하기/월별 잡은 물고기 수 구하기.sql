-- 코드를 작성해주세요
SELECT count(*) as FISH_COUNT, MONTH(time) as MONTH
from fish_info
group by MONTH(time)
order by month;