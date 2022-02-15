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

// lambda函数 匿名函数 作为函数参数传递

// [外部变量的获取方式](){} 值传递还是传引用
// [=](){}
// [&](){}

int main()
{
    // 为匿名函数设定名称
    auto f =  [](int x, int y) { return x + y; };
    int sum = f(3,4);
    printf("sum= %d\n",sum);


    std::vector<int> some_list;
    int total = 0;
    for (int i = 0; i < 5; ++i)
        some_list.push_back(i);
    // total传的引用，此时匿名函数内部可以修改外部变量
    std::for_each(begin(some_list), end(some_list), [&total](int x){ total += x; });
    printf("total= %d\n",total);

    return 0;
}
