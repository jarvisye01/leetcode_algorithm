package main

import "fmt"

func judge(x int, y int, l int, w int) bool {
    if x < 0 || x >= l || y < 0 || y >= w {
        return false
    }
    return true
}

func markPoint(x int, y int, mark [][]bool, l int, w int, board [][]byte) {
    if !judge(x, y, l, w) || board[x][y] != 'O' || mark[x][y] == true {
        return
    }

    mark[x][y] = true
    if judge(x + 1, y, l, w) && !mark[x + 1][y] {
        markPoint(x + 1, y, mark, l, w, board)
    }
    if judge(x - 1, y, l, w) && !mark[x - 1][y] {
        markPoint(x - 1, y, mark, l, w, board)
    }
    if judge(x, y + 1, l, w) && !mark[x][y + 1] {
        markPoint(x, y + 1, mark, l, w, board)
    }
    if judge(x, y - 1, l, w) && !mark[x][y + 1] {
        markPoint(x, y - 1, mark, l, w, board)
    }
}

func solve(board [][]byte) {
    if len(board) == 0 || len(board[0]) == 0 {
        return
    }

    mark := make([][]bool, len(board))
    for i := 0; i < len(board); i++ {
        mark[i] = make([]bool, len(board[i]))
    }

    M := len(board)
    N := len(board[0])
    for i := 0; i < N; i++ {
        if board[0][i] == 'O' {
            markPoint(0, i, mark, M, N, board)
        }
        if board[M - 1][i] == 'O' {
            markPoint(M - 1,  i, mark, M, N, board)
        }
    }

    for i := 1; i < M - 1; i++ {
        if board[i][0] == 'O' {
            markPoint(i, 0, mark, M, N, board)
        }
        if board[i][N - 1] == 'O' {
            markPoint(i, N - 1, mark, M, N, board)
        }
    }

    for i := 0; i < M; i++ {
        for j := 0; j < N; j++ {
            if board[i][j] == 'O' && !mark[i][j] {
                board[i][j] = 'X'
            }
        }
    }
}

func main() {
    board := [][]byte {
       {'X', 'X', 'X', 'X'},
       {'X', 'O', 'O', 'X'},
       {'X', 'X', 'O', 'X'},
       {'X', 'O', 'X', 'X'},
    }
    solve(board)

    for i := 0; i < len(board); i++ {
        for j := 0; j < len(board[0]); j++ {
            fmt.Printf("%c ", board[i][j])
        }
        fmt.Println()
    }
}
