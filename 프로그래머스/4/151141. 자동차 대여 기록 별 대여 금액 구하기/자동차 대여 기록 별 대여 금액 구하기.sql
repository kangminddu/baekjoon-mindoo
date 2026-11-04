-- 코드를 입력하세요
SELECT t.history_id, round(t.daily_fee * t.days * (100 - coalesce(p.discount_rate, 0)) / 100) as fee
from (select
        h.history_id,
        c.car_type,
        c.daily_fee,
        datediff(h.end_date, h.start_date) + 1 as days,
        case
            when datediff(h.end_date, h.start_date) + 1 >= 90 then '90일 이상'
            when datediff(h.end_date, h.start_date) + 1 >= 30 then '30일 이상'
            when datediff(h.end_date, h.start_date) + 1 >= 7 then '7일 이상'
        end as duration_type
      from car_rental_company_rental_history h join
      car_rental_company_car c on h.car_id = c.car_id
      where c.car_type = '트럭'
     )T
left join car_rental_company_discount_plan p
on t.car_type = p.car_type
and t.duration_type = p.duration_type
order by fee desc, t.history_id desc;