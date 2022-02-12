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


int main(){
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

