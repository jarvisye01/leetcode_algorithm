package main

func getMin(nums... int) int {
    if len(nums) == 1 {
        return nums[0]
    }

    m := nums[0]
    for _, v := range nums {
        if v < m {
            m = v
        }
    }
    return m
}

func maximalSquare(matrix [][]byte) int {
    res := 0
    M := len(matrix)
    if M == 0 {
        return res
    }
    N := len(matrix[0])
    if N == 0 {
        return res
    }

    dp := make([][]int, M)
    for i := 0; i < M; i++ {
        dp[i] = make([]int, N)
    }

    for i := 0; i < M; i++ {
        for j := 0; j < N; j++ {
            if matrix[i][j] == '1' {
                if i > 0 && j > 0 {
                    dp[i][j] = getMin(dp[i][j - 1], dp[i - 1][j - 1], dp[i - 1][j]) + 1
                } else {
                    dp[i][j] = 1
                }
            }
            if dp[i][j] > res {
                res = dp[i][j]
            }
        }
    }
    return res * res
}

func main() {

}
