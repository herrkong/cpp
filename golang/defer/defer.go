package main

import (
	"fmt"
	"time"
)

// 定时1s dotask   打印

func doPullTask()(){
	fmt.Println("pull task")
}

func doPushTask()(){
	fmt.Println("push task")
}

func main(){
	defer func(){
		if err := recover(); err != nil{
			fmt.Println(err)
		}
	}()
	exit := make(chan int)
	pullTimer := time.NewTicker(1 * time.Second)
	defer pullTimer.Stop()
	pushTimer := time.NewTicker(2 * time.Second)
	defer pushTimer.Stop()
	
	go func(){
		for{
			select 	{
			case <-pushTimer.C:
				doPushTask()
			case <-pullTimer.C:
				doPullTask()
			}
		}
	}()

	<-exit

}