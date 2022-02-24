#include <stdio.h>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <deque>
#include <list>

// 有序数组
// 去除多余元素 不开辟多余内存
// 借助map
int DelExtraElem(int a[], int len)
{
    int j = 0;
    for (int i = 1; i < len; i++)
    {
       if (a[j] != a[i] ){
           a[++j] = a[i];
       }

    }
    return ++j ;
}

void PrintArray(int a[], int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d,", a[i]);
    }
    printf("\n");
}

int main()
{
    // int a[] = {1,2,3,4,5};
    // int num = sizeof(a) / sizeof(a[0]);

    int a[5] = {0, 1, 1, 1, 2 };
    int new_len = DelExtraElem(a, 5);
    printf("new_len=%d\n", new_len);
    // PrintArray(a,new_len);

    return 0;
}

// tcp

// 滑动窗口
// ip + port

// 存放在包头

// 大小端
// 0x1234
// 大端   0x12  0x34
// 小端   0x34  0x12

// 大小端转换
// 便于传输
// 地址 存放数据
// 取数据

// 共享内存  mmap
// 共享临界资源区 多个进程访问到该内存区域

// 创建 多大的共享内存区域

// linux 用户态 3g
// 内核态 1g

// mysql
// 存储引擎
// b+树 查询效率高
// 多路查找树
// 数据存在叶子结点
// 有序 链表
// 范围查询

// 非主键索引 叶子结点
// 主键索引
