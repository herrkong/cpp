#include <iostream>

using namespace std;

// https://www.w3xue.com/exp/article/20216/74508.html
// 单例模式的自动释放
// 1 友元类 2 内部类+静态数据成员 3 atexit  4 pthread_once()+atexit()

class Singleton {
public:
    //静态成员函数
    static Singleton * GetSingleton(){
        if (m_pSingleton == NULL){
            m_pSingleton = new Singleton;
            //用于注册程序退出后的回调函数
            atexit(Destroy);
        }
        return m_pSingleton;
    }
    static void Destroy(){
        if (m_pSingleton){
            delete m_pSingleton;
        }
    }

private:
    //构造和析构函数都设为private
    Singleton(){ std::cout << "new singleton" << std::endl;}
    ~Singleton(){ std::cout << "delete singleton" << std::endl;}
private:
    //静态成员变量
    static Singleton* m_pSingleton ;
};

// 饿汉模式 线程安全 内存中始终存在
Singleton* Singleton::m_pSingleton = Singleton::GetSingleton();

