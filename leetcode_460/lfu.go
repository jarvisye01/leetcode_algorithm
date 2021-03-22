package main
//
//import (
//    "container/heap"
//    "unicode"
//)
//
//type node struct {
//    val interface{}
//    extra interface{}
//    pre *node
//    next *node
//    list *list
//}
//
//type list struct {
//    sz int
//    head *node
//    tail *node
//}
//
//func (l *list) PutBack(n *node) {
//    if l.tail == nil {
//        l.head = n
//        l.tail = n
//        n.list = l
//        return
//    }
//    l.tail.next = n
//    n.pre = l.tail
//    l.tail = n
//    n.list = l
//}
//
//func (l *list) PutHead(n *node) {
//    if l.head == nil {
//        l.head = n
//        l.tail = n
//        n.list = l
//        return
//    }
//    n.next = l.head
//    l.head.pre = n
//    l.head = n
//    n.list = l
//}
//
//func (l *list) RemoveTail() {
//    if l.sz == 0 {
//        return
//    }
//    if l.sz == 1 {
//        l.head, l.tail = nil, nil
//        l.sz--
//    }
//    t := l.tail.pre
//    t.next = nil
//    l.tail = t
//    l.sz--
//}
//
//func (l *list) MoveToHead(n *node) {
//    if l != n.list {
//        return
//    }
//
//    tf, tb := n.pre, n.next
//    if tf != nil {
//        tf.next = tb
//    }
//    if tb != nil {
//        tb.pre = tf
//    }
//
//    if n == l.head {
//        return
//    }
//
//    n.next = l.head
//    l.head = n
//}
//
//func (l *list) insert()
//
//type LFUCache struct {
//    hash map[int]*node
//    list DeQueue
//    sz int
//}
//
//
//func Constructor(capacity int) LFUCache {
//    return LFUCache{
//        hash: map[int]*node{},
//        list: GetDeQueue(),
//        sz:   0,
//    }
//}
//
//
//func (this *LFUCache) Get(key int) int {
//    t, ok := this.hash[key]
//    if !ok {
//        return -1
//    }
//    res, _ := t.val.(int)
//    return res
//}
//
//
//func (this *LFUCache) Put(key int, value int)  {
//
//}
