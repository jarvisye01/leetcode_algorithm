package main

import "fmt"

//Definition for singly-linked list.
type ListNode struct {
 	Val int
 	Next *ListNode
}

func rotateRight(head *ListNode, k int) *ListNode {
	if head == nil {
		return head
	}
	th := head;
	var tail *ListNode
	//链表的长度
	N := 0
	for th != nil {
		N++
		if th.Next == nil {
			tail = th
		}
		th = th.Next
	}
	th = head
	var res *ListNode
	move := k % N
	if move == 0 {
		return head
	}
	for i := 0; i < N - 1 - move; i++ {
		head = head.Next
	}
	res = head.Next
	head.Next = nil
	tail.Next = th
	return res
}

func main() {
	l1 := &ListNode{1, nil}
	l2 := &ListNode{2, nil}
	l3 := &ListNode{3, nil}
	//l4 := &ListNode{4, nil}
	//l5 := &ListNode{5, nil}
	l1.Next = l2
	l2.Next = l3
	//l3.Next = l4
	//l4.Next = l5

	t := rotateRight(l1, 6)

	for t != nil {
		fmt.Println(t.Val)
		t = t.Next
	}
}
