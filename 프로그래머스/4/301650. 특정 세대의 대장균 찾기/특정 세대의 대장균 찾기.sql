-- 코드를 작성해주세요
with recursive gen as (
select id, 1 as generation
from ecoli_data
where parent_id is null
union all
select e.id, g.generation + 1
from ecoli_data e join
gen g on e.parent_id = g.id
)
select id from gen
where generation = 3
order by id;