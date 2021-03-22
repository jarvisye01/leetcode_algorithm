package main

import "fmt"

func translate(board [][]byte, row, col, block []map[int]int) [][]int {
	M := len(board)
	N := len(board[0])
	arr := make([][]int, M, M)
	for i := 0; i < M; i++ {
		arr[i] = make([]int, N, N)
		for j := 0; j < N; j++ {
			if board[i][j] == '.' {
				arr[i][j] = 0
			} else {
				arr[i][j] = int(board[i][j] - '0')
				row[i][arr[i][j]] = 1
				col[j][arr[i][j]] = 1
				block[(i / 3) * 3 + j / 3][arr[i][j]] = 1
			}
		}
	}
	return arr
}

func toByte(b [][]byte, a [][]int) {
	for i := 0; i < 9; i++ {
		for j := 0; j < 9; j++ {
			b[i][j] = byte(a[i][j] + '0')
		}
	}
}

func initMap(n int) []map[int]int {
	m := make([]map[int]int, n, n)
	for i := 0; i < n; i++ {
		m[i] = map[int]int{}
	}
	return m
}

func dfs(arr [][]int, startX int, startY int, row, col, block []map[int]int, n int) int {
	i := startX
	j := startY
	for ; i < 9; i++ {
		flag := false
		for ; j < 9; j++ {
			if arr[i][j] != 0 {
				row[i][arr[i][j]] = 1
				col[j][arr[i][j]] = 1
				block[(i / 3) * 3 + j / 3][arr[i][j]] = 1
				n++
			} else {
				flag = !flag
				break
			}
		}
		if flag {
			break
		}
		j = 0
	}
	if n == 81 {
		return n
	}
	for k := 1; k <= 9; k++ {
		if row[i][k] == 0 && col[j][k] == 0 && block[(i / 3) * 3 + j / 3][k] == 0 {
			arr[i][j] = k
			row[i][k] = 1
			col[j][k] = 1
			block[(i / 3) * 3 + j / 3][k] = 1
			if dfs(arr, i, j, row, col, block, n) == 81 {
				return 81
			}
			row[i][k] = 0
			col[j][k] = 0
			block[(i / 3) * 3 + j / 3][k] = 0
		}
	}
	//失败回溯
	arr[i][j] = 0
	return n
}

//board [][]byte
func solveSudoku(board [][]byte)  {
	row := initMap(9)
	col := initMap(9)
	block := initMap(9)
	test := translate(board, row, col, block)
	dfs(test, 0, 0, row, col, block, 0)
	fmt.Println(test)
	toByte(board, test)
}

func main() {
	//fmt.Println('9' - '0')
	test := [][]int{
		{5, 3, 0, 0, 7, 0, 0, 0, 0},
		{6, 0, 0, 1, 9, 5, 0, 0, 0},
		{0, 9, 8, 0, 0, 0, 0, 6, 0},
		{8, 0, 0, 0, 6, 0, 0, 0, 3},
		{4, 0, 0, 8, 0, 3, 0, 0, 1},
		{7, 0, 0, 0, 2, 0, 0, 0, 6},
		{0, 6, 0, 0, 0, 0, 2, 8, 0},
		{0, 0, 0, 4, 1, 9, 0, 0, 5},
		{0, 0, 0, 0, 8, 0, 0, 7, 9},
	}
	for i := 0; i < 9; i++ {
		fmt.Print("{")
		for j := 0; j < 9; j++ {
			fmt.Printf("'%d'", test[i][j])
			if j < 8 {
				fmt.Print(", ")
			}
		}
		fmt.Println("}, ")
	}
	b := [][]byte{
		{'5', '3', '0', '0', '7', '0', '0', '0', '0'},
		{'6', '0', '0', '1', '9', '5', '0', '0', '0'},
		{'0', '9', '8', '0', '0', '0', '0', '6', '0'},
		{'8', '0', '0', '0', '6', '0', '0', '0', '3'},
		{'4', '0', '0', '8', '0', '3', '0', '0', '1'},
		{'7', '0', '0', '0', '2', '0', '0', '0', '6'},
		{'0', '6', '0', '0', '0', '0', '2', '8', '0'},
		{'0', '0', '0', '4', '1', '9', '0', '0', '5'},
		{'0', '0', '0', '0', '8', '0', '0', '7', '9'},
	}
	solveSudoku(b)
	fmt.Println(b)
	fmt.Println(byte(6 + '0') == '6')
}

