package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func getMax(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func maxDepth(root *TreeNode) int {
	if root == nil {
		return 0
	}
	depthL := maxDepth(root.Left)
	depthR := maxDepth(root.Right)
	return getMax(depthL, depthR) + 1
}

func main() {

}
