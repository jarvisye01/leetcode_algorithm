package main

//* Definition for singly-linked list.
type ListNode struct {
	Val int
	Next *ListNode
}

//总结，当你找不到头结点的时候
//可以新建一个虚拟的头结点
func deleteDuplicates(head *ListNode) *ListNode {
	th := &ListNode{0, nil}
	t := th
	back := head
	front := head

	for front != nil {
		for front != nil && front.Val == back.Val {
			front = front.Next
		}
		if back.Next == front {
			t.Next = back
			t = back
			t.Next = nil
		}
		back = front
	}
	return th.Next
}