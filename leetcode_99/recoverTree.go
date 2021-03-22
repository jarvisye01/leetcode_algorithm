package main

import "fmt"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func findMaxNode(r *TreeNode, t **TreeNode) {
	if *t == nil {
		*t = r
	}
	if r == nil {
		return
	}
	if r.Val > (*t).Val {
		*t = r
	}
	findMaxNode(r.Left, t)
	findMaxNode(r.Right, t)
}

func findMinNode(r *TreeNode, t **TreeNode) {
	if *t == nil {
		*t = r
	}
	if r == nil {
		return
	}
	if r.Val < (*t).Val {
		*t = r
	}
	findMinNode(r.Left, t)
	findMinNode(r.Right, t)
}

func change(r1 *TreeNode, r2 *TreeNode) {
	t := r1.Val
	r1.Val = r2.Val
	r2.Val = t
}

func recover(root *TreeNode) {
	var min *TreeNode
	var max *TreeNode
	findMaxNode(root.Left, &max)
	findMinNode(root.Right, &min)

	if min == nil && max == nil {
		return
	}

	if min != nil && max != nil {
		if max.Val > root.Val && min.Val < root.Val {
			change(max, min)
		}
		if max.Val > root.Val || min.Val < root.Val {
			if max.Val > root.Val {
				change(max, root)
			}
			if min.Val < root.Val {
				change(min, root)
			}
		} else {
			recover(root.Left)
			recover(root.Right)
		}
	} else if min != nil {
		if min.Val < root.Val {
			change(min, root)
		} else {
			recover(root.Right)
		}
	} else {
		if max.Val > root.Val {
			change(max, root)
		} else {
			recover(root.Left)
		}
	}
}

func recoverTree(root *TreeNode)  {
	recover(root)
}

func main() {
	t1 := &TreeNode{5, nil, nil}
	t2 := &TreeNode{3, nil, nil}
	t3 := &TreeNode{9, nil, nil}
	t4 := &TreeNode{-12312, nil, nil}
	t5 := &TreeNode{2, nil, nil}
	t1.Left = t2
	t1.Right = t3
	t2.Left = t4
	t2.Right = t5
	recoverTree(t1)

	var min *TreeNode
	var max *TreeNode
	findMaxNode(t1, &max)
	findMinNode(t1, &min)
	fmt.Println(max.Val)
	fmt.Println(min.Val)
}
