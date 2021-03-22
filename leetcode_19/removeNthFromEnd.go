package main

type ListNode struct {
    Val int
    Next *ListNode
}

func getNFromEnd(head *ListNode, n int) *ListNode {
    slow := head
    fast := head
    for i := 0; i < n; i++ {
        if fast == nil {
            return nil
        }
        fast = fast.Next
    }

    for fast != nil {
        slow = slow.Next
        fast = fast.Next
    }

    return slow
}

func removeNthFromEnd(head *ListNode, n int) *ListNode {
    if n == 0 {
        return head
    }
    list := &ListNode{
        Val:  -1,
        Next: nil,
    }
    list.Next = head

    nPlusOne := getNFromEnd(list, n + 1)
    nPlusOne.Next = nPlusOne.Next.Next
    return list.Next
}
