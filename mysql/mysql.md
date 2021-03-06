
#### Mysql索引采用的数据结构B+树分析
https://segmentfault.com/a/1190000021488885
为什么 MySQL 的索引要使用 B+树而不是其它树形结构?比如 B 树？为什么不用hash表(unordered_map底层) 红黑树(map set底层)
1 从内存角度来说 数据库的数据存在磁盘上  数据量大没法全部加载进内存  b+树的设计可以分批次载入内存
2从业务角度来说 当然是hash表O(1)当然要更快O(logn) 不过B+树底层 叶子结点包含了所有数据 每个节点都有一个指向下一个节点的指针 
形成一个有序链表  更加适合适合范围查找
3 B+树和B树是多路树 而 红黑树是二叉树 相比较红黑树会产生更大 更深的树高 不利于查找 B+树比较矮胖 查询效率稳定


#### 使用b+树 而不是b树 
https://segmentfault.com/a/1190000021488885
b+树查询稳定性更好 避免磁盘io操作 

####  MySql一条查询sql的执行过程
mysql client --> server 维护一条长链接  连接器
查询缓存  之前查过会记录缓存  更新表会清掉缓存
分析器 分析sql语句的 词法分析：识别操作类型 表名 字段 语法分析：语法正确性
优化器  优先哪个索引 查找策略
执行器 mysql 引擎 innnodb   底层数据结构 b+树

#### mysql 联合索引 最左匹配原则
https://segmentfault.com/a/1190000015416513

KEY test_col1_col2_col3 on test(col1,col2,col3);
SELECT * FROM test WHERE col1=“1” AND clo2=“2” AND clo4=“4”

#### mysql redis 数据一致性问题

写操作 先写mysql再同步数据到redis
读操作 先读redis redis中无存在 去查mysql 再把查询结果同步到redis


#### 自增主键用完了怎么办

一般根本不会等到自增到用完 就已经分库分表了 

交易id 不会使用自增主键 而是自定义的表示id 

#### 自增主键 主键 


####  索引 联合索引 主键 唯一索引

加索引 编译查询 底层b+树 

普通索引 key index定义的索引
唯一索引 Unique  不允许两行具有相同的索引值  保证数据的唯一性

主键 一张表只能有一个primary key  

主键可以是多个字段的组合 主键不可为空 唯一索引可以 
主键可以做外键 唯一索引不可以


#### Transaction 事务 四大特性 和 隔离级别

acid 

原子性 atomic
隔离性
一致性
持久性

隔离级别
1）脏读
指一个事务读取到另一个事务未提交的数据。
2）不可重复读
指一个事务对同一行数据重复读取两次，但得到的结果不同。
3）虚读/幻读
指一个事务执行两次查询，但第二次查询的结果包含了第一次查询中未出现的数据。
4）丢失更新
指两个事务同时更新一行数据，后提交（或撤销）的事务将之前事务提交的数据覆盖了。


#### mysql mvcc多版本控制链

#### mysql 日志
https://cloud.tencent.com/developer/article/1695604

1 binlog  记录sql语句 追加写 

数据库事务四大特性
原子性
持久性


隔离级别
1）脏读
指一个事务读取到另一个事务未提交的数据。
2）不可重复读
指一个事务对同一行数据重复读取两次，但得到的结果不同。
3）虚读/幻读
指一个事务执行两次查询，但第二次查询的结果包含了第一次查询中未出现的数据。
4）丢失更新
指两个事务同时更新一行数据，后提交（或撤销）的事务将之前事务提交的数据覆盖了。

##### binlog使用场景
主从复制 数据恢复 

2 undo log   回滚日志
数据库事务四大特性中有一个是 原子性  通过undo log 实现
原子性 

3 redolog  重做日志 
一个是内存中的日志缓冲( redo log buffer )，另一个是磁盘上的日志文件( redo logfile)
redo 具体来说就是只记录事务对数据页做了哪些修改，
事务的四大特性里面有一个是持久性，具体来说就是只要事务提交成功，那么对数据库做的修改就被永久保存下来了，不可能因为任何原因再回到原来的状态。

#### 延时双删策略

https://cloud.tencent.com/developer/news/634004

延时双删策略 
一、 延时双删策略

在写库前后都进行redis.del(key)操作，并且设定合理的超时时间。具体步骤是：

1）先删除缓存

2）再写数据库

3）休眠500毫秒（根据具体的业务时间来定）

4）再次删除缓存。

 缓存中数据肯定是和数据库一致 