package main

import "fmt"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func generate(start int, end int, m [][]int) int {
	if end < start {
		return 0
	}
	if m[start][end] != 0 {
		return m[start][end]
	}
	if start == end {
		m[start][end] = 1
		return m[start][end]
	}
	children := 0
	for cur := start; cur <= end; cur++ {
		lefts := generate(start, cur - 1, m)
		rights := generate(cur + 1, end, m)
		if lefts > 0 && rights > 0 {
			children += lefts * rights
		} else if lefts > 0 {
			children += lefts
		} else if rights > 0 {
			children += rights
		} else {
			children += 1
		}

	}
	m[start][end] = children
	return m[start][end]
}

func numTrees(n int) int {
	memory := make([][]int, n + 1, n + 1)
	for i := 0; i < n + 1; i++ {
		memory[i] = make([]int, n + 1)
	}
	return generate(1, n, memory)
}

func main() {
	for i := 0; i < 20; i++ {
		fmt.Println(numTrees(30))
	}
}
