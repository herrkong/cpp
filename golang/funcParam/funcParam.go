package main

import "fmt"

// 传入切片 会改变其值
func Change(a []int) {
	a[0] = 1

}

// 传入数组 只是拷贝 不会改变其值
func Change1(a [3]int) {
	a[0] = 1

}

func main() {
	a := []int{9, 8, 7}
	b := [3]int{9, 8, 7}

	Change(a)
	fmt.Println(a)

	Change1(b)
	fmt.Println(b)

}
