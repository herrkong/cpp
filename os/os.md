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

