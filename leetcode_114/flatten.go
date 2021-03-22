package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func orderScan(r *TreeNode) (*TreeNode, *TreeNode) {
	if r == nil {
		return nil, nil
	}

	h1, t1 := orderScan(r.Left)
	h2, t2 := orderScan(r.Right)
	r.Left = nil
	if h1 != nil && h2 != nil {
		r.Right = h1
		t1.Right = h2
		return r, t2
	} else if h1 != nil {
		r.Right = h1
		return r, t1
	} else if h2 != nil {
		r.Right = h2
		return r, t2
	}
	return r, r
}

func flatten(root *TreeNode) {
	root, _ = orderScan(root)
}

func main() {

}
