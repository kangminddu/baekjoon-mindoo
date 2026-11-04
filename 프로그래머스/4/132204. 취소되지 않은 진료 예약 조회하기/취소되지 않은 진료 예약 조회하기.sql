-- 코드를 입력하세요
SELECT a.apnt_no, p.pt_name, p.pt_no, a.mcdp_cd, d.dr_name, a.apnt_ymd
from patient p join appointment a on p.pt_no = a.pt_no
join doctor d on d.dr_id = a.mddr_id
where a.apnt_cncl_yn = 'N' and date_format(a.apnt_ymd, '%Y-%m-%d') = '2022-04-13' and a.mcdp_cd = 'cs'
group by a.apnt_no
order by a.apnt_ymd;
