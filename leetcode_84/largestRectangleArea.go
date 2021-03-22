package main

import "fmt"

func getMin(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func getMax(a, b int) int {
	if a > b {
		return a
	}
	return b
}

//思想优点僵硬，不要啥都想着DP
//func largestRectangleArea(heights []int) int {
//	N := len(heights)
//	m := 0
//	dp := make([][]int, N, N)
//	for i := 0; i < N; i++ {
//		dp[i] = make([]int, N, N)
//		dp[i][i] = heights[i]
//		if dp[i][i] > m {
//			m = dp[i][i]
//		}
//	}
//	for i := 0; i < N; i++ {
//		for j := i + 1; j < N; j++ {
//			//h[i][j] = min(h[i][j - 1], heights[i])
//			dp[j][i] = getMin(dp[j - 1][i], heights[j])
//			dp[i][j] = dp[j][i] * (j - i + 1)
//			if dp[i][j] > m {
//				m = dp[i][j]
//			}
//		}
//	}
//	return m
//}

func resize(str []int, l int, capacity int) []int {
	copy := make([]int, capacity, capacity)
	for i := 0; i < l; i++ {
		copy[i] = str[i]
	}
	return copy
}

func monotonicStack(h []int) int {
	maxA := 0
	N := len(h)
	s := make([]int, N + 1, N + 1)
	top := 0
	s[top] = -1
	top++
	for i := 0; i < N; i++ {
		for s[top - 1] != -1 && h[i] < h[s[top - 1]] {
			top--
			maxA = getMax(h[s[top]] * (i - s[top - 1] - 1), maxA)
		}
		s[top] = i
		top++
	}
	for s[top - 1] != -1 {
		top--
		tH := h[s[top]]
		tW := N - s[top - 1] - 1
		maxA = getMax(tH * tW, maxA)
	}
	return maxA;
}

func largestRectangleArea(heights []int) int {
	N := len(heights)
	m := 0
	for i := 0; i < N; i++ {
		minH := 1 << 31
		for j := i; j < N; j++ {
			minH = getMin(minH, heights[j])
			area := minH * (j - i + 1)
			if area > m {
				m = area
			}
		}
	}
	return m
}

func main() {
	fmt.Println(largestRectangleArea([]int{2, 1, 5, 6, 2, 3}))
	fmt.Println(monotonicStack([]int{2, 1, 5, 6, 2, 3}))
}
