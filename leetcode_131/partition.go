package main

import "fmt"

func getArr(path []int, s string) []string {
    res := make([]string, 0)
    start := 0
    for _, i := range path {
        res = append(res, s[start : i + 1])
        start = i + 1
    }
    return res
}

func dfs(dp [][]bool, row int, col int, N int, path []int, res *[][]string, s string) {
    if col == N {
        fmt.Println(path)
        t := getArr(path, s)
        *res = append(*res, t)
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

func partition(s string) [][]string {
    N := len(s)
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

    res := make([][]string, 0)
    dfs(dp, 0, 0, N, []int{}, &res, s)

    return res
}

func main() {
    fmt.Println(partition("aabab"))
    fmt.Println(partition("ababa"))
}