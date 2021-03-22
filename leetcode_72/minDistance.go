package main

import "fmt"

func getMin(a, b, c int) int {
	m := a
	if b < m {
		m = b
	}
	if c < m {
		m = c
	}
	return m
}

func minDistance(word1 string, word2 string) int {
	M := len(word1)
	N := len(word2)

	dp := make([][]int, M + 1, M + 1)
	for i := 0; i <= M; i++ {
		dp[i] = make([]int, N + 1, N + 1)
	}

	for i := 0; i <= M || i <= N; i++ {
		if i <= M {
			dp[i][0] = i
		}
		if i <= N {
			dp[0][i] = i
		}
	}

	for i := 1; i <= M; i++ {
		for j := 1; j <= N; j++ {
			if word1[i - 1] == word2[j - 1] {
				dp[i][j] = dp[i - 1][j - 1]
			} else {
				dp[i][j] = getMin(dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + 1)
			}
		}
	}
	return dp[M][N]
}

func main() {
	fmt.Println(minDistance("rad", "apple"))
}
