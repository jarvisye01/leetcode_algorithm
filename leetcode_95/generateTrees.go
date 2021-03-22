package main

import "fmt"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func generate(start int, end int) []*TreeNode {
	if end < start {
		return []*TreeNode{}
	}
	if start == end {
		return []*TreeNode{&TreeNode{start, nil, nil}}
	}
	children := make([]*TreeNode, 0)
	for cur := start; cur <= end; cur++ {
		lefts := generate(start, cur - 1)
		rights := generate(cur + 1, end)
		if len(lefts) > 0 && len(rights) > 0 {
			for i := 0; i < len(lefts); i++ {
				for  j := 0; j < len(rights); j++ {
					tr := &TreeNode{cur, lefts[i], rights[j]}
					children = append(children, tr)
				}
			}
		} else if len(lefts) > 0 {
			for i := 0; i < len(lefts); i++ {
				tr := &TreeNode{cur, lefts[i], nil}
				children = append(children, tr)
			}
		} else if len(rights) > 0 {
			for  j := 0; j < len(rights); j++ {
				tr := &TreeNode{cur, nil, rights[j]}
				children = append(children, tr)
			}
		} else {
			tr := &TreeNode{cur, nil, nil}
			children = append(children, tr)
		}

	}
	return children
}

func generateTrees(n int) []*TreeNode {
	return generate(1, n)
}

func main() {
	test := generateTrees(10)
	fmt.Println(test)
}
