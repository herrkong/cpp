#### gameserver
login hall

login room 

游戏服务器架构 
https://cloud.tencent.com/developer/article/1164990


登陆服务器 --> 大厅服务器 --> 房间服务器

登陆服务器 LoginServer 负载均衡  将不同的玩家连接到不同的大厅服务器HallServer 登陆服务器拿到对应的大厅信息返回给客户端 客户端根据信息连接大厅服务器。
同时Client和LoginServer的连接要断开 

玩家A通过登陆服务器1连接到登陆服务器，登陆服务器开始为当前玩家在众多的大厅服务器中根据哪一个大厅服务器人数比较少来选择一个大厅，
同时把这个大厅的连接IP和端口发给客户端，客户端收到这个IP和端口信息后，根据这个信息连接到此大厅，
同时，客户端断开与登陆服务器之间的连接，这便是用户登陆过程中，在登陆服务器这一块的处理流程。

HallServer  大厅服务器 有多个HallServer大厅服务器 
玩家在大厅界面 选择相应的玩法  进入该玩法的房间列表 列表上显示该类房间(高中低级场)在玩人数

进入相应房间RoomServer 执行具体的玩法逻辑 RoomServer中有几个定时器 比如发牌 结算等定时器 执行游戏流程



roomserver 房间服务器 不同玩法
moneyserver
logserver
proxyserver 转发服务器

roomserverceme 

两类 
通用游戏房间逻辑
游戏玩法逻辑

ConfigManager配置模块 
GameTable牌桌类
GameSeat 座位类
GameUser 玩家类
ProxyServer  转发模块  (将金币变动 转发给MoneyServer  牌局信息转发给 LogServer)
DbServer  db
RedisServer  redis缓存
RobotServer  请求Ai机器人进入房间


https://www.jianshu.com/p/82a81a220722




#### 游戏设计原理和方法
https://www.zhihu.com/column/dongliangqi

#### 手游app的分类
棋牌(大富翁) moba 射击  养成经营 策略 体育(fifa)
#### moba 游戏
multiplayer online Battle Arena Games
多人实时在线游戏

mmorpg 多人在线角色扮演

#### slg游戏
Simulation  Game  
模拟仿真类游戏 涉及策略 养成 经营 
三国

实时pvp在线对战  player vs player 

##### elo机制


#### 游戏服务器架构  