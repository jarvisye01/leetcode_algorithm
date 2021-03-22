package main

import "fmt"

func dfs(nums []int, cur int, path []int, res *[][]int) {
	if cur == len(nums) {
		return
	}
	for i := cur; i < len(nums); i++ {
		path = append(path, nums[i])
		t := make([]int, len(path))
		copy(t, path)
		*res = append(*res, t)
		dfs(nums, i + 1, path, res)
		path = path[ : len(path) - 1]
	}
	return
}

func subsets(nums []int) [][]int {
	res := make([][]int, 0, 0)
	res = append(res, []int{})
	dfs(nums, 0, []int{}, &res)
	return res
}

func main() {
	fmt.Println("test")
	fmt.Println(subsets([]int{1, 2, 3}))
}