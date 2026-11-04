-- 코드를 입력하세요
SELECT u.user_id as user_id, u.nickname as nickname, sum(b.price) as total_sales
from used_goods_board b join used_goods_user u on b.writer_id = u.user_id
where b.status = 'DONE'
group by user_id
having sum(b.price) >= 700000
order by total_sales;