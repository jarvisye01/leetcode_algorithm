package main

import "fmt"

func generateMatrix(n int) [][]int {
	res := make([][]int, n, n)
	for i := 0; i < n; i++ {
		res[i] = make([]int, n, n)
	}

	limitx := n - 1
	limity := n - 1
	startX := 0
	startY := 0
	t := 0
	num := 1
	for t < (n / 2) + (n % 2) {
		for k := 0; k <= limity; k++ {
			res[startX][startY + k] = num
			num++
		}
		for k := 1; k < limitx; k++ {
			res[startX + k][startX + limity] = num
			num++
		}
		for k := limity; k >= 0 && limitx > 0; k-- {
			res[startX + limitx][startY + k] = num
			num++
		}
		for k := limitx - 1; k >= 1 && limity > 0; k-- {
			res[startX + k][startY] = num
			num++
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
	fmt.Println(generateMatrix(3))
}
