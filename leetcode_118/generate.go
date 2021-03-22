package main

import "fmt"

func generate(numRows int) [][]int {
    res := make([][]int, 0)
    if numRows == 0 {
        return res
    }
    res = append(res, []int{1})
    for i := 1; i < numRows; i++ {
        row := make([]int, len(res[i - 1]) + 1)
        row[0], row[len(row) - 1] = res[i - 1][0], res[i - 1][len(res[i -1 ]) - 1]
        for j := 1; j < len(row) - 1; j++ {
            row[j] = res[i - 1][j - 1] + res[i - 1][j]
        }
        res = append(res, row)
    }
    return res
}

func main() {
    fmt.Println(generate(5))
}
