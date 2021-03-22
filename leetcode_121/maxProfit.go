package main

import "fmt"

func maxProfit(prices []int) int {
    if len(prices) == 0 {
        return 0
    }
    low := prices[0]
    res := 0
    for i := 1; i < len(prices); i++ {
        if prices[i] < low {
            low = prices[i]
        }
        if prices[i] > low && prices[i] - low > res {
            res = prices[i] - low
        }
    }
    return res
}

func main() {
    fmt.Println(maxProfit([]int{7,1,5,3,6,4}))
}
