package main

import "fmt"

func maxSubArray(nums []int) int {
	N := len(nums)
	tm := nums[0]
	max := tm
	for i := 1; i < N; i++ {
		if tm < 0 {
			tm = nums[i]
		} else {
			tm = tm + nums[i]
		}
		if tm > max {
			max = tm
		}
	}
	return max
}

func main() {
	fmt.Println(maxSubArray([]int{-2,1,-3,4,-1,2,1,-5,4}))
}
