package main

import "fmt"

func longestValidParentheses(s string) int {
    N := len(s)
    res := 0
    dp := make([]int, N)

    for i := 1; i < N; i++ {
        if s[i] == ')' {
            if s[i - 1] == '(' {
                if i - 2 >= 0 {
                    dp[i] = dp[i - 2] + 2
                } else {
                    dp[i] = 2
                }
            } else if i - 2 > 0 && i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] == '(' {
                if i - dp[i - 1] - 2 >= 0 {
                    dp[i] = dp[i - 1] + 2 + dp[i - dp[i - 1] - 2]
                } else {
                    dp[i] = dp[i - 1] + 2
                }
            }
        }
        if dp[i] > res {
            res = dp[i]
        }
    }
    return res
}

func main() {
    s := "(()))())("
    res := longestValidParentheses(s)
    fmt.Println(res)
}