

#### defer panic recover

defer func(){
    if err := recover();err!= nil{
        log.Error(err)
    }
}()

defer 执行顺序类似于压栈 先进后出 函数返回前调用

panic(value) --> 被recover捕获 value




####  数组和切片 函数传参的问题
传入切片 会改变切片本身的值
传入数组 是值拷贝  不会改变数组本身


#### map 的key chan struct 这些都不能作为key  
只有基本数据