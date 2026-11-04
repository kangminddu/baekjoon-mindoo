-- 코드를 입력하세요
SELECT distinct history_id, car_id, start_date, end_date, 
case
    when datediff(end_date, start_date) + 1 >= 30
    then '장기 대여'
    else '단기 대여'
end as rent_type
from car_rental_company_rental_history
where date_format(start_date, '%Y-%m') = '2022-09'
order by history_id desc;