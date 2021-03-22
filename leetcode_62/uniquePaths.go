package main

import "fmt"

var dp [][]int

func dfs(m, n, i, j int) int {
	if n == i && m == j {
		dp[i - 1][j - 1] = 1
		return 1
	}
	if dp[i - 1][j - 1] != 0 {
		return dp[i - 1][j - 1]
	}
	if i < n && j < m {
		dp[i - 1][j - 1] = dfs(m , n, i + 1, j) + dfs(m, n, i, j + 1)
	} else if i < n {
		dp[i - 1][j - 1] = dfs(m, n, i + 1, j)
	} else {
		dp[i - 1][j - 1] = dfs(m, n, i, j + 1)
	}
	return dp[i - 1][j - 1]
}

func uniquePaths(m int, n int) int {
	dp = make([][]int, n, n)
	for i := 0; i < n; i++ {
		dp[i] = make([]int, m, m)
	}
	return dfs(m, n, 1, 1)
}

func main() {
	fmt.Println(uniquePaths(100, 100))
	//for i := 10; i < 200; i += 10 {
	//	fmt.Println(uniquePaths(i, i))
	//}
}
