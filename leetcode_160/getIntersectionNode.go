package main

type ListNode struct {
    Val int
    Next *ListNode
}

func getIntersectionNode(headA, headB *ListNode) *ListNode {
    ha, hb := headA, headB
    m := map[*ListNode]bool{}

    var res *ListNode
    for ha != nil {
        m[ha] = true
        ha = ha.Next
    }

    for hb != nil {
        if m[hb] {
            res = hb
            break
        }
        hb = hb.Next
    }
    return res
}

func myGetIntersectionNode(headA, headB *ListNode) *ListNode {
    if headA == nil || headB == nil {
        return nil
    }
    ha, hb := headA, headB

    num := 0
    for ha != hb {
        if ha.Next == nil {
            ha = headB
            num++
        } else {
            ha = ha.Next
        }
        if hb.Next == nil {
            hb = headA
            num++
        } else {
            hb = hb.Next
        }
        if num > 2 {
            return nil
        }
    }

    return ha
}


