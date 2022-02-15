
#### Mysql索引采用的数据结构B+树分析
https://segmentfault.com/a/1190000021488885
为什么 MySQL 的索引要使用 B+树而不是其它树形结构?比如 B 树？为什么不用hash表(unordered_map底层) 红黑树(map set底层)
1 从内存角度来说 数据库的数据存在磁盘上  数据量大没法全部加载进内存  b+树的设计可以分批次载入内存
2从业务角度来说 当然是hash表O(1)当然要更快O(logn) 不过B+树底层 叶子结点包含了所有数据 每个节点都有一个指向下一个节点的指针 
形成一个有序链表  更加适合适合范围查找
3 B+树和B树是多路树 而 红黑树是二叉树 相比较红黑树会产生更大 更深的树高 不利于查找 B+树比较矮胖 查询效率稳定



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