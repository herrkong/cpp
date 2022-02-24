#### 腾讯二面 游戏服务器
##### 游戏服务器架构 
房间类游戏服务器 架构
登录服务器 验证账户密码 
大厅服务器
游戏房间服务器


#### 游戏服务器的登录验证
https://www.jianshu.com/p/086ba10f5e88
其实也可以 客户端大厅server 大厅server再去找登录服务器验证？ 感觉不如先通过登录服验证后再连大厅

##### 登录过程中的异常行为
同一个账号在多个终端登录
同一个登录报文被多次发送
登录过程中某服务进程失效
登录过程中终端连接已断开

为保证登录过程的健壮，可使用多段登录、服务器无状态化、

多段登录
大厅段登录以保证能够正常进入大厅
房间段登录以保证能够正常进入房间

#### APP如何与服务端安全登录 通信
https://netsecurity.51cto.com/article/615379.html

APP与服务端的整个通信过程
token机制防止非法调用 身份认证

可以确定调用者身份 采取封禁账号等措施

token机制无法防止被抓包所以要加密传输信息

##### 对APP和server之间的数据要加密
防止被抓包

当然不能采用对称加密的方案 服务端和客户端各自保存同一把私钥
在两边加解密消息

采用非对称加密  app和server之间各自生成一对公私钥 并把公钥交给对方保存

client +  公钥加密消息 --->  server 私钥解密  
非对称加密的私钥保存在server端


常见的非对称加密 rsa ecc 

非对称加密效率低 安全性高
对称加密效率高 安全性低

可以用非对称加密 对称加密算法的秘钥


##### 防重放攻击 加时间戳或者 随机字符串
拦截到请求之后照原样再给服务器发送请求 比较耗时的查数据的接口
大量重放可能导致 服务器奔溃 

请求中添加时间戳 和服务器时间对比 超时的不处理
请求时添加随机字符串 服务端存缓存  缓存中查到就认为是重复请求 不予处理


#### 放篡改  黑客也可以对随机字符串和时间戳篡改 这是APP生成的数据
不要相信任何来自客户端的东西

为了防止数据在传输过程中被篡改，我们引入数字签名机制。

将（消息密文 + 随机字符串 + 时间戳 + 私钥的加盐值 ）计算摘要 -->  数字签名
APP将数据密文、时间戳、随机字符串以及签名值一起发往服务端;
服务端再做一次同样的摘要计算 比对签名一致性 

###### 为什么要加盐值
123 md5 abc
这样能反推出密文

其实就是客户端服务端自己定义的多加一段字符串 

对称加密采用AES算法、非对称加密采用RSA算法，信息摘要算法采用MD5算法。

12306 银联数字证书


#### 信息摘要算法 
明文信息计算摘要 唯一标识确认该消息或者文件 比如md5 sha-1


##### app发送加密数据流程 
1 首先 APP 和 server 各自生成了一对非对称加密算法的公钥对  rsa算法
把APP 保存了server的公钥 server 保存了APP的公钥
2 APP随机生成一个对称加密算法aes的私钥
3 APP用server的rsa公钥对这个aes私钥加密 得到aes私钥密文 以备server端之后用rsa私钥解密出来aes的私钥
4 用这个aes私钥对消息明文加密得到消息密文
5 APP生成随机字符串 时间戳 消息密文 aes私钥密文 进行md5 得到摘要
6 app用自己的rsa私钥对md5摘要签名 得到签字值
7 将消息密文 aes私钥密文 签名值 时间戳 随机字符串 发给server

##### server解密数据流程
1 校验时间戳和服务器当前时间的差值 超过一定区间认为请求超时
2 校验随机字符串是否已经存在缓存 存在则认为是重复请求
3 对随机字符串 时间戳 消息密文 aes私钥密文 进行md5 
4 使用app的rsa公钥验证该md5和数据中传的签名进行验证  签名验证通过证明没有被篡改数据
5  服务端用rsa私钥解密aes加密密文 得到aes私钥
6 用aes私钥去解密加密消息得到消息明文
然后去处理业务逻辑




用户 --> 输入账号密码 --> app 调用登录接口 --> server
sever --> token --> app 
用户浏览数据 请求数据 --> app 请求+token -->  server 校验token合法性
---> 成功返回数据 否则返回报错




#### 服务器如何判断当前用户是否登录? token 
app 向server请求数据 
token组成  --->   uid+timestamp+sign签名 hash算法的输出hex压缩(输入uid+timestamp)

token值 比对 
服务器产生token值返回给APP 自己本地也存一份redis 


##### 游戏服务器如何保存客户端的连接token
https://www.jianshu.com/p/82a81a220722

服务端生成token 返回给客户端作为请求令牌
Token是服务端生成的一串字符串，以作客户端进行请求的一个令牌，当第一次登录后，服务器生成一个Token便将此Token返回给客户端，以后客户端只需带上这个Token前来请求数据即可，无需再次带上用户名和密码。


生成token存在redis 

服务端保存非对称加密私钥


https://cloud.tencent.com/developer/article/1164990

IOCP (完成端口IO模式) 高性能服务器 比如Apache
http://www.noobyard.com/article/p-opqibkij-cy.html

https://www.cnblogs.com/mutou3221/archive/2013/04/28/3048806.html
线程池处理异步IO请求

让所有的通信请求排到队列中，利用事先建立的少量几个线程依次处理队列中的请求，因为线程数量少，无需用大量时间进行线程切换，提高通信性能


#####  linux epoll 多路复用和windows iocp完成端口io

上述三类服务器都采用的 epoll 多路复用 
线程池 

一个可执行程序 监听了一批端口  客户端连接上其中一端口
这个可执行程序 起了线程池  建立的socket连接保存在线程中
https://blog.csdn.net/benbenr/article/details/2668423


服务程序在listen某个端口并accept某个连接请求后，会生成一个新的socket来对该请求进行处理。


https://www.cnblogs.com/liuweijian/archive/2009/12/27/1633657.html

socket编程其实对tcp/ip协议操作的封装 
accept  就是tcp三次握手
https://blog.csdn.net/bujidexinq/article/details/86296016?utm_medium=distribute.pc_relevant.none-task-blog-2~default~baidujs_baidulandingword~default-0.queryctrv4&spm=1001.2101.3001.4242.1&utm_relevant_index=3


应用层 ftp http 
网络层 tcp udp 
传输层 ip


一个唯一的tcp 连接 （client_ip client_port server_ip server_port tcp/udp）

##### 棋牌游戏服务器设计
https://www.jianshu.com/p/7b7c3efbee83




#### https http 




公私钥 非对称加密 https 
微服务 rpc服务
操作系统os
网络tcp 
计组
数据结构算法 