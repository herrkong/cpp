package main

import (
	"sync"
	"time"
)

// 无缓冲channel
// 无缓冲 channel 在消息发送时需要接收者就绪。声明无缓冲 channel 的方式是不指定缓冲大小
// 发送方和接收方都处于就绪状态
//  发送方会阻塞到接收方接收发送的值
func main() {
	c := make(chan string)

	wg := sync.WaitGroup{}
	wg.Add(2)

	go func() {
		defer wg.Done()
		c <- `foo`
	}()

	go func() {
		defer wg.Done()

		time.Sleep(time.Second * 1)
		println(`Message: ` + <-c)
	}()

	wg.Wait()

}
