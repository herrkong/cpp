#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <unordered_map>
#include <iterator>
#include <thread>
#include <unistd.h>
#include <algorithm>
#include <functional>
#include <pthread.h>

using namespace std;

// 读写锁 能被多个读线程拥有 但只能被一个写线程拥有的锁
// shared_mutex
//https://blog.csdn.net/gongjianbo1992/article/details/100061344



// 互斥锁 mutex 同一时刻只能被唯一一个线程拥有
//int pthread_mutex_init(pthread_mutex_t *restrict mutex, const pthread_mutexattr_t *restrict attr);
//int pthread_mutex_destroy(pthread_mutex_t *mutex);
//加锁
//int pthread_mutex_lock(pthread_mutex_t *mutex);

//解锁  
//unlock主动解锁函数，同时将阻塞在该锁上的所有线程全部唤醒，
//至于哪个线程先被唤醒，取决于优先级、调度。默认：先阻塞、先唤醒。
// int pthread_mutex_unlock(pthread_mutex_t *mutex);

//https://blog.csdn.net/ShenHang_/article/details/106818896

volatile int Tickets = 100;
pthread_mutex_t  mutex;

//线程函数
void* Worker(void * arg){
    while (Tickets > 0){
        pthread_mutex_lock(&mutex);
        printf("worker %d sell %dth tickets\n",*((int*)arg),Tickets);
        Tickets--;
        pthread_mutex_unlock(&mutex);
        usleep(10000);
    }
}

int main(){

    pthread_mutex_init(&mutex,NULL);

    pthread_t tids[3];
    for (int i = 0 ; i < 3 ; i++){
        pthread_create(&tids[i],NULL,&Worker,&i);
    }
    
    // for (int i = 0 ; i < 3 ; i++){
    //     pthread_cancel(tids[i]);
    // }

    for (int i = 0 ; i < 3 ; i++){
        pthread_join(tids[i],NULL);
    }
    sleep(2);
    pthread_mutex_destroy(&mutex);


    return 0;
}