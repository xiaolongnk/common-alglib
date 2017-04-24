/** 1. 工资最高的worker，输出姓名和工资，按照工资从小到大排序。 **/
select name , wage from we_worker order by wage desc limit 10; [ offset , size]
select name , wage from we_worker order by wage desc limit 10 , 10;
select name , wage from we_worker where wage = (select max(wage) from we_worker);

/** 2. 找出所有的员工的部门名称，输出 老师姓名和部门名称 */
select a.name  as teacher_name , b.name as department_name from we_worker as a  left join we_department b on a.department = b.id;
select * from we_worker a left join we_department b  on a.department = b.id;

/** 3. 找出每个老师带课的数量 **/
select teacher_id , count(*) as class_num from we_group  group by teacher_id order by class_num desc;

/** 4. 每个老师的id,工资， 带课数量  **/
select a.name , a.id , b.class_num  from we_worker a left join (select teacher_id , count(*) as class_num from we_group group by teacher_id) b on a.id = b.teacher_id  where a.department = 1;

/** 5. 还没带班级的老师 **/
/** 5.1 找出所有带班的老师  **/

select * from we_worker where department = 1 and id not in (select distinct teacher_id from we_group);

select * from we_worker where department = 1 and id in (select distinct teacher_id from we_group);

select * from we_worker where department = 1 and not exists (select * from we_group where teacher_id = we_worker.id);

select * from we_worker where department = 1 and exists (select * from we_group where teacher_id = we_worker.id);

/** 6. mysql 内置函数 **/
/**  date_add and date_sub **/

update we_worker set in_time=date_add(in_time , interval 2 day) where id = 1;
update we_worker set in_time=date_add(in_time , interval 10 day) where id = 2;
update we_worker set in_time=date_add(in_time , interval 6 day) where id = 3;
update we_worker set in_time=date_sub(in_time , interval 1 month) where id = 4;
update we_worker set in_time=date_sub(in_time , interval 2 month) where id = 5;
update we_worker set in_time=date_sub(in_time , interval 70 day) where id = 6;
update we_worker set in_time=date_sub(in_time , interval 1 year) where id = 7;
update we_worker set in_time=date_sub(in_time , interval 2 year) where id = 8;
update we_worker set in_time=date_sub(in_time , interval 4 month) where id = 9;
update we_worker set in_time=date_sub(in_time , interval 3 month) where id = 10;

/** 7. 入职满一年的员工 **/

select * from we_worker where in_time <= date_sub(now() , interval 1 year) ;








SELECT
  title '商品名称',
  template_id '商品编号',
  provider '供应商',
  remain '库存'
FROM (
		SELECT
        a.provider                    AS provider,
        a.template_id                 AS template_id,
        if(remain IS NULL, 0, remain) AS remain
      	FROM  (
			 (
			  SELECT
              count(*) AS sum,
              template_id,
              provider
            FROM t_real
            GROUP BY template_id, provider
			) a 
		LEFT JOIN
        	(SELECT
           	count(*) AS remain,
           	template_id,
           	provider
         	FROM t_real
         	WHERE status = 0
         	GROUP BY template_id, provider) b
          ON a.template_id = b.template_id AND a.provider=b.provider)
) r  left join t_fc t on r.template_id = t.id;

