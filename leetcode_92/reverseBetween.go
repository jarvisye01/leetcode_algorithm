package main

 //Definition for singly-linked list.
type ListNode struct {
 	Val int
	Next *ListNode
}

func reverseBetween(head *ListNode, m int, n int) *ListNode {
	v := &ListNode{0, nil}
	th := v
	i := 1
	for head != nil {
		if i == m {
			h := head
			tail := h
			head = head.Next
			h.Next = nil
			for j := i + 1; j <= n; j++ {
				t := head
				head = head.Next
				t.Next = h
				h = t
				i++
			}
			th.Next = h
			th = tail
		} else {
			th.Next = head;
			head = head.Next
			th = th.Next
			th.Next = nil
			i++
		}
	}
	return v.Next
}

func main() {
	l1 := &ListNode{1, nil}
	l2 := &ListNode{2, nil}
	l3 := &ListNode{3, nil}
	l4 := &ListNode{4, nil}
	l5 := &ListNode{5, nil}

	l1.Next = l2
	l2.Next = l3
	l3.Next = l4
	l4.Next = l5

	reverseBetween(l1, 2, 4)
}
