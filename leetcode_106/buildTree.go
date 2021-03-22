package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func myBuild(in []int, pos []int) *TreeNode {
	if len(pos) == 0 {
		return nil
	}
	N := len(pos)
	r := pos[N - 1]
	pr := 0
	for i := N - 1; i >= 0; i-- {
		if in[i] == r {
			pr = i
		}
	}
	root := &TreeNode{r, nil, nil}
	root.Left = myBuild(in[ : pr], pos[ : pr], )
	root.Right = myBuild(in[pr + 1 : ], pos[pr : N - 1])
	return root
}

func buildTree(inorder []int, postorder []int) *TreeNode {
	return myBuild(inorder, postorder)
}

func main() {

}
