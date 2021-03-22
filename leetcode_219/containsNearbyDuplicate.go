package main

import "fmt"

func containsNearbyDuplicate(nums []int, k int) bool {
	m := make(map[int]int)
	for idx, v := range nums {
		if lastIdx, ok := m[v]; ok {
			if idx-lastIdx <= k {
				return true
			}
		}
		m[v] = idx
	}
	return false
}

func main() {
	arr := []int{1, 2, 3, 1}
	k := 2
	fmt.Println(containsNearbyDuplicate(arr, k))
}
