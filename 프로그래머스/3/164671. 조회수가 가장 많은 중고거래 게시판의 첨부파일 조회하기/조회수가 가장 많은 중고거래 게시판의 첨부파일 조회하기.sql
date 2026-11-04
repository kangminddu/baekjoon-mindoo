-- 코드를 입력하세요
SELECT concat('/home/grep/src/', b.board_id, '/', f.file_id, f.file_name ,f.file_ext) as FILE_PATH
from used_goods_file  f join used_goods_board b on f.board_id = b.board_id 
where b.views = (select max(views) from used_goods_board)
order by f.file_id desc;