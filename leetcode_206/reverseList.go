package main


//Definition for singly-linked list.
type ListNode struct {
	Val int
	Next *ListNode
}

func recursive(node *ListNode) *ListNode  {
	if node == nil {
		return nil
	}
	if node.Next == nil {
		return node
	}
	t := recursive(node.Next)
	//此时node的next已经是t的最后一个
	node.Next.Next = node
	node.Next = nil
	return t
}

func iterate(head *ListNode) *ListNode {
	if head == nil {
		return nil
	}
	t1 := head
	t2 := head.Next
	t1.Next = nil

	for t2 != nil {
		t := t1
		next := t2.Next
		t1 = t2
		t1.Next = t
		t2 = next
	}
	return t1
}

func reverseList(head *ListNode) *ListNode {
	return recursive(head)
}
