package main

 //* Definition for singly-linked list.

type ListNode struct {
	Val int
	Next *ListNode
}

func partition(head *ListNode, x int) *ListNode {
	f1 := &ListNode{0, nil}
	b1 := f1
	f2 := &ListNode{0, nil}
	b2 := f2
	//f3 := &ListNode{0, nil}
	//b3 := f3

	//这一题关键是要看看题目是不是要求你要精确地排序
	//这是你需不需要一条相等值的链表的前提
	for head != nil {
		t := head
		head = head.Next
		//节点接上去之后要进行尾值处理
		t.Next = nil
		if t.Val < x {
			b1.Next = t;
			b1 = b1.Next;
		} else {
			b2.Next = t;
			b2 = b2.Next;
		}
		//else {
		//	b3.Next = t;
		//	b3 = b3.Next;
		//}
	}
	b1.Next = f2.Next
	//b2.Next = f3.Next
	return f1.Next
}

func main() {

}
