#### 进程间通信 

管道 pipe
消息队列 MessageQueue
信号 signal : 退出信号 exit等
信号量 Semaphore
共享内存 
socket套接字

#### 多路复用  select poll epoll 的区别
 
对于文件描述符的遍历方式不同 select线性查询 O(n)
epoll O(1) 只会查询活跃的fd 不会检索全部的连接

对于 需要保持大量连接 但只有少量活跃的情况 epoll的效率就明显更高


#### mutex实现原理
std::mutex 是pthrad_mutex_t 的封装

class mutex {
    pthread_mutex_t _M_mutex;
public:
    mutex() { _M_mutex = PTHREAD_MUTEX_INITIALIZER; }
    ~mutex() { pthread_mutex_destroy(&_M_mutex); }
    void lock() { pthread_mutex_lock(&_M_mutex); }
    bool try_lock() { return pthread_mutex_trylock(&_M_mutex) == 0; }
    void unlock() { pthread_mutex_unlock(&_M_mutex); }
}


####  系统性能监控

top 

内存 cpu 

####  七层模型
<!-- https://segmentfault.com/a/1190000014044351 -->

osi七层模型

tcp ip  
1 应用层   telnet  http   ftp
2 表示层
3 会话层 

4传输层  tcp udp 
5 网络层 ip  


6链路层
7物理层


#### 网络 
 三次握手 四次挥手 
send syn reponse ack

 client  --> server  1

 server --> client  2 

 client --> server  3 

 四次挥手 
send fin response ack 
 client --> server  1

 server --> client  2

 server --> client  3

 client -->  server  4

报文字段  
滑动窗口 
流量控制
拥塞控制 tcp

netstat   
established  heartbeat
close 
timewait  

保活计时器


#### tcp和udp的区别

tcp基于连接 三次握手 udp在发送数据前没有建立连接 也没有ack的确认机制
udp实时性 传输大量数据比较合适


#### tcp服务器最大并发连接数
端口上限65535

tcp连接 client ip port server ip port 
linux 文件描述符限制 

ulimit -n 一个进程最多打开的文件数

##### 为什么TIME_WAIT状态还需要等2MSL后才能返回到CLOSED状态
2msl 生存时间之内
ack确认包可能会丢失 用来重发确认
server没有收到ack 会重发fin 



#### 线程同步

https://zhuanlan.zhihu.com/p/101050199

互斥锁
条件变量
读写锁
信号量
