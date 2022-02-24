#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <deque>
#include <list>

// malloc底层实现
// 内存池 
//从堆中预先分配了内存 划分为多个内存块形成链表结构  已分配内存  未分配内存 


// linux 
// 内核态 1G
// 用户态 3G



int main()
{
    int *a = new (int);
    int *b = (int *)malloc(10);
    char * c = (char*)malloc(5);
    *a = 10;
    *b = 20;
    *c = 'c';
    printf("*c=%c\n",*c);
    printf("sizeof(a)=%d,sizeof(b)=%d\n",int(sizeof(a)),int(sizeof(b)));
    printf("a=%p,*a=%d,b=%p,*b=%d\n",a,*a,b,*b);

    return 0;
}