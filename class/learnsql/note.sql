/** theory **/

一、install mysql-server (client and server)
1. download your mysql-server from this link. https://cdn.mysql.com//Downloads/MySQLInstaller/mysql-installer-community-5.7.17.0.msi
2. start your mysql-server , connect to your mysql server.
    数据表的定义。主键。自增主键。

二、base class for mysql.
1. mysql data types  ( int , bigint , char , varchar , text , float , double , decimal , datetime ， timestamp )
2. some keywords ( select  , from , where , order by ,  desc , asc , group by , max() , min() , 运算符，join , left join , right join , on,  in ， between , insert , drop , delete , grant privileges , alter  )
3. show commands; show databases;  show tables; show create table; desc command;
4. create database yourdatabase ;
5. create tables for your database （存储引擎，编码）;
6. insert data for yout tables (single data , batch insert);
7. drop operations; drop data from tables; drop tables ; drop databases;

三、mysql query:
1. single table select ; (select * from table where xxx);
2. join table select; (select * from a , b where a.xx = b.xx and a.xx = '123' order by a.xx);
3. left join table select; select * from a left join b on a.x = b.x and a.c = b.c where a.x = 'xx' and b.c='eee'; left join 的原理。
4. 聚合操作： max min avg  having 
5. order by , group by , limit , count;
6. sub query; select * from A where A.x in (select B.x from b.xxx = '1231' );
7. if (grade > 70 , 'low' , 'small');  if(value,t,f);   select id,salary,if(salary>300,'high','low') from salary;
8. ifnull(t,f)    select id,salary,ifnull(salary,0) from salary;


四、some functions in mysql
1. now()
2. date_add , date_sub();  interval 8 days; select date_add(now() , interval 3 day); select date_sub(now() , interval 1 day); month;
3. concat;
4. upper , lower , left (name , 3) , right (name , 3);lenght(name) , SubString
5. http://www.cnblogs.com/dspace/p/6194008.html
6. CurDate() 返回当前日期
7. CurTime() 返回当前时间
8. DateDiff() 计算两个日期之差
9. Date_Add() 高度灵活的日期运算函数
10. Date_Format() 返回一个格式化的日期或时间串
11. Day() 返回一个日期的天数部分
12. DayOfWeek() 对于一个日期，返回对应的星期几
13. Hour() 返回一个时间的小时部分
14. Minute() 返回一个时间的分钟部分
15. Month() 返回一个日期的月份部分
16. Now() 返回当前日期和时间
17. Second() 返回一个时间的秒部分



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
