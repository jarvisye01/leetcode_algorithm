package main

import "fmt"

func trailingZeroes(n int) int {
    res := 0
    for num := n; num > 4; num /= 5 {
        res += num / 5
    }
    return res
}

func main() {
    for i := 1; i < 501; i++ {
       fmt.Println(i, "=>", trailingZeroes(i))
    }
}
