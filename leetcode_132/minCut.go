package main

import "fmt"

func dfs(dp [][]bool, row int, col int, N int, path []int, res *int, s string) {
    if col == N {
        if len(path) - 1 < *res {
            *res = len(path) - 1
        }
        return
    }

    for i := col; i < N; i++ {
        if dp[row][i] {
            path = append(path, i)
            dfs(dp, i + 1, i + 1, N, path, res, s)
            path = path[ : len(path) - 1]
        }
    }

}

func minCut(s string) int {
    N := len(s)
    if N <= 1 {
        return 0
    }
    dp := make([][]bool, N)
    for i := 0; i < N; i++ {
        dp[i] = make([]bool, N)
        dp[i][i] = true
    }

    for i := 1; i < N; i++ {
        for j := i; j < N; j++ {
            if s[j - i] == s[j] {
                if i > 1 {
                    dp[j - i][j] = dp[j - i + 1][j - 1]
                } else {
                    dp[j - i][j] = true
                }
            }
        }
    }
    res := 1 << 30
    dfs(dp, 0, 0, N, []int{}, &res, s)
    return res
}

func main() {
    fmt.Println(minCut("ababa"))
}
