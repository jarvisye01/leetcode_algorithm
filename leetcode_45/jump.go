package main

import "fmt"

func jump(nums []int) int {
	//MAX := 1 << 31
	N := len(nums)
	dp := make([]int, N, N)
	dp[0] = 0
	maxJIndex := 0
	for i := 1; i < N; i++ {
		for k := maxJIndex; k < i; k++ {
			if nums[k] >= i - k {
				dp[i] = dp[k] + 1
				break
			} else {
				maxJIndex = k
			}
		}
	}
	fmt.Println(dp)
	return dp[N - 1]
}

func main() {
	fmt.Println(jump([]int{1, 2, 3, 1, 2, 2, 4, 1, 7, 2}))
}
