package main

import "fmt"

//4, 2
func c(m, n int) int {
	r := 1
	for i := 1; i <= n; i++ {
		r *= m
		m--
	}
	for i := 1; i <= n; i++ {
		r /= i
	}
	return r
}

func dfs(n int, k int, cur int, depth int, path []int, res *[][]int) {
	if depth == k {
		t := make([]int, len(path))
		copy(t, path)
		*res = append(*res, t)
		return
	}

	for i := cur + 1; i <= n; i++ {
		path = append(path, i)
		dfs(n, k, i, depth + 1, path, res)
		path = path[ : len(path) - 1]
	}
}

func combine(n int, k int) [][]int {
	res := make([][]int, 0, 0)
	dfs(n, k, 0, 0, []int{}, &res)
	return res
}

func main() {
	fmt.Println(c(5, 2))
	t := combine(5, 2)
	fmt.Println(t)
}
