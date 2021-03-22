package main

import "fmt"

func removeDuplicates(nums []int) int {
	N := len(nums)
	i := 0
	j := 0
	total := 0
	for i < N {
		for i < N && nums[i] == nums[j] {
			i++
		}
		if i - j > 1 {
			nums[total] = nums[j]
			nums[total + 1] = nums[j]
			total += 2
		} else {
			nums[total] = nums[j]
			total++
		}
		j = i
	}
	return total
}

func main() {
	t := []int{0,0,1,1,1,1,2,3,3}
	fmt.Println(removeDuplicates(t))
}
