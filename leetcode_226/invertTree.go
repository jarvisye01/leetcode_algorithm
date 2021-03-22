package main

import "fmt"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func invertTreeAux(node *TreeNode) *TreeNode {
	if node == nil || (node.Left == nil && node.Right == nil) {
		return node
	}

	node.Left, node.Right = invertTreeAux(node.Right), invertTreeAux(node.Left)
	return node
}

func invertTree(root *TreeNode) *TreeNode {
	root = invertTreeAux(root)
	return root
}

func print(node *TreeNode) {
	if node == nil {
		return
	}
	print(node.Left)
	fmt.Print(node.Val, " ")
	print(node.Right)
}

func main() {
	r1 := &TreeNode{1, nil, nil}
	r2 := &TreeNode{2, nil, nil}
	r3 := &TreeNode{3, nil, nil}
	r4 := &TreeNode{4, nil, nil}
	r5 := &TreeNode{5, nil, nil}
	r1.Left, r1.Right = r2, r3
	r3.Left, r3.Right = r4, r5
	fmt.Println("Before<<<<<<<<<<<<<<<<<<<<<<<<<")
	print(r1)
	fmt.Println()

	r1 = invertTree(r1)
	fmt.Println("After<<<<<<<<<<<<<<<<<<<<<<<<<<")
	print(r1)
	fmt.Println()
}
