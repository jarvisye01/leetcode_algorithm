package main

import "fmt"

func sortColors(nums []int) {
	N := len(nums)
	zero := 0
	one := 0
	for i := 0; i < N; i++ {
		if nums[i] == 0 {
			zero++
		}
		if nums[i] == 1 {
			one++
		}
	}
	for i := 0; i < N; i++ {
		if i < zero {
			nums[i] = 0
		} else if i < one + zero {
			nums[i] = 1
		} else {
			nums[i] = 2
		}
	}
}

func main() {
	test := []int{1, 0, 0, 0, 2, 2, 1, 1, 1, 2, 0, 0, 0}
	fmt.Println(test)
	sortColors(test)
	fmt.Println(test)
}
