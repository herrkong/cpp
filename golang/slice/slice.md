

##### golang 切片的底层数据结构

##### 封装数组

go源码 runtime模块

type slice struct {
	array unsafe.Pointer
	len   int
	cap   int
}



