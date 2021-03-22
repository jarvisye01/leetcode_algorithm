package main

import "sort"

// threeSum：首先确定的标头不能重复，后续的满足之后的left与right也不能重复
func threeSum(nums []int) [][]int {
    target := 0
    res := make([][]int, 0)
    if len(nums) < 3 {
        return res
    }

    sort.Ints(nums)

    i := 0
    for i < len(nums) - 2 {
        for i > 0 && i < len(nums) - 2 && nums[i] == nums[i - 1] {
            i++
        }

        left, right := i + 1, len(nums) - 1

        for left < right {
            t := nums[i] + nums[left] + nums[right]
            if t == target {
                res = append(res, []int{nums[i], nums[left], nums[right]})
                left++
                right--
                for left < len(nums) && nums[left] == nums[left - 1] {
                    left++
                }
                for right > 0 && nums[right] == nums[right + 1] {
                    right--
                }
            } else if t < target {
                left++
            } else {
                right--
            }
        }
        i++
    }
    return res
}
