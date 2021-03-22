package main

import "fmt"

func factorial(n int) int {
    r := 1
    for i := n; i > 0; i-- {
        r *= i;
    }
    return r
}

func getPermute(nums []int, n int) [][]int  {
    if n < 0 {
        return [][]int{}
    }
    if n == 0 {
        result := make([][]int, 1, 1)
        result[0] = append(result[0], nums[n])
        return result
    }
    lastR := getPermute(nums, n - 1)
    M := len(lastR)
    result := make([][]int, factorial(n + 1), factorial(n + 1))
    nr := 0
    for i := 0; i < M; i++ {
        r := 0
        for j := 0; j <= n; j++ {
            t := 0
            result[nr] = make([]int, n + 1, n + 1)
            for k := 0; k <= n; k++ {
                if k == r {
                    result[nr][k] = nums[n]
                } else {
                    result[nr][k] = lastR[i][t]
                    t++
                }
            }
            r++
            nr++
        }
    }
    return result
}

func permute(nums []int) [][]int {
    N := len(nums)
    return getPermute(nums, N - 1);
}

func main() {
    fmt.Println(factorial(3))
    fmt.Println(permute([]int{1, 2, 3}))
}
