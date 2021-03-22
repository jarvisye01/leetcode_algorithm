package main

func maxProfit(prices []int) int {
    profit := 0
    N := len(prices)

    for i := 0; i < N - 1; i++ {
        t := prices[i + 1] - prices[i]
        if t > 0 {
            profit += t
        }
    }

    return profit
}

func main() {

}
