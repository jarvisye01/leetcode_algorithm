package main

import "fmt"

func setZeroes(matrix [][]int) {
	M := len(matrix)
	if M == 0 {
		return
	}
	N := len(matrix[0])
	row := make([]bool, M, M)
	col := make([]bool, N, N)

	for i := 0; i < M; i++ {
		for j := 0; j < N; j++ {
			if matrix[i][j] == 0 {
				row[i] = true
				col[j] = true
			}
		}
	}

	for i := 0; i < M; i++ {
		for j := 0; j < N; j++ {
			if row[i] || col[j] {
				matrix[i][j] = 0
			}
		}
	}
}

//位运算做题会出现一个问题，就是int的位数是有限的，如果数组太大会超出
func setZero(matrix [][]int) {
	M := len(matrix)
	if M == 0 {
		return
	}
	N := len(matrix[0])
	row := 0 << uint(M)
	col := 0 << uint(N)

	for i := 0; i < M; i++ {
		for j := 0; j < N; j++ {
			if matrix[i][j] == 0 {
			//	设置row
			//  先检查
			//  关键点，注意到位运算的顺序，特别是与或非和移位运算
				if row & (1 << uint(M - i - 1)) == 0 {
					row += 1 << uint(M - i - 1)
				}
				if col & (1 << uint(N - j - 1)) == 0 {
					col += 1 << uint(N - j - 1)
				}
			}
		}
	}
	for i := 0; i < M; i++ {
		for j := 0; j < N; j++ {
			if row & (1 << uint(M - i - 1)) != 0 || col & (1 << uint(N - j - 1)) != 0 {
				matrix[i][j] = 0
			}
		}
	}
}

func main() {
	test := [][]int{
		{1,1,1},
		{1,0,1},
		{1,1,1},
	}
	setZero(test)
	fmt.Println(test)
}
