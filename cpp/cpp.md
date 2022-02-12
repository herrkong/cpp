
##### if ndef   #pragma once
#ifndef是if not define的简写，#ifdef是if define的简写。
https://blog.csdn.net/qq_27278957/article/details/77988256

为了避免同一个文件被include多次，C/C++中有两种方式，一种是#ifndef方式，一种是#pragma once方式。

#ifndef 还能避免 相同内容的文件被重复引用 不同头文件中的宏定义冲突

#pragma once方式 不用担心宏定义名相同报错 
https://www.cnblogs.com/hokyhu/archive/2009/03/30/1425604.html

##### static

https://www.runoob.com/w3cnote/cpp-static-usage.html


#### volatile
https://www.runoob.com/w3cnote/c-volatile-keyword.html
当两个线程都要用到某一个变量且该变量的值会被改变时，应该用 volatile 声明，该关键字的作用是防止优化编译器把变量从内存装入 CPU 寄存器中。如果变量被装入寄存器，那么两个线程有可能一个使用内存中的变量，一个使用寄存器中的变量，这会造成程序的错误执行。volatile 的意思是让编译器每次操作该变量时一定要从内存中真正取出，而不是使用已经存在寄存器中的值

##### 内存布局 

计算变量在内存中占用几个字节

数据类型的取值范围


#### c++ 深拷贝 浅拷贝

浅拷贝 两个指针指向同一块内存
深拷贝 重新开辟一块内存 两个指针指向不同的内存区域

#### todo 
#### 多线程 修改全局变量 加解锁 demo 
#### 多协程 demo  
#### socket epoll 多路复用 demo
#### server间socket通信 demo
#### grpc通信  demo 

####  用两个stack实现 一个queue 

####  golang实现sync.map

#### cpp实现自定义队列queue
ok 










