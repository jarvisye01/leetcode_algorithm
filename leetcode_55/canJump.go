package main

import "fmt"

//dfs会消耗太多的时间
func dfs(nums []int, cur int, jpL int) bool {
	if jpL == len(nums) - 1 {
		return true
	}
	for i := nums[cur]; i >= 1; i-- {
		if(dfs(nums, cur + i, jpL + i)) {
			return true
		}
	}
	return false
}

//实际上，我们只需要看能否越过数组中的每一个0即可
func check(nums []int) bool {
	maxJ := 0
	for i := 0; i < len(nums); i++ {
		if nums[i] > maxJ {
			maxJ = nums[i]
		} else if nums[i] == maxJ {
			if nums[i] == 0 {
				if i == len(nums) - 1 {
					return true
				} else {
					return false
				}
			}
		}
		maxJ--
	}
	return true
}

func canJump(nums []int) bool {
	return dfs(nums, 0, 0)
}

func main() {
	a := []int{2, 3, 1, 1, 4}
	fmt.Println(check(a))
}
