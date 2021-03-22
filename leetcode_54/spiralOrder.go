package main

import "fmt"

func getMin(x, y int) int {
	if x < y {
		return x
	}
	return y
}

func spiralOrder(matrix [][]int) []int {
	M := len(matrix)
	if M == 0 {
		return []int{}
	}

	N := len(matrix[0])
	res := make([]int, 0, M * N)

	limitx := M - 1
	limity := N - 1
	startX := 0
	startY := 0
	min := getMin(M, N)
	t := 0
	for t < (min / 2) + (min % 2) {
		for k := 0; k <= limity; k++ {
			res = append(res, matrix[startX][startY + k])
		}
		for k := 1; k < limitx; k++ {
			res = append(res, matrix[startX + k][startX + limity])
		}
		for k := limity; k >= 0 && limitx > 0; k-- {
			res = append(res, matrix[startX + limitx][startY + k])
		}
		for k := limitx - 1; k >= 1 && limity > 0; k-- {
			res= append(res, matrix[startX + k][startY])
		}
		t++
		startX++
		startY++
		limitx -= 2
		limity -= 2
	}
	return res
}

func main() {
	a := spiralOrder([][]int{
		{1, 2, 3},
		{4, 5, 6},
	})
	fmt.Println(a)
}