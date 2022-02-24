#include <map>
#include <iterator>
#include <iostream>
#include <stdio.h>

using namespace std;

// c prinf 打印 
// int %d
// float %f 
// unsigned long %lu
// long int %ld
// long long int %lld
// unsigned long long int %llu
// 

class A{
public:
    int a;  // 4
    char b;  // 1  8 
    float c;  // 4  16 
    void Print(); // 不占字节  0
    virtual void Fight(); // 一个指针的大小 8个字节 24
};



int main(){
    printf("sizeof(A)=%d\n",int(sizeof(A)));
    int a = 0;
    float b = 1;
    double c = 2;
    char d = 'd' ;
    string e = "e";
    
    printf("a=%d,s=%lu\n",a,sizeof(a));  // int    4个字节 一个字节Byte 8个二进制位b
    printf("b=%f,s=%lu\n",b,sizeof(b));  // float  4个字节
    printf("c=%f,s=%lu\n",c,sizeof(c));  // double 8个字节
    printf("d=%c,s=%lu\n",d,sizeof(d));  // char   1个字节
    return 0;
}

