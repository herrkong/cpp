#### channel的底层实现
https://juejin.cn/post/6898132039812431885

type hchan struct {
	qcount   uint // 队列中元素个数
	dataqsiz uint // 循环队列的大小
	buf      unsafe.Pointer // 指向循环队列
	elemsize uint16 // 通道里面的元素大小
	closed   uint32 // 通道关闭的标志
	elemtype *_type // 通道元素的类型
	sendx    uint   // 待发送的索引，即循环队列中的队尾指针front
	recvx    uint   // 待读取的索引，即循环队列中的队头指针rear
	recvq    waitq  // 接收等待队列
	sendq    waitq  // 发送等待队列
	lock mutex // 互斥锁
}
