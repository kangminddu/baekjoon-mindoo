-- 코드를 작성해주세요
SELECT count(*) as FISH_COUNT, b.FISH_NAME 
from fish_info a join fish_name_info b
on a.fish_type = b.fish_type

group by a.fish_type
order by fish_count desc;