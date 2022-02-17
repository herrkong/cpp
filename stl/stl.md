#### map 删除迭代器失效问题

erase 返回指向被删除元素的下一个元素的迭代器

iter = m.erase(iter)

#### vector map set 的内存分析
vector 占用连续内存
map 内存不连续

set map底层都是平衡二叉树 红黑树 
插入删除效率高 是因为其元素都是以节点形式存储 不需要做内存移动和拷贝

#### map 元素有序

#### set中元素有序唯一

#### unordered_map 无序map 
底层采用hash表存储 

#### 关联容器 顺序容器


#### 对比Golang C++ 在Map Vector(slice)底层实现的差异

stl源码 
c++ 实现stl map vector


golang源码
go实现 slice map sync.map



#### stl的内存是在堆还是栈上

#### 不停的给vector map push_back insert 迭代器会失效吗


