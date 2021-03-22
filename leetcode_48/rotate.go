package main

import "fmt"

func move(matrix [][]int, x1, y1, x2, y2 int) {
	matrix[x1][y1] = matrix[x2][y2]
}

func rotate(matrix [][]int)  {
	N := len(matrix)
	//k表示回字的第几层
	L := N - 1
	for i := 0; i <= N / 2; i++ {
		for j := i; j < N - i - 1; j++ {
			t := matrix[i][j]
			x1 := i
			y1 := j
			x2 := L - y1
			y2 := x1
			for k := 0; k < 3; k++ {
				matrix[x1][y1] = matrix[x2][y2]
				x1 = x2
				y1 = y2
				x2 = L - y1
				y2 = x1
			}
			matrix[x1][y1] = t
		}
	}
}

func main() {
	a := [][]int{{1,2,3},{4,5,6},{7,8,9}}
	fmt.Println(a)
	rotate(a)
	fmt.Println(a)
}