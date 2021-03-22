package main

import "fmt"

func moveZeroes(nums []int) {
    i := 0
    j := 0
    for j < len(nums) {
        if nums[j] != 0 {
            nums[i] = nums[j]
            i++
        }
        j++
    }
    for i < len(nums) {
        nums[i] = 0
        i++
    }
}

func main() {
    arr := []int{0,1,0,3,12}
    moveZeroes(arr)
    fmt.Println(arr)
}
