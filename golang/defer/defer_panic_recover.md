#### defer panic recover

defer func(){
    if err := recover();err!= nil{
        log.Error(err)
    }
}()

defer 执行顺序类似于压栈 先进后出 函数返回前调用

panic(value) --> 被recover捕获 value