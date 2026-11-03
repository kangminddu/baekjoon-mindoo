-- 코드를 작성해주세요
SELECT count(*) as FISH_COUNT, max(LENGTH) as MAX_LENGTH, FISH_TYPE
from fish_info
group by fish_type
having avg(coalesce(length, 10)) >= 33
order by fish_type asc;