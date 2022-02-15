#### redis 五大数据结构
string 字符串 set 
hash  hset
set集合
list列表 链表结构
用作消息队列
blpop/rpush 
zset有序集合
zadd 
zrange key  withscore timestamp[mtime]


#### redis实现消息队列

1 list   点对点 一个生产者 一个消费者
rpush : 将一个或多个值 value 插入到列表 key 的表尾(最右边)
blpop : 移出并获取列表的第一个元素， 如果列表没有元素会阻塞列表直到等待超时或发现可弹出元素为止

增加消息确认机制ack

注意确保blpop出来的元素被成功完成业务处理 弹出时备份一下  如果不成功再丢回队列等待再次处理

2 subsrcibe / publish  一个生产者 多个消费者


3  Stream
XADD 
XRANGE 

再详细看下这种数据结构



##### redis 实现消息队列 方式1 和2 的区别

前者 blpop取出就删掉了 发布订阅模式 多个消费者都可以消费
前者 如果不处理 list 中会保存 后者不处理消息会被丢弃



