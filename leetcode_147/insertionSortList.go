package main

import "fmt"

type ListNode struct {
    Val int
    Next *ListNode
}

// 1 -> 7 -> 6 -> 4
// 1 -> 7 -> 4
func insertionSortList(head *ListNode) *ListNode {
    if head == nil {
        return nil
    }
    nodes := make([]*ListNode, 0)
    h := head
    for h != nil {
        nodes = append(nodes, h)
        h = h.Next
    }

    for i := 0; i < len(nodes); i++ {
        for j := i; j > 0; j-- {
            if nodes[j].Val >=  nodes[j - 1].Val {
                break
            }
            nodes[j], nodes[j - 1] = nodes[j - 1], nodes[j]
        }
    }

    th := nodes[0]
    for i := 1; i < len(nodes); i++ {
        th.Next = nodes[i]
        th = th.Next
        th.Next = nil
    }
    return nodes[0]
}

// 1 -> 7 -> 6 -> 4
// 1 -> 7 -> 4
func insertionSort(head *ListNode) *ListNode {
    if head == nil || head.Next == nil {
        return head
    }
    h := head
    for h.Next != nil {
        t := h.Next
        if h.Val > t.Val {
            h.Next = t.Next
            th := head
            if t.Val <= th.Val {
                t.Next = th
                head = t
            } else {
                for th != h {
                    if t.Val <= th.Next.Val {
                        t.Next = th.Next
                        th.Next = t
                        break
                    }
                    th = th.Next
                }
            }
        } else {
            h = h.Next
        }
    }
    return head
}

func main() {
    node1 := &ListNode{
        Val:  4,
        Next: nil,
    }
    node2 := &ListNode{
        Val:  2,
        Next: nil,
    }
    node3 := &ListNode{
        Val:  1,
        Next: nil,
    }
    node4 := &ListNode{
        Val:  3,
        Next: nil,
    }

    node1.Next, node2.Next, node3.Next = node2, node3, node4
    insertionSort(node1)
    fmt.Println(node1.Val, node2.Val, node3.Val, node4.Val)
}
