package main

import (
	"fmt"
	"sync"
	"time"
)

//https://www.flysnow.org/2017/05/12/go-in-action-go-context.html

// 多个协程同时做同一件事

func main() {
	var wg sync.WaitGroup

	wg.Add(2)
	go func() {
		time.Sleep(2 * time.Second)
		fmt.Println("1号完成")
		wg.Done()
	}()
	go func() {
		time.Sleep(2 * time.Second)
		fmt.Println("2号完成")
		wg.Done()
	}()
	wg.Wait()
	fmt.Println("好了，大家都干完了，放工")
}
