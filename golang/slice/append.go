package main

import "fmt"

// Go 中明确表示没有传引用，所有的函数参数都是传值。而像 map、chan、slice
// 这些引用类型，虽然是传值，但在函数内亦可以修改其值，达到传引用的效果

// 传切片append 未改变切片
// http://www.linvon.cn/posts/go%E5%87%BD%E6%95%B0%E4%B8%AD%E4%BD%BF%E7%94%A8append%E4%BF%AE%E6%94%B9%E4%BC%A0%E5%85%A5%E7%9A%84slice%E4%B8%BA%E4%BD%95%E6%97%A0%E6%95%88/

// 如果切片的当前大小不足以附加新值，那么切片需要动态增长，
// 从而更改了基础数组。如果没有返回此新切片，那么追加的更改是不生效的。
// 切片内存动态增长 需要返回新切片
// 或者使用切片指针
func AppendReturn(s []int) []int {
	s = append(s, 5)
	return s
}

func AppendPointer(s *[]int) {
	*s = append(*s, 5)
}

// 传数组是传的拷贝
func ChangeArray(s [4]int) {
	s[0] = -1
}

// 传切片可改变切片的值
func ChangeSlice(s []int) {
	s[0] = -1
}

// 传切片 可改变其值
func Add(s []int) {
	for i := range s {
		s[i] = s[i] + 5
	}
}

func main() {
	// 这里传切片append
	s := []int{1, 2, 3, 4}
	// s2 := [4]int{1, 2, 3, 4}
	// ChangeArray(s2)
	// ChangeSlice(s)

	// fmt.Println(s2)
	// fmt.Println(s)

	// Append(s)
	// fmt.Println(s)

	s = AppendReturn(s)
	fmt.Println(s)

	// AppendPointer(&s)
	// fmt.Println(s)

	// Add(s)
	// fmt.Println(s)

}
