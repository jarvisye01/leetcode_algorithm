package main

import "fmt"

func search(nums []int, target int) int {
    N := len(nums)
    if N == 0 {
        return -1
    }

    l, h := 0, N -1
    for l <= h {
        mid := l + (h - l) / 2
        if nums[mid] == target {
            return mid
        }

        if nums[0] <= nums[mid] {
            if nums[0] <= target && nums[mid] > target {
                h = mid - 1
            } else {
                l = mid + 1
            }
        } else {
            if nums[mid] < target && nums[N - 1] >= target {
                l = mid + 1
            } else {
                h = mid - 1
            }
        }
    }
    return -1
}

func main() {
    arr := []int{3, 1}
    res := search(arr, 1)
    fmt.Println(res)
}
