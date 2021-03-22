package main

//Definition for a binary tree node.
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func inorderT(r *TreeNode, res *[]int) {
	if r == nil {
		return
	}
	inorderT(r.Left, res)
	*res = append(*res, r.Val)
	inorderT(r.Right, res)
}

func inorderTraversal(root *TreeNode) []int {
	res := make([]int, 0)
	inorderT(root, &res)
	return res
}
