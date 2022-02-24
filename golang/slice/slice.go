package main

import (
	"fmt"
)

func printslice(s []int) {
	for i, _ := range s {
		fmt.Printf("d=%d,addr=%p\n", s[i], &s[i])
	}
}

// func main() {
// 	s := []int{1, 2, 3}
// 	printslice(s)
// }
