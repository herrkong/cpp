#include <stdio.h>
 
// volatile 作用
// 让编译器从内存中取值 而不是寄存器 

// 多线程环境下 可能造成CPU寄存器中的值 和 内存中的值不一致



int main()
{
    int i = 10;
    int a = i;
 
    printf("i = %d", a);
 
    // 下面汇编语句的作用就是改变内存中 i 的值
    // 但是又不让编译器知道
    __asm {
        mov dword ptr [ebp-4], 20h
    }
 
    int b = i;
    printf("i = %d", b);
    return 0;
}