package main

import "fmt"

func findDuplicate(nums []int) int {
    i := 0
    for i < len(nums) {
        for nums[i] != i + 1 {
            if nums[nums[i] - 1] == nums[i] {
                return nums[i]
            }
            nums[i], nums[nums[i] - 1] = nums[nums[i] - 1], nums[i]
        }
        i++
    }
    return -1
}

func main() {
    arr := []int{2,5,9,6,9,3,8,9,7,1}
    res := findDuplicate(arr)
    fmt.Println(res)
}
