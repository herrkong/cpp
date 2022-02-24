#### rpc调用和http调用的区别

https://blog.csdn.net/m0_38110132/article/details/81481454

#### 基于协议不同导致的传输效率不同
rpc  tcp/ip协议
http 
七层网络模型

应用层的http
传输层的 tcp
网络层 ip 

当然是rpc调用更快 长链接


#### rpc的服务注册与发现
https://www.cnkirito.moe/rpc-registry/


registry :
用于服务端注册服务 客户端发现服务

server   :  将服务信息注册到注册中心 提供后台服务

client : 从注册中心获取远程服务注册信息 然后向server发起调用服务
