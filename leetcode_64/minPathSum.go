package main

import "fmt"

func getMin(x, y int) int {
	if x < y {
		return x
	}
	return y
}

func minPathSum(grid [][]int) int {
	M := len(grid)
	if M == 0 {
		return 0
	}
	N := len(grid[0])

	dp := make([][]int, M)
	for i := 0; i < M; i++ {
		dp[i] = make([]int, N)
	}

	var row, col int
	for k := 0; k < M || k < N; k++ {
		if k < N {
			dp[0][k] = row + grid[0][k]
			row += grid[0][k]
		}
		if k < M {
			dp[k][0] = col + grid[k][0]
			col += grid[k][0]
		}
	}
	for i := 1; i < M; i++ {
		for j := 1; j < N; j++ {
			dp[i][j] = grid[i][j] + getMin(dp[i - 1][j], dp[i][j - 1])
		}
	}
	fmt.Println(dp)
	return dp[M - 1][N - 1]
}

func main() {
	test := [][]int{
		{1, 3, 1},
		//{1, 5, 1},
		//{4, 2, 1},
	}
	fmt.Println(minPathSum(test))
}
