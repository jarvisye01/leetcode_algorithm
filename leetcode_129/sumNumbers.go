package main

import "fmt"

type TreeNode struct {
    Val int
    Left *TreeNode
    Right *TreeNode
}

func dfs(r *TreeNode, cur int, res *int) {
    if r == nil {
        return
    }
    if r.Left == nil && r.Right == nil {
        *res += cur * 10 + r.Val
        return
    }

    if r.Left != nil {
        dfs(r.Left, cur * 10 + r.Val, res)
    }
    if r.Right != nil {
        dfs(r.Right, cur * 10 + r.Val, res)
    }
}

func sumNumbers(root *TreeNode) int {
    res := 0
    dfs(root, 0, &res)
    return res
}

func main() {
    //r1 := &TreeNode{1, nil, nil}
    //r2 := &TreeNode{2, nil, nil}
    //r3 := &TreeNode{3, nil, nil}
    //r1.Left, r1.Right = r2, r3

    r1 := &TreeNode{0, nil, nil}
    r2 := &TreeNode{2, nil, nil}
    r1.Left = r2

    fmt.Println(sumNumbers(r1))
}
