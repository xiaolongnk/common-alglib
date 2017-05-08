/** show database structure **/
show databases;
/** show tables **/
show tables;
/** select database **/
use learning_sql;

/** show table structure **/
desc we_student;
desc we_department;
desc we_class;
desc we_group;
desc we_worker;

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

select * from we_worker 
        where department = 1 and id not in 
            (select distinct teacher_id from we_group);


select * from we_worker 
        where department = 1 and id in 
            (select distinct teacher_id from we_group);
select * from we_worker 
        where department = 1 and not exists 
        (select * from we_group where teacher_id = we_worker.id);

select * from we_worker where department = 1 and exists (select * from we_group where teacher_id = we_worker.id);



/**  6. mysql 内置函数 date_add and date_sub  **/

update we_worker set in_time=date_add(in_time , interval 2 day) where id = 1;
update we_worker set in_time=date_sub(in_time , interval 3 month) where id = 10;

/** 7. 入职满一年的员工 **/

select * from we_worker where in_time <= date_sub(now() , interval 1 year) ;


/** 8. 每个课程的开课数量 **/

select class_id , count(*) as count from we_group group by class_id;

/** 9. 每门课程的 课程id , 开课数量，课程名称 **/

select a.id , r.total, a.name , a.class_description  from we_class as a left join (select class_id , count(*) as total from we_group group by class_id) r on a.id  = r.class_id;

select a.id , r.total, a.name , a.class_description  from we_class as a left join (select class_id , count(*) as total from we_group group by class_id) r on a.id  = r.class_id where r.total is not null;


/** 10. 找出还没开班的课程 **/

select a.id 
    from we_class a 
    left join 
    we_group b 
    on a.id = b.class_id 
    where b.id is null;
    
select * from we_class a , we_group b where a.id = b.class_id;

/** 11.这出一个  学生的姓名,班级开课时间,班级节课时间,课程名称，带课老师名称  **/
+-----------+---------------------+---------------------+---------+---------------------+--------------+
| name      | starttime           | endtime             | name    | class_description   | teacher_name |
+-----------+---------------------+---------------------+---------+---------------------+--------------+
| 张一凡    | 2017-07-14 09:00:00 | 2017-08-14 00:00:00 | c语言   | 基本c语言语法       | 000          |
| 王鑫      | 2017-07-14 09:00:00 | 2017-08-14 00:00:00 | c语言   | 基本c语言语法       | 000          |
+-----------+---------------------+---------------------+---------+---------------------+--------------+

select a.name , b.id as group_id  , c.name, c.class_description , d.name  
    from we_student a 
    left join we_group b on a.group_id = b.id 
    left join we_class c on b.class_id = c.id 
    left join we_worker d on b.teacher_id = d.id;
