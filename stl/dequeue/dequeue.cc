#include <stdio.h>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <list>
#include <deque>

// https://www.cnblogs.com/linuxandmcu/p/10260124.html
//  双端队列

// 使用场景
// 方便查找且内存扩展
// 连续内存 两侧均可增减元素

void PrintDeque(std::deque<int> &dq)
{
    for (auto &e : dq)
    {
        printf("%d,", e);
    }
    printf("\n");
}

int main()
{
    std::deque<int> a;
    std::deque<int> b(10);
    std::deque<int> c(10, 1);
    std::deque<int> d(a);
    std::deque<int> e(a.begin(), a.begin() + 3);

    int n[] = {1, 2, 3, 4, 5};
    std::deque<int> f(n, n + 5);
    std::deque<int> g(&n[1], &n[4]); // n[1] n[2] n[3]

    PrintDeque(f);
    PrintDeque(g);

    return 0; 
}
