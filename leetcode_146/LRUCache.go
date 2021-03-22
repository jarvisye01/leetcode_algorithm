package main

import "fmt"

type LRUCache struct {
	l   *list
	m   map[int]*Element
	cap int
}

func Constructor(capacity int) LRUCache {
	return LRUCache{
		l: &list{
			h: nil,
			t: nil,
		},
		m:   map[int]*Element{},
		cap: capacity,
	}
}

func (this *LRUCache) Get(key int) int {
	if v, ok := this.m[key]; ok {
	    this.l.mov2first(v)
		return v.v
	}
	return -1

}

func (this *LRUCache) Put(key int, value int) {
	if e, ok := this.m[key]; ok {
		e.v = value
		this.l.mov2first(e)
	} else {
		newElement := &Element{
			k:    key,
			v:    value,
			pre:  nil,
			next: nil,
		}
		if this.size() == this.cap {
			// 删除最长未使用的节点
			d := this.l.t
			this.l.del(d)
			delete(this.m, d.k)
            this.m[key] = newElement
            this.l.add2first(newElement)
		} else {
			this.m[key] = newElement
			this.l.add2first(newElement)
		}
	}
}

func (lru *LRUCache) size() int {
	return len(lru.m)
}

type Element struct {
	k    int
	v    int
	pre  *Element
	next *Element
}

type list struct {
	h *Element
	t *Element
}

func (l *list) del(e *Element) {
	if l.h == l.t {
		l.h = nil
		l.t = nil
		return
	}
	if l.h == e {
		l.h = l.h.next
		l.h.pre = nil
	} else if l.t == e {
		l.t = l.t.pre
		l.t.next = nil
	} else {
		e.next.pre = e.pre
		e.pre.next = e.next
	}
	e.pre = nil
	e.next = nil
}

func (l *list) add2first(e *Element) {
    if l.h == nil {
        l.h = e
        l.t = e
        return
    }
	e.next = l.h
    l.h.pre = e
	l.h = e
}

func (l *list) add2tail(e *Element) {
	if l.t == nil {
		l.t = e
		l.h = e
		return
	}
	l.t.next = e
	e.pre = l.t
	l.t = e
}

func (l *list) mov2first(e *Element) {
	if l.h == e {
		return
	}
	l.del(e)
	l.add2first(e)
}

func main() {
    lru := Constructor(1)
    //lru.Put(1, 1)
    //lru.Put(2, 2)
    //lru.Get(1)
    //lru.Put(3, 3)
    //lru.Get(2)
    //lru.Put(4, 4)
    //lru.Get(1)
    //lru.Get(3)
    //lru.Get(4)
    fmt.Println(lru.Get(1))
    lru.Put(2, 1)
    fmt.Println(lru.Get(2))
    lru.Put(3, 2)
    fmt.Println(lru.Get(2))
    fmt.Println(lru.Get(3))
    fmt.Println("ok")
}
