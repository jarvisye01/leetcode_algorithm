package main

import "fmt"

type MinStack struct {
    arr []int
    mval []int
    sz int
    msz int
}


/** initialize your data structure here. */
func Constructor() MinStack {
    return MinStack{
        arr:   make([]int, 8),
        mval: make([]int, 8),
        sz:   0,
        msz:  0,
    }
}

func (this *MinStack) resize(cap int) {
    c1 := make([]int, cap)
    c2 := make([]int, cap)

    for i := 0; i < this.sz; i++ {
        c1[i] = this.arr[i]
    }

    for i := 0; i < this.msz; i++ {
        c2[i] = this.mval[i]
    }

    this.arr, this.mval = c1, c2
}

func (this *MinStack) Push(x int)  {
    if this.sz == len(this.arr) {
        this.resize(2 * len(this.arr))
    }
    this.arr[this.sz] = x
    this.sz++
    if this.msz == 0 || x <= this.GetMin() {
        this.mval[this.msz] = x
        this.msz++
    }
}


func (this *MinStack) Pop()  {
    this.sz--
    x := this.arr[this.sz]
    if x == this.GetMin() {
        this.msz--
    }
}


func (this *MinStack) Top() int {
    x := this.arr[this.sz - 1]
    return x
}


func (this *MinStack) GetMin() int {
    m := this.mval[this.msz - 1]
    return m
}

func main() {
    s := Constructor()

    arr := []int{4, 5, 6, 2, 1, 3, 0}
    for i := 0; i < len(arr); i++ {
        s.Push(arr[i])
        fmt.Println(s.GetMin())
    }

    fmt.Println("---------------------")
    for s.sz > 0 {
        fmt.Println(s.GetMin())
        s.Pop()
    }
}
