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

using namespace std;

// 左值和右值
// 左值可以取地址 右值不能取地址

// 通过std::move左值 得到右值引用 指向该左值

//右值引用和std::move的应用场景
// 实现移动语义 stl和自定义类中常用 来避免对象拷贝 提升程序性能

// template<typename T>
// typename remove_reference<T>::type && move(T&& t)
// {
//     return static_cast<typename remove_reference<T>::type &&>(t);
// }

class Foo
{
public:
    std::string member;

    // Copy member.
    Foo(const std::string &m) : member(m) {}

    // Move member.
    Foo(std::string &&m) : member(std::move(m)) {}
};

void func(int &&a)
{
    cout << a << endl;
}


int main()
{
    // int a = 5;
    // int &ref_a = a;
    // // std::move将左值转化为右值
    // int &&ref_a_right = std::move(a);

    int a = 6;
    func(std::move(a));

    int b = 10;
    func(static_cast<int &&>(b));
}

