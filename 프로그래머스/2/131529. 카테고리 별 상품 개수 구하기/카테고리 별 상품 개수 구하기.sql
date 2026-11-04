-- 코드를 입력하세요
SELECT substring_index(product_code, 0,1) as category,
count(*)
from product
group by substring_index(product_code, 0,1)
order by substring_index(product_code, 0,1);