package main

import "fmt"

func getLeftIndex(nums []int, target int) int {
    N := len(nums)
    if N == 0 || nums[0] > target || nums[N - 1] < target {
        return -1
    }
    l, h := 0, N - 1
    for l < h {
        mid := l + (h - l) / 2
        if nums[mid] >= target {
            h = mid
        } else {
            l = mid + 1
        }
    }
    return l
}

func getRightIndex(nums []int, target int) int {
    N := len(nums)
    if N == 0 || nums[0] > target || nums[N - 1] < target {
        return -1
    }
    l, h := 0, N - 1
    for l < h {
        mid := h - (h - l) / 2
        if nums[mid] <= target {
            l = mid
        } else {
            h = mid - 1
        }
    }
    return h
}

func searchRange(nums []int, target int) []int {
    l := getLeftIndex(nums, target)

    r := getRightIndex(nums, target)
    return []int{l, r}
}

func main() {
    arr := []int{5,7,7,8,8,10}
    res := searchRange(arr, 8)
    fmt.Println(res)
}
