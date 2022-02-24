#include <stdio.h>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <list>
#include <memory>

// https://www.cnblogs.com/xietianjiao/p/10935413.html

// 智能指针
// 多个指针共享 user_count()计算有几个
// shared_ptr  引用计数 每一个shared_ptr的拷贝都指向同一块内存 构造一次+1 析构一次-1

// 减为0时 删除所指向的堆内存

// weak_ptr
// weak_ptr是用来解决shared_ptr相互引用时的死锁问题
//如果说两个shared_ptr相互引用,那么这两个指针的引用计数永远不可能下降为0,资源永远不会释放。
// 它是对对象的一种弱引用，不会增加对象的引用计数，和shared_ptr之间可以相互转化，
// shared_ptr可以直接赋值给它，它可以通过调用lock函数来获得shared_ptr

// unique_ptr
// 独享所有权的智能指针

//
// shared_ptr 允许多个指针指向同一个对象

// unique_ptr 独占所指向的对象

// weak_ptr shared_ptr的弱引用

int main()
{
    // 不要用普通指针初始化智能指针
    std::shared_ptr<int> a(new int(4));
    printf("%d\n", int(a.use_count()));
    printf("%d\n", *a);
    printf("%d\n", a.unique());

    //weak_ptr通过lock()获得可用shared_ptr
    std::weak_ptr<int> b(a);
    printf("b=%d\n", *b.lock());

    std::unique_ptr<int> c(new int(5));
    printf("%d\n", *c);

    return 0;
}

// #include <iostream>
// #include <future>
// #include <thread>

// using namespace std;
// class Person
// {
// public:
//     Person(int v) {
//         value = v;
//         std::cout << "Cons" <<value<< std::endl;
//     }
//     ~Person() {
//         std::cout << "Des" <<value<< std::endl;
//     }

//     int value;

// };

// int main()
// {
//     std::shared_ptr<Person> p1(new Person(1));// Person(1)的引用计数为1

//     std::shared_ptr<Person> p2 = std::make_shared<Person>(2);

//     p1.reset(new Person(3));// 首先生成新对象，然后引用计数减1，引用计数为0，故析构Person(1)
//                             // 最后将新对象的指针交给智能指针

//     std::shared_ptr<Person> p3 = p1;//现在p1和p3同时指向Person(3)，Person(3)的引用计数为2

//     p1.reset();//Person(3)的引用计数为1
//     p3.reset();//Person(3)的引用计数为0，析构Person(3)
//     return 0;
// }