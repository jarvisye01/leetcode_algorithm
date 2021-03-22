package main

import (
	"fmt"
	"sort"
)

/**
 * 是一个DFS的递归调用，需要考虑剪枝
 * @param 输入的数组
 * @param 保存结果的二维数组
 * @param DFS的路径
 */
func recurse(nums []int, res *[][]int, path []int) {
	N := len(nums)
	m := map[int]bool{}
	for i := 0; i < N; i++ {
		if m[nums[i]] {
			// 不在处理已经出现过的数字
			continue
		} else {
			m[nums[i]] = true
		}
		path = append(path, nums[i])
		t := make([]int, len(path), len(path))
		copy(t, path)
		*res = append(*res, t)
		// nums[i + 1 : ]，走过的路不在回头去走
		recurse(nums[i + 1 : ], res, path)
		path = path[ : len(path) - 1]
	}
}

/**
 * @param nums 输入的数组
 */
func subsetsWithDup(nums []int) [][]int {
	res := make([][]int, 0)
	sort.Ints(nums)
	recurse(nums, &res, []int{})
	// 加入空数组，题目需要
	res = append(res, []int{})
	return res
}

func main() {
	fmt.Println(subsetsWithDup([]int{4, 4, 4, 1, 4}))
}
