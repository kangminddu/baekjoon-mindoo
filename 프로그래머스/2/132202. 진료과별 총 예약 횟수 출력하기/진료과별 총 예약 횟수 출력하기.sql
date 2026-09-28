-- 코드를 입력하세요
SELECT MCDP_CD AS 진료과코드, count(MCDP_CD) as 5월예약건수 from appointment
where date_format(apnt_ymd, '%Y-%m') = '2022-05'
group by mcdp_cd
order by count(MCDP_CD), mcdp_cd;