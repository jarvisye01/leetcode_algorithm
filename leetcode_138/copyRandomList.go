package main

import "fmt"

type Node struct {
    Val int
    Next *Node
    Random *Node
}

func getCopyNode(node *Node) *Node {
    return &Node{
        Val:    node.Val,
        Next:   nil,
        Random: nil,
    }
}

func copyRandomList(head *Node) *Node {
    if head == nil {
        return head
    }

    m := map[*Node]*Node{}

    th := getCopyNode(head)
    m[head] = th
    if head.Random != nil {
        if m[head.Random] != nil {
            th.Random = m[head.Random]
        } else {
            t := getCopyNode(head.Random)
            m[head.Random] = t
            th.Random = t
        }
    }
    h := head.Next
    tt := th
    for h != nil {
        if m[h] != nil {
            tt.Next = m[h]
        } else {
            tt.Next = getCopyNode(h)
            m[h] = tt.Next
        }
        tt = tt.Next
        if h.Random != nil {
            if m[h.Random] != nil {
                tt.Random = m[h.Random]
            } else {
                tt.Random = getCopyNode(h.Random)
                m[h.Random] = tt.Random
            }
        }
        h = h.Next
    }
    return th
}

func main() {
    nodes := make([]*Node, 5)
    vals := []int{7, 13, 11, 10, 1}
    for i := 0; i < 5; i++ {
        nodes[i] = &Node{Val: vals[i]}
    }

    nodes[0].Next, nodes[0].Random = nodes[1], nil
    nodes[1].Next, nodes[1].Random = nodes[2], nodes[0]
    nodes[2].Next, nodes[2].Random = nodes[3], nodes[4]
    nodes[3].Next, nodes[3].Random = nodes[4], nodes[2]
    nodes[4].Next, nodes[4].Random = nil, nodes[0]

    res := copyRandomList(nodes[0])
    fmt.Println(res.Val)
}
