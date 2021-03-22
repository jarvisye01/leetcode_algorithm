package main

import "fmt"

func dfs(b [][]byte, m int, n int, w string, cur int, curI int, curJ int, used [][]bool) bool {
	if w[cur] != b[curI][curJ] {
		return false
	}
	if cur == len(w) - 1 {
		return true
	}
	used[curI][curJ] = true
	if curI - 1 >= 0 {
		if !used[curI - 1][curJ] && dfs(b, m, n, w, cur + 1, curI - 1, curJ, used) {
			return true
		}
	}
	if curJ + 1 < n {
		if !used[curI][curJ + 1] && dfs(b, m, n, w, cur + 1, curI, curJ + 1, used) {
			return true
		}
	}
	if curI + 1 < m {
		if !used[curI + 1][curJ] && dfs(b, m, n, w, cur + 1, curI + 1, curJ, used) {
			return true
		}
	}
	if curJ - 1 >= 0 {
		if !used[curI][curJ - 1] && dfs(b, m, n, w, cur + 1, curI, curJ - 1, used) {
			return true
		}
	}
	used[curI][curJ] = false
	return false
}

func exist(board [][]byte, word string) bool {
	M := len(board)
	if word == "" {
		return false
	}
	if M == 0 {
		return false
	}
	N := len(board[0])
	used := make([][]bool, M, M)
	for i := 0; i < M; i++ {
		used[i] = make([]bool, N, N)
	}
	for i := 0; i < M; i++ {
		for j := 0; j < N; j++ {
			if word[0] == board[i][j] {
				if dfs(board, M, N, word,0, i, j, used) {
					return true
				}
			}
		}
	}
	return false
}

func main() {
	fmt.Println("test")
	//test := [][]byte{
	//	{'A','B','C','E'},
	//	{'S','F','C','S'},
	//	{'A','D','E','E'},
	//}
	//fmt.Println(exist(test, "ABCB"))
	test := [][]byte{
		{'A'},
	}
	fmt.Println(exist(test, "A"))
}