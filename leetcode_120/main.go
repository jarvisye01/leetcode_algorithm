package main

import "fmt"

func getMin(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func getArratMin(arr []int) int {
	m := 1 << 30
	for i := 0; i < len(arr); i++ {
		if arr[i] < m {
			m = arr[i]
		}
	}
	return m
}

func simple(triangle [][]int) int {
	N := len(triangle)
	if N == 0 {
		return 0
	}
	for i := N - 2; i >= 0; i-- {
		for j := 0; j < len(triangle[i]); j++ {
			triangle[i][j] += getMin(triangle[i + 1][j], triangle[i + 1][j + 1])
		}
	}
	return triangle[0][0]
}

func minimumTotal(triangle [][]int) int {
	N := len(triangle)
	if N == 0 {
		return 0
	}
	res := make([][]int, N)
	for i := 0; i < N; i++ {
		res[i] = make([]int, N)
	}

	res[0][0] = triangle[0][0]

	for i := 1; i < N; i++ {
		for j := 0; j < len(triangle[i]); j++ {
			if j == 0 {
				res[i][j] = triangle[i][j] + res[i - 1][j]
 			} else if  j == len(triangle[i]) - 1 {
				res[i][j] = triangle[i][j] + res[i - 1][j - 1]
			} else {
				res[i][j] = triangle[i][j] + getMin(res[i - 1][j], res[i - 1][j - 1])
			}
		}
	}
	return getArratMin(res[N - 1])
}

func main() {
	test := [][]int{
		{-1},
		{2,3},
		{1,-1,-3},
	}
	fmt.Println(minimumTotal(test))
}
