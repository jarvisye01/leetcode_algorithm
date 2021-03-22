package main

import (
	"fmt"
)

func getMaxFloor(height []int) int {
	max := -1
	for i := 0; i< len(height); i++ {
		if height[i] > max {
			max = height[i]
		}
	}
	return max
}

//这种逐层计算的方法是不需要额外的内存的
//使用动态规划应该可以换取更快的时间
func trap(height []int) int {
	N := len(height)
	floor := 1
	water := 0
	maxF := getMaxFloor(height)
	for floor <= maxF {
		left := 0
		right := N - 1
		for height[left] < floor && left <= right {
			left++
		}
		for height[right] < floor && right >= left {
			right--
		}
		if left == right {
			break
		}
		water += right - left - 1
		for i := left + 1; i < right; i++ {
			if height[i] >= floor {
				water--
			}
		}
		floor++
	}
	return water
}

//Dynamic programing
//func trap(height []int) int {
//	return 0
//}

func getMin(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func myTrap(height []int) int {
	if len(height) < 3 {
		return 0
	}

	left_height := make([]int, len(height))
	right_height := make([]int, len(height))
	left_height[0] = height[0]
	right_height[len(height) - 1] = height[len(height) - 1]
	l, r := left_height[0], right_height[len(height) - 1]
	for i := 0; i < len(height); i++ {
		if height[i] > l {
			l = height[i]
		}
		if height[len(height) - 1 - i] > r {
			r = height[len(height) - 1 - i]
		}

		left_height[i], right_height[len(height) - 1 - i] = l, r
	}

	res := 0
	for i := 0; i < len(height); i++ {
		res += getMin(left_height[i], right_height[i]) - height[i]
	}
	return res
}

func main() {
	arr := []int{0,1,0,2,1,0,1,3,2,1,2,1}
	fmt.Println(trap(arr))
	fmt.Println(myTrap(arr))
}
