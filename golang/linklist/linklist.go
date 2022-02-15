package main

import "fmt"

// go 实现翻转链表

type Node struct {
	Value int
	Next  *Node
}

func ReverseLinkList(head *Node) *Node {
	if head == nil || head.Next == nil {
		return head
	}
	tmp := head
	var cur *Node = nil
	for tmp.Next != nil {
		t := tmp.Next
		tmp.Next = cur
		cur = tmp
		tmp = t
	}
	return cur
}

//尾插法初始化链表
func InitLinkList(head *Node) *Node {
	if head == nil || head.Next == nil {
		head.Value = 1
		head.Next = nil
	}

	tmp := head

	for i := 2; i < 5; i++ {
		node := new(Node)
		node.Value = i
		node.Next = nil
		tmp.Next = node
		tmp = node
	}

	tmp.Next = nil

	return head
}

func PrintLinkList(head *Node) {
	for head != nil {
		fmt.Printf("%d,", head.Value)
		head = head.Next
	}
}

func main() {
	head := new(Node)
	head = InitLinkList(head)
	PrintLinkList(head)
	head = ReverseLinkList(head)
	fmt.Println("\nafter reverse:")
	PrintLinkList(head)
}
