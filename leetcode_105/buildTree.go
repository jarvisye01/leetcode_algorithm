package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func myBuild(pre []int, in []int) *TreeNode {
	if len(pre) == 0 {
		return nil
	}
	N := len(pre)
	r := pre[0]
	pr := 0
	for i := 0; i < N; i++ {
		if in[i] == r {
			pr = i
		}
	}
	root := &TreeNode{r, nil, nil}
	root.Left = myBuild(pre[1 : pr + 1], in[ : pr])
	root.Right = myBuild(pre[pr + 1 : ], in[pr + 1 : ])
	return root
}

func buildTree(preorder []int, inorder []int) *TreeNode {
	return myBuild(preorder, inorder)
}

func main() {

}
