package main

import "fmt"

func getRow(rowIndex int) []int {
    res := make([]int, 0)
    res = append(res, 1)
    for i := 1; i < rowIndex + 1; i++ {
        row := make([]int, len(res) + 1)
        row[0], row[len(row) - 1] = res[0], res[len(res) - 1]
        for j := 1; j < len(row) - 1; j++ {
            row[j] = res[j - 1] + res[j]
        }
        res = row
    }
    return res
}

func main() {
    fmt.Println(getRow(5))
}
