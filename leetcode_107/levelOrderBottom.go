package main

import "container/list"

type TreeNode struct {
    Val int
    Left *TreeNode
    Right *TreeNode
}

func levelOrderBottom(root *TreeNode) [][]int {
    res := make([][]int, 0)
    q := list.New()
    if root != nil {
        q.PushBack(root)
    }
    for q.Len() > 0 {
        l := q.Len()
        data := make([]int, 0)
        for i := 0; i < l; i++ {
            e := q.Front()
            r := e.Value.(*TreeNode)
            q.Remove(e)
            if r.Left != nil {
                q.PushBack(r.Left)
            }
            if r.Right != nil {
                q.PushBack(r.Right)
            }
            data = append(data, r.Val)
        }
        res = append([][]int{data}, res...)
    }
    return res
}

func main() {

}
