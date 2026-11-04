-- 코드를 작성해주세요
select grade, id, email
from (select id, email, 
     case
        when skill_code & (select sum(code) from skillcodes where category = 'Front End') > 0
        AND skill_code & (select code from skillcodes where name = 'Python') > 0
        then 'A'
        when skill_code & (select code from skillcodes where name = 'C#') > 0
        then 'B'
        when skill_code & (select sum(code) from skillcodes where category = 'Front End') > 0
        then 'C'
      END AS grade
     from developers
     )T
where grade is not null
order by grade, id;