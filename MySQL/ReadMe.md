MySQL 是目前最流行的关系型数据库管理系统，在 WEB 应用方面 MySQL 也是目前最好的 RDBMS 应用软件之一。随着淘宝去IOE(去除IBM小型机、Oracle数据库及EMC存储设备)化的推进，MySQL 数据库在当前的互联网应用中变得越来越重要，本教程主要讲授针对 Java 开发所需的 MySQL 高级知识，课程中会让大家快速掌握索引，如何避免索引失效，索引的优化策略，了解innodb和myisam存储引擎，熟悉MySQL锁机制，能熟练配置MySQL主从复制，熟练掌握explain、show profile、慢查询日志等日常SQL诊断和性能分析策略。

常见命令：
#####C:\Windows\system32>net stop mysql0815
>MySQL0815 服务正在停止。
>MySQL0815 服务已成功停止。


#####C:\Windows\system32>net start mysql0815
>MySQL0815 服务正在启动 。
>MySQL0815 服务已经启动成功。


####C:\Windows\system32>mysql -h localhost -P 3306 -u root -p
>Enter password: ****
>Welcome to the MySQL monitor.  Commands end with ; or \g.
>Your MySQL connection id is 2
>Server version: 5.5.15 MySQL Community Server (GPL)
>
>Copyright (c) 2000, 2010, Oracle and/or its affiliates. All rights reserved.
>
>Oracle is a registered trademark of Oracle Corporation and/or its
affiliates. Other names may be trademarks of their respective
owners.
>
>Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

####mysql> exit
>Bye

####C:\Windows\system32>mysql -h localhost -P 3306 -u root -proot
>Welcome to the MySQL monitor.  Commands end with ; or \g.
Your MySQL connection id is 3
Server version: 5.5.15 MySQL Community Server (GPL)
>
>Copyright (c) 2000, 2010, Oracle and/or its affiliates. All rights reserved.
>
>Oracle is a registered trademark of Oracle Corporation and/or its
affiliates. Other names may be trademarks of their respective
owners.
>
>Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.
>
####mysql> exit
>Bye

####C:\Windows\system32>mysql -u root -proot
>Welcome to the MySQL monitor.  Commands end with ; or \g.
Your MySQL connection id is 4
Server version: 5.5.15 MySQL Community Server (GPL)
>
>Copyright (c) 2000, 2010, Oracle and/or its affiliates. All rights reserved.
>
>Oracle is a registered trademark of Oracle Corporation and/or its
affiliates. Other names may be trademarks of their respective
>owners.
>
>Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

####mysql> show databases;
>+--------------------+
| Database           |
>+--------------------+
| information_schema |
| mysql              |
| performance_schema |
| test               |
>+--------------------+
4 rows in set (0.00 sec)

####mysql> use test;
>Database changed
mysql> show tables;
Empty set (0.00 sec)

####mysql> show tables from mysql;
>+---------------------------+
| Tables_in_mysql           |
+---------------------------+
| columns_priv              |
| db                        |
| event                     |
| func                      |
| general_log               |
| help_category             |
| help_keyword              |
| help_relation             |
| help_topic                |
| host                      |
| ndb_binlog_index          |
| plugin                    |
| proc                      |
| procs_priv                |
| proxies_priv              |
| servers                   |
| slow_log                  |
| tables_priv               |
| time_zone                 |
| time_zone_leap_second     |
| time_zone_name            |
| time_zone_transition      |
| time_zone_transition_type |
| user                      |
+---------------------------+
24 rows in set (0.00 sec)

####mysql> select database();
>+------------+
| database() |
+------------+
| test       |
+------------+
1 row in set (0.00 sec)

>mysql> create table stuinfo(
    -> id int,
    -> name varchar(20));
Query OK, 0 rows affected (0.01 sec)

####mysql> show tables;
>+----------------+
| Tables_in_test |
>+----------------+
| stuinfo        |
>+----------------+
>1 row in set (0.00 sec)

####mysql> desc stuinfo;
>+-------+-------------+------+-----+---------+-------+
>| Field | Type        | Null | Key | Default | Extra |
+-------+-------------+------+-----+---------+-------+
| id    | int(11)     | YES  |     | NULL    |       |
| name  | varchar(20) | YES  |     | NULL    |       |
+-------+-------------+------+-----+---------+-------+
2 rows in set (0.00 sec)

####mysql> select * from stuinfo;
>Empty set (0.00 sec)

####mysql> insert into stuinfo (id,name) values(1,'john');
>Query OK, 1 row affected (0.00 sec)

####mysql> insert into stuinfo (id,name) values(2,'rose');
>Query OK, 1 row affected (0.00 sec)

####mysql> select * from stuinfo;
>+------+------+
| id   | name |
+------+------+
|    1 | john |
|    2 | rose |
+------+------+
2 rows in set (0.00 sec)

####mysql> update stuinfo set name='lilei' where id=1;
>Query OK, 1 row affected (0.00 sec)
Rows matched: 1  Changed: 1  Warnings: 0

####mysql> select * from stuinfo;
>+------+-------+
| id   | name  |
+------+-------+
|    1 | lilei |
|    2 | rose  |
+------+-------+
2 rows in set (0.00 sec)

####mysql> delete from stuinfo where id=1;
>Query OK, 1 row affected (0.00 sec)

####mysql> select * from stuinfo;
>+------+------+
| id   | name |
+------+------+
>|    2 | rose |
+------+------+
1 row in set (0.00 sec)

####mysql> select version();
>+-----------+
| version() |
+-----------+
| 5.5.15    |
+-----------+
1 row in set (0.00 sec)

####mysql> exit
>Bye

####C:\Windows\system32>mysql --version
>mysql  Ver 14.14 Distrib 5.5.15, for Win32 (x86)

####C:\Windows\system32>mysql -V
>mysql  Ver 14.14 Distrib 5.5.15, for Win32 (x86)


####mysql> show DATABASES;
>+--------------------+
| Database           |
+--------------------+
| information_schema |
| mysql              |
| performance_schema |
| test               |
+--------------------+
4 rows in set (0.00 sec)

####mysql> SHOW DATABASES\g
>+--------------------+
| Database           |
+--------------------+
| information_schema |
| mysql              |
| performance_schema |
| test               |
+--------------------+
4 rows in set (0.00 sec)

####mysql> use test;
>Database changed
mysql> select * from stuinfo;
+------+------+
| id   | name |
+------+------+
|    2 | rose |
+------+------+
1 row in set (0.00 sec)

####mysql> select *
>-> from stuinfo;
+------+------+
| id   | name |
+------+------+
|    2 | rose |
+------+------+
1 row in set (0.00 sec)

####mysql> SELECT * FROM stuinfo;
>+------+------+
| id   | name |
+------+------+
|    2 | rose |
+------+------+
1 row in set (0.00 sec)

####mysql> select * from stuinfo;
>+------+------+
| id   | name |
+------+------+
>|    2 | rose |
+------+------+
1 row in set (0.00 sec)

####mysql> #select * from stuinfo;
>mysql>