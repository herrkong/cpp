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

