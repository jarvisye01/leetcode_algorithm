package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func getMin(root *TreeNode) int {
	if root.Left == nil {
		return root.Val
	}
	return getMin(root.Left)
}

func getMax(root *TreeNode) int {
	if root.Right == nil {
		return root.Val
	}
	return getMax(root.Right)
}

func isValidBST(root *TreeNode) bool {
	if root == nil {
		return true
	}
	if isValidBST(root.Left) && isValidBST(root.Right) {
		if root.Left != nil {
			if root.Val < root.Left.Val || getMax(root.Left) >= root.Val {
				return false
			}
		}
		if root.Right != nil {
			if root.Val > root.Right.Val || getMin(root.Right) <= root.Val {
				return false
			}
		}
		return true
	}
	return false
}
