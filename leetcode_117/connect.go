package main

import "fmt"

type Queue interface {
    AddToTail(x interface{})
    RemoveFromTail() interface{}
    AddToHead(x interface{})
    RemoveFromHead() interface{}
    Size() int
}

type qNode struct {
    val interface{}
    pre *qNode
    next *qNode
}

type listQueue struct {
    length int
    head *qNode
    tail *qNode
}

func (lq *listQueue) AddToTail(x interface{}) {
    t := lq.tail
    newNode := &qNode{val: x}
    if t == nil {
        lq.tail = newNode
        lq.head = lq.tail
    } else {
        t.next = newNode
        newNode.pre = t
        lq.tail = newNode
    }
    lq.length++
}

func (lq *listQueue) RemoveFromHead() interface{} {
    x := lq.head
    lq.head = x.next
    if lq.head == nil {
        lq.tail = nil
        lq.length--
        return x
    }
    lq.head.pre = nil
    lq.length--
    return x
}

func (lq *listQueue) AddToHead(x interface{}) {
    h := lq.head
    newNode := &qNode{val: x}
    if h == nil {
        lq.head = newNode
        lq.tail = lq.head
    } else {
        h.pre = newNode
        newNode.next = h
        lq.head = newNode
    }
    lq.length++
}

func (lq *listQueue) RemoveFromTail() interface{} {
    x := lq.tail
    lq.tail = x.pre
    if lq.tail == nil {
        lq.head = nil
        lq.length--
        return x
    }
    lq.tail.next = nil
    lq.length--
    return x
}

func (lq *listQueue) Size() int {
    return lq.length
}

func GetQueue() Queue {
    return &listQueue{}
}

type Node struct {
    Val int
    Left *Node
    Right *Node
    Next *Node
}

func connect(root *Node) *Node {
    if root == nil {
        return root
    }
    q := GetQueue()
    q.AddToTail(root)
    for q.Size() > 0 {
        l := q.Size()
        h := q.RemoveFromHead().(*qNode).val.(*Node)
        if h.Left != nil {
            q.AddToTail(h.Left)
        }
        if h.Right != nil {
            q.AddToTail(h.Right)
        }
        for i := 0; i < l - 1; i++ {
            t := q.RemoveFromHead().(*qNode).val.(*Node)
            if t.Left != nil {
                q.AddToTail(t.Left)
            }
            if t.Right != nil {
                q.AddToTail(t.Right)
            }
            h.Next = t
            h = t
        }
    }
    return root
}

func main() {
    r0 := &Node{0, nil, nil, nil}
    r1 := &Node{1, nil, nil, nil}
    r2 := &Node{2, nil, nil, nil}
    r3 := &Node{3, nil, nil, nil}
    r4 := &Node{4, nil, nil, nil}
    r5 := &Node{5, nil, nil, nil}
    r6 := &Node{6, nil, nil, nil}
    r0.Left = r1
    r0.Right = r2
    r1.Left = r3
    r1.Right = r4
    r2.Left = r5
    r2.Right = r6
    root := connect(r0)
    fmt.Println(root)
}