#include <stdio.h>	
#include <vector>	
#include <set>	
#include <map>	
#include <unordered_map>	
#include <list>


//https://zhiqiang.org/coding/std-mutex-implement.html
// std::mutex 是pthrad_mutex_t 的封装
typedef union {
  struct __pthread_mutex_s {
    int __lock;                 //!< mutex状态，0：未占用；1：占用。
    unsigned int __count;       //!< 可重入锁时，持有线程上锁的次数。
    int __owner;                //!< 持有线程的线程ID。
    unsigned int __nusers;
    int __kind;                 //!< 上锁类型。
    int __spins;
    __pthread_list_t __list;
  } __data;
} pthread_mutex_t;


class mutex {
    pthread_mutex_t _M_mutex;
public:
    mutex() { _M_mutex = PTHREAD_MUTEX_INITIALIZER; }
    ~mutex() { pthread_mutex_destroy(&_M_mutex); }
    void lock() { pthread_mutex_lock(&_M_mutex); }
    bool try_lock() { return pthread_mutex_trylock(&_M_mutex) == 0; }
    void unlock() { pthread_mutex_unlock(&_M_mutex); }
}


int main() {

     return 0;
}