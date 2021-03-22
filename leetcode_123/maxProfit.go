package main

import "fmt"

func getMax(a, b int) int {
    if a > b {
        return a
    }
    return b
}

//func maxProfit(prices []int) int {
//    profit := 0
//    if len(prices) == 0 {
//        return profit
//    }
//    N := len(prices)
//
//    m := make([]int, N)
//    profits := make([][]int, N)
//    for i := 0; i < N; i++ {
//        profits[i] = make([]int, N)
//        profits[i][i] = 0
//    }
//
//    for i := 0; i < N; i++ {
//        minPrice := prices[i]
//        mp := 0
//        for j := i + 1; j < N; j++ {
//            if prices[j] < minPrice {
//                minPrice = prices[j]
//                profits[i][j] = profits[i][j - 1]
//            } else {
//                t := prices[j] - minPrice
//                if t > mp {
//                    mp = t
//                    profits[i][j] = t
//                } else {
//                    profits[i][j] = profits[i][j - 1]
//                }
//            }
//            m[j] = getMax(m[j], profits[i][j])
//        }
//    }
//    for i := 0; i < N; i++ {
//        profit = getMax(profit, profits[i][N - 1] + m[i])
//    }
//    return profit
//}

func maxProfit(prices []int) int {
    profit := 0
    if len(prices) == 0 {
        return profit
    }

    N := len(prices)

    row := make([]int, N)
    col := make([]int, N)

    min := prices[0]
    max := prices[N - 1]

    for i := 1; i < N; i++ {
        if prices[i] < min {
            min = prices[i]
            row[i] = row[i -1]
        } else {
            row[i] = getMax(row[i - 1], prices[i] - min)
        }

        if prices[N - 1 - i] > max {
            max = prices[N - 1 - i]
            col[N - 1 - i] = col[N - i]
        } else {
            col[N - 1 - i] = getMax(col[N - i], max - prices[N - 1 - i])
        }
    }

    for i := 0; i < N; i++ {
        t := row[i] + col[i]
        if t > profit {
            profit = t
        }
    }

    return profit
}

func main() {
    profit := []int{3,3,5,0,0,3,1,4}
    fmt.Println(maxProfit(profit))
}
