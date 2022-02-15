package main

import (
	"fmt"
	"sync"
	"time"
)

var (
	start        int64 = 0
	length       int64 = 10
	total_length int64 = 100000
	mutex        sync.Mutex
)

//多协程下载文件

func DownloadNetworkFile(File []int) (totalFile []int, err error) {

	timer := time.NewTicker(time.Second)

	wg := sync.WaitGroup{}
	wg.Add(8)
	for i := 0; i < 8; i++ {
		go func() {
			mutex.Lock()
			partFile, _ := downloadNetworkFile(File, start, length)
			if len(partFile) > 0 {
				start = start + length
			}
			totalFile = append(totalFile, partFile...)
			mutex.Unlock()
			wg.Done()
		}()
	}
	wg.Wait()

	go func() {
		for {
			select {
			case <-timer.C:
				fmt.Printf("current start = %d\n", start)
			}
		}
	}()

	time.Sleep(time.Minute)

	return totalFile, nil
}

func downloadNetworkFile(File []int, start int64, length int64) (partFile []int, err error) {
	end := start + length
	if start+length > total_length {
		end = total_length
	}
	partFile = File[start:end]
	return partFile, nil
}

func main() {
	totalFile := make([]int, 10000)
	for i := 0; i < 10000; i++ {
		totalFile[i] = i
	}
	tf, err := DownloadNetworkFile(totalFile)
	if err != nil {
		fmt.Println(err)
	}
	fmt.Printf("len file = %d\n", len(tf))
}
