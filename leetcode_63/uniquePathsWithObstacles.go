package main

import "fmt"

var dp [][]int

func dfs(nums [][]int, m, n, i, j int) int {
	if n == i && m == j {
		if nums[i - 1][j - 1] == 0 {
			dp[i - 1][j - 1] = 1
			return 1
		}
		dp[i - 1][j - 1] = 0
		return 0
	}

	if dp[i - 1][j - 1] != -1 {
		return dp[i - 1][j - 1]
	}

	if nums[i - 1][j - 1] == 1 {
		dp[i - 1][j - 1] = 0
		return 0
	}

	if i < n && j < m {
		dp[i - 1][j - 1] = 0
		dp[i - 1][j - 1] = dfs(nums, m , n, i + 1, j) + dfs(nums, m, n, i, j + 1)
	} else if i < n {
		dp[i - 1][j - 1] = dfs(nums, m , n, i + 1, j)
	} else {
		dp[i - 1][j - 1] = dfs(nums, m, n, i, j + 1)
	}

	//if i < n && j < m {
	//	dp[i - 1][j - 1] = 0
	//	if nums[i][j - 1] != 1 {
	//		dp[i - 1][j - 1] += dfs(nums, m , n, i + 1, j)
	//	}
	//	if nums[i - 1][j] != 1 {
	//		dp[i - 1][j - 1] += dfs(nums, m, n, i, j + 1)
	//	}
	//} else if i < n {
	//	if nums[i][j - 1] != 1 {
	//		dp[i - 1][j - 1] += dfs(nums, m , n, i + 1, j)
	//	}
	//} else {
	//	if nums[i - 1][j] != 1 {
	//		dp[i - 1][j - 1] += dfs(nums, m, n, i, j + 1)
	//	}
	//}
	fmt.Println(dp)
	return dp[i - 1][j - 1]
}

func uniquePathsWithObstacles(obstacleGrid [][]int) int {
	n := len(obstacleGrid)
	m := len(obstacleGrid[0])
	dp = make([][]int, n, n)
	for i := 0; i < n; i++ {
		dp[i] = make([]int, m, m)
	}
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			dp[i][j] = -1
		}
	}
	return dfs(obstacleGrid, m, n, 1, 1)
}

func main() {
	test := [][]int{
		{0, 0, 0},
		{0, 1, 0},
		{0, 0, 0},
	}
	fmt.Println(uniquePathsWithObstacles(test))
}
