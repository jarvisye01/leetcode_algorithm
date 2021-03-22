package main


type ListNode struct {
    Val int
    Next *ListNode
}

func mergeTwoLists(l1 *ListNode, l2 *ListNode) *ListNode {
    th := &ListNode{}
    t := th

    for l1 != nil && l2 != nil {
        if l1.Val <= l2.Val {
            t.Next = l1
            l1 = l1.Next
        } else {
            t.Next = l2
            l2 = l2.Next
        }
        t = t.Next
    }

    if l1 != nil {
        t.Next = l1
    }

    if l2 != nil {
        t.Next = l2
    }

    return th.Next
}

func recursive(lists []*ListNode, l, h int) *ListNode {
    if l > h {
        return nil
    }
    if l == h {
        return lists[l]
    }

    mid := l + (h - l) / 2

    t1 := recursive(lists, l, mid)
    t2 := recursive(lists, mid + 1, h)
    return mergeTwoLists(t1, t2)
}

func mergeKLists(lists []*ListNode) *ListNode {
    return recursive(lists, 0, len(lists) - 1)
}
