package main

import "fmt"

type ListNode struct {
    Val int
    Next *ListNode
}

func getMid(head *ListNode) *ListNode {
    if  head == nil || head.Next == nil {
        return head
    }

    slow := head
    fast := head
    for fast.Next != nil {
        fast = fast.Next.Next
        if fast == nil {
            break
        }
        slow = slow.Next
        if fast.Next == nil {
            break
        }
    }
    return slow
}

func merge(h1 *ListNode, h2 *ListNode) *ListNode {
    vNode := &ListNode{}
    t := vNode
    for h1 != nil && h2 != nil {
        if h1.Val < h2.Val {
            t.Next = h1
            h1 = h1.Next
        } else {
            t.Next = h2
            h2 = h2.Next
        }
        t = t.Next
        t.Next = nil
    }
    if h1 != nil {
        t.Next = h1
    }
    if h2 != nil {
        t.Next = h2
    }
    return vNode.Next
}

func sortList(head *ListNode) *ListNode {
    if head == nil || head.Next == nil {
        return head
    }

    mid := getMid(head)
    h1, h2 := head, mid.Next
    mid.Next = nil

    t1 := sortList(h1)
    t2 := sortList(h2)
    res := merge(t1, t2)

    return res
}

func main() {
    l1 := &ListNode{4, nil}
    l2 := &ListNode{3, nil}
    l3 := &ListNode{2, nil}
    l4 := &ListNode{1, nil}

    l1.Next, l2.Next, l3.Next = l2, l3, l4

    t := sortList(l1)
    for t != nil {
        fmt.Printf("%d ", t.Val)
        t = t.Next
    }
    fmt.Println()
}
