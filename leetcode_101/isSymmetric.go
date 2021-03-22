package main

import "fmt"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func mySymmetric(r1, r2 *TreeNode) bool {
	if r1 == nil && r2 == nil {
		return true
	}
	if r1 == nil || r2 == nil {
		return false
	}
	if r1.Val != r2.Val {
		return false
	}
	return mySymmetric(r1.Left, r2.Right) && mySymmetric(r1.Right, r2.Left)
}

func isSymmetric(root *TreeNode) bool {
	if root == nil {
		return true
	}
	return mySymmetric(root.Left, root.Right)
}

func main() {
	r1 := &TreeNode{1, nil, nil}
	r2 := &TreeNode{2, nil, nil}
	r3 := &TreeNode{2, nil, nil}
	r4 := &TreeNode{3, nil, nil}
	r5 := &TreeNode{3, nil, nil}
	r6 := &TreeNode{4, nil, nil}
	r7 := &TreeNode{4, nil, nil}
	r1.Left = r2
	r1.Right = r3
	r2.Left = r4
	r2.Right = r6
	r3.Left = r7
	r3.Right = r5
	fmt.Println(isSymmetric(r1))
}
