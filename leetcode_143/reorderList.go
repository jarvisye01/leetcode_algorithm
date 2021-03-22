package main

type ListNode struct {
    Val int
    Next *ListNode
}

func reorderList(head *ListNode) {
    if head == nil || head.Next == nil {
        return
    }
    lists := []*ListNode{}
    h := head
    for h != nil {
        lists = append(lists, h)
        h = h.Next
    }

    i := 0
    mid := len(lists) / 2
    j := len(lists) - 1
    var last *ListNode
    for i < mid {
        lists[i].Next = lists[j]
        lists[j].Next = nil
        if last != nil {
            last.Next = lists[i]
        }
        last = lists[j]
        i++
        j--
    }
    if len(lists) % 2 == 1 {
        last.Next = lists[mid]
        lists[mid].Next = nil
    }
}

func main() {
}
