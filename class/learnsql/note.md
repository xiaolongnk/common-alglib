## 理论知识

#### 一、install mysql-server (client and server)

1. download your mysql-server from this link. https://cdn.mysql.com//Downloads/MySQLInstaller/mysql-installer-community-5.7.17.0.msi
2. start your mysql-server , connect to your mysql server.

#### 二、base class for mysql.

1. mysql data types  ` int , bigint , char , varchar , text , float , double , decimal , datetime ， timestamp`
2. some keywords ( `select`,`from`,`where`, `order by`,`desc`,`asc`,`group by`,`+`,`-`,`*`,`/`,`left join`,`right join`,`on`,`in`,`between`, `insert`,`drop`, `delete` ,`alter`....)
3. show commands;
    ```
    show databases; 
    show tables;
    show create table;
    desc command;
    ```
4. create database
    ```
    create database yourdatabase ;
    ```
5. 创建数据库。create tables for your database;
6. 单列插入，批量插入。 insert data for yout tables (single data , batch insert);
7. 删除操作。drop operations; drop data from tables; drop tables ; drop databases;

#### 三、mysql query:

1. single table select ; (select * from table where xxx);
2. join table select; (select * from a , b where a.xx = b.xx and a.xx = '123' order by a.xx);
3. left join table select; select * from a left join b on a.x = b.x and a.c = b.c where a.x = 'xx' and b.c='eee'; left join 的原理。
4. 聚合操作： max min avg  having 
5. order by , group by , limit , count;
6. sub query; select * from A where A.x in (select B.x from b.xxx = '1231' );
7. if (grade > 70 , 'low' , 'small');  if(value,t,f);   select id,salary,if(salary>300,'high','low') from salary;
8. ifnull(t,f)    select id,salary,ifnull(salary,0) from salary;

#### 四、mysql中的内置函数

1. now()
2. date_add , date_sub();  interval 8 days; select date_add(now() , interval 3 day); select date_sub(now() , interval 1 day); month;
4. upper , lower , left (name , 3) , right (name , 3);lenght(name) , SubString
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



## 数据库表结构

1. we_student

	| Field         | Type        | Null | Key | Default             | Extra          |
	---------------+-------------+------+-----+---------------------+----------------
	| id            | bigint(20)  | NO   | PRI | NULL                | auto_increment |
	| group_id      | bigint(20)  | NO   |     | 0                   |                |
	| name          | varchar(64) | NO   |     |                     |                |
	| email         | varchar(64) | NO   |     |                     |                |
	| gender        | char(1)     | NO   |     | F                   |                |
	| address       | varchar(64) | NO   |     |                     |                |
	| parents_phone | varchar(32) | NO   |     |                     |                |
	| school_grade  | smallint(6) | NO   |     | 1                   |                |
	| birthday      | datetime    | NO   |     | 1990-01-01 00:00:00 |                |
	| ctime         | datetime    | NO   |     | CURRENT_TIMESTAMP   |                |
	| mtime         | datetime    | NO   |     | CURRENT_TIMESTAMP   |                |
	| status        | smallint(6) | NO   |     | 1                   |                |
	
2. we_class

	| Field             | Type          | Null | Key | Default           | Extra          |
	-------------------+---------------+------+-----+-------------------+----------------+
	| id                | bigint(20)    | NO   | PRI | NULL              | auto_increment |
	| name              | varchar(64)   | NO   |     |                   |                |
	| class_description | varchar(2048) | NO   |     |                   |                |
	| price             | int(11)       | NO   |     | 3000              |                |
	| price_description | varchar(2048) | NO   |     |                   |                |
	| ctime             | datetime      | NO   |     | CURRENT_TIMESTAMP |                |
	
3. we_group

	| Field      | Type        | Null | Key | Default           | Extra          |
	------------+-------------+------+-----+-------------------+----------------+
	| id         | bigint(20)  | NO   | PRI | NULL              | auto_increment |
	| class_id   | smallint(6) | NO   |     | 1                 |                |
	| starttime  | datetime    | NO   |     | CURRENT_TIMESTAMP |                |
	| endtime    | datetime    | NO   |     | CURRENT_TIMESTAMP |                |
	| teacher_id | bigint(20)  | NO   |     | 0                 |                |
	| status     | smallint(6) | NO   |     | 0                 |                |

4. we_worker

	| Field      | Type        | Null | Key | Default           | Extra          |
	------------+-------------+------+-----+-------------------+----------------+
	| id         | bigint(20)  | NO   | PRI | NULL              | auto_increment |
	| name       | varchar(64) | NO   |     |                   |                |
	| sex        | char(1)     | NO   |     | M                 |                |
	| mobile     | varchar(32) | NO   |     |                   |                |
	| birthday   | datetime    | NO   |     | CURRENT_TIMESTAMP |                |
	| card_id    | varchar(32) | NO   |     |                   |                |
	| wage       | int(10)     | NO   |     | 0                 |                |
	| department | bigint(20)  | NO   |     | 0                 |                |
	| in_time    | datetime    | NO   |     | CURRENT_TIMESTAMP |                |
	| out_time   | datetime    | NO   |     | CURRENT_TIMESTAMP |                |
	| status     | smallint(6) | NO   |     | 1                 |                |
	
5. we_department

	| Field       | Type          | Null | Key | Default           | Extra          |
	-------------+---------------+------+-----+-------------------+----------------+
	| id          | bigint(20)    | NO   | PRI | NULL              | auto_increment |
	| name        | varchar(32)   | NO   |     |                   |                |
	| description | varchar(2048) | NO   |     |                   |                |
	| ctime       | datetime      | NO   |     | CURRENT_TIMESTAMP |                |


## 创建数据库和数据表

1. 创建数据表

	```
	/**学生表**/
	create table we_student (
	  id bigint(20) auto_increment,
	  group_id bigint(20) not null default 0 comment 'group_id for the student',
	  name varchar(64) not null default '' comment 'name of the student',
	  email varchar(64) not null default '' comment 'email for the student',
	  sex char not null default 'F' comment 'sex of the student',
	  address varchar(64) not null default '' comment 'address of the student',
	  parents_phone varchar(32) not null default '' comment 'parents mobile',
	  school_grade smallint not null default 1 comment '1-6 for 初一 ~ 高三',
	  birthday datetime not null default '1990-01-01 00:00:00',
	  ctime datetime not null default CURRENT_TIMESTAMP ,
	  mtime datetime not null default CURRENT_TIMESTAMP ,
	  status smallint not null default 1 comment '1:normal , -1: delete',
	  primary key (id)
	) engine = InnoDB , charset=utf8 , comment 'student table' ;
	
	/**课程表，记录所有的课程**/
	create table we_class (
	  id bigint(20) auto_increment comment 'class id for this class',
	  name varchar(64) not null default '' comment 'name for this class.',
	  class_description varchar(2048)  not null default '' comment 'class description',
	  price int(11) not null default 3000 comment 'price for this class',
	  price_description varchar(2048) not null default '' comment 'description for price',
	  ctime datetime not null default CURRENT_TIMESTAMP comment 'create time',
	  primary key (id)
	) engine = InnoDB , charset=utf8 , comment 'all class table';
	
	/**table for teacher*/
	create table we_worker(
	  id bigint(20) auto_increment comment 'id for teacher',
	  name varchar(64) not null default '' comment 'teacher name',
	  sex char not null default 'M' comment 'M for man , female for woman',
	  mobile varchar(32) not null default '' comment 'mobile',
	  birthday datetime not null default CURRENT_TIMESTAMP,
	  card_id varchar(32) not null default '' comment 'wage card id',
	  wage int(10) not null default 0 comment 'wage for the teacher',
	  department bigint(20) not null default 0 comment 'depart id for this worker',
	  in_time datetime not null default  CURRENT_TIMESTAMP comment '入职时间',
	  out_time datetime not null default CURRENT_TIMESTAMP comment '离职时间',
	  status smallint not null default 1 comment '1: 在职 , -1:离职',
	  primary key (id)
	) engine = InnoDB , charset=utf8 , comment 'table for teacher';
	
	/** table for departments **/
	create table we_department
	(
	  id bigint(20) AUTO_INCREMENT comment '',
	  name varchar(32) not null default '' comment 'department name',
	  description varchar(2048) not null default '' comment 'description for this department',
	  ctime datetime not null default CURRENT_TIMESTAMP,
	  primary key (id)
	) engine = InnoDB , charset =utf8 , comment 'table for departments';
	
	
	/** table for groups: groups represents students set **/
	
	create table we_group
	(
	  id bigint(20) auto_increment comment '',
	  class_id smallint not null default 1 comment 'class id for this group',
	  starttime datetime not null default CURRENT_TIMESTAMP comment 'start time for this group',
	  endtime datetime not null default  CURRENT_TIMESTAMP comment 'end time for this group',
	  teacher_id bigint(20) not null default 0 comment 'worker id',
	  status smallint not null default 0 comment '0: planning , 1:in process , 2: finished , -1: canceled',
	  primary key (id)
	) engine = InnoDB , charset =utf8 , comment 'table for student groups';
	
	```
2. 插入测试数据

	```
	insert into we_worker ( name , sex , mobile , birthday , card_id , wage , department , in_time , out_time) values
	('欧小龙' , 'M' , '18201176525' ,'1990-10-18' , '18201176525' ,  10000 , 1 , '2017-07-13 00:00:00' , '0001-01-01 00:00:00');
	
	/* for we_group **/
	insert into we_group (class_id , starttime , endtime , teacher_id) values (1 , '2017-07-14 09:00:00' , '2017-08-14 00:00:00' , 1);
	insert into we_group (class_id , starttime , endtime , teacher_id) values (1 , '2017-07-14 09:00:00' , '2017-08-14 00:00:00' , 1);
	insert into we_group (class_id , starttime , endtime , teacher_id) values (1 , '2017-07-14 09:00:00' , '2017-08-14 00:00:00' , 1);
	insert into we_group (class_id , starttime , endtime , teacher_id) values (1 , '2017-07-14 09:00:00' , '2017-08-14 00:00:00' , 1);
	
	/* for we_department **/
	insert into we_department ( name , description ) values ('teacher' , '教工部' );
	insert into we_department ( name , description ) values ('adminstration' , '行政部' );
	insert into we_department ( name , description ) values ('finacial' , '财务部' );
	insert into we_department ( name , description ) values ('human resource' , '人力资源' );
	
	
	insert into we_class (name  , class_description , price , price_description ) values ('c语言入门' , 'test ' , 30 , 'test');
	
	```


## SQL查询练习 习题

1. 数据库操作，查看库和表结构

	```mysql
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
	```

2. 工资最高的worker，输出姓名和工资，按照工资从小到大排序 `select ` , `order by` , `limit`
	
	```
	select name , wage from we_worker order by wage desc limit 10; [ offset , size]
	select name , wage from we_worker order by wage desc limit 10 , 10;
	select name , wage from we_worker where wage = (select max(wage) from we_worker);
	```

3. 找出所有的员工的部门名称，输出 老师姓名和部门名称 `left join`

	```
	select a.name  as teacher_name , b.name as department_name from we_worker as a  left join we_department b on a.department = b.id;
	select * from we_worker a left join we_department b  on a.department = b.id;
	```

4. 找出每个老师带课的数量 `group by` , `count`

	```
	select teacher_id , count(*) as class_num from we_group  group by teacher_id order by class_num desc;
	```

5. 每个老师的id,工资， 带课数量 `left join`
	```
	select a.name , a.id , b.class_num  from we_worker a left join (select teacher_id , count(*) as class_num from we_group group by teacher_id) b on a.id = b.teacher_id  where a.department = 1;
	```

6. 还没带班级的老师, 以及所有带班的老师 `子查询`，聚合函数 `count`，`exists`

	```
	select * from we_worker 
	        where department = 1 and id not in 
	            (select distinct teacher_id from we_group);
	select * from we_worker 
	        where department = 1 and id in 
	            (select distinct teacher_id from we_group);
	select * from we_worker 
	        where department = 1 and not exists 
	        (select * from we_group where teacher_id = we_worker.id);
	
	select * from we_worker 
		where department = 1 
				and exists 
				(select * from we_group where teacher_id = we_worker.id);
	```

7. mysql 内置函数 `date_add` and `date_sub`, 以及数据 `update`

	```
	update we_worker set in_time=date_add(in_time , interval 2 day) where id = 1;
	update we_worker set in_time=date_sub(in_time , interval 3 month) where id = 10;
	```

8. 入职满一年的员工

	```
	select * from we_worker where in_time <= date_sub(now() , interval 1 year) ;
	```

9. 每个课程的开课数量

	```
	select class_id , count(*) as count from we_group group by class_id;
	```
10. 每门课程的 课程id , 开课数量，课程名称

	```
	select a.id , r.total, a.name , a.class_description  from we_class as a left join (select class_id , count(*) as total from we_group group by class_id) r on a.id  = r.class_id;
	
	select a.id , r.total, a.name , a.class_description  from we_class as a left join (select class_id , count(*) as total from we_group group by class_id) r on a.id  = r.class_id where r.total is not null;
	```

11. 找出还没开班的课程 , 多表 `left join` , 4 个表

	```
	select a.id 
	    from we_class a 
	    left join 
	    we_group b 
	    on a.id = b.class_id 
	    where b.id is null;
	    
	select * from we_class a , we_group b where a.id = b.class_id;
	```

12. 这出一个  学生的姓名,班级开课时间,班级节课时间,课程名称，带课老师名称,下面是输出示例

	| name      | starttime           | endtime             | name    | class_description   | teacher_name |
	-----------+---------------------+---------------------+---------+---------------------+--------------+
	| 张一凡    | 2017-07-14 09:00:00 | 2017-08-14 00:00:00 | c语言   | 基本c语言语法       | 000          |
	| 王鑫      | 2017-07-14 09:00:00 | 2017-08-14 00:00:00 | c语言   | 基本c语言语法       | 000          |
	
	```
	select a.name , b.id as group_id  , c.name, c.class_description , d.name  
	    from we_student a 
	    left join we_group b on a.group_id = b.id 
	    left join we_class c on b.class_id = c.id 
	    left join we_worker d on b.teacher_id = d.id;
	```
