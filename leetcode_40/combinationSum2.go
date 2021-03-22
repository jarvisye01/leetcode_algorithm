package main

import (
	"fmt"
	"sort"
)

func dfs(nums []int, target int, cur int, total int, path []int, res *[][]int) {
	if total > target {
		return
	}

	if total == target {
		t := make([]int, len(path), len(path))
		copy(t, path)
		*res = append(*res, t)
		return
	}

	m := map[int]bool{}
	for i := cur; i < len(nums); i++ {
		if !m[nums[i]] && total + nums[i] <= target {
			m[nums[i]] = true
			path = append(path, nums[i])
			dfs(nums, target, i + 1, total + nums[i], path, res)
			path = path[ : len(path) - 1]
		}
	}
}

func combinationSum2(nums []int, target int) [][]int {
	sort.Ints(nums)
	result := make([][]int, 0, 0)
	dfs(nums, target, 0, 0, []int{}, &result)
	return result
}

func main() {
	fmt.Println(combinationSum2([]int{2, 5, 2, 1, 2}, 5))
	fmt.Println(combinationSum2([]int{10,1,2,7,6,1,5}, 8))
}
