package main

import (
	"fmt"
	"strconv"
)

func produceString(s string) string {
	m := map[byte]int{}
	num := 1
	for i := 'A'; i <= 'Z'; i++ {
		m[byte(i)] = num
		num++
	}
	res := ""
	for i := 0; i < len(s); i++ {
		res += strconv.Itoa(m[s[i]])
	}
	return res
}

func numDecodings(s string) int {
	N := len(s)
	if N == 0 {
		return 0
	}
	if s[0 : 1] == "0" {
		return 0
	}
	dp := make([]int, N + 1)
	dp[0] = 1
	dp[1] = 1
	for i := 1; i < N; i++ {
		if s[i] == '0' {
			if s[i - 1] != '1' && s[i - 1] != '2' {
				return 0
			}
			dp[i + 1] = dp[i - 1]
		} else if s[i] >= '1' && s[i] <= '6' {
			if s[i - 1] == '1' || s[i - 1] == '2' {
				dp[i + 1] = dp[i] + dp[i - 1]
			} else {
				dp[i + 1] = dp[i]
			}
		} else {
			if s[i - 1] == '1' {
				dp[i + 1] = dp[i] + dp[i - 1]
			} else {
				dp[i + 1] = dp[i]
			}
		}
	}
	return dp[N]
}

func main() {
	test := "AGSAHFKASHD"
	s := "0"
	fmt.Println(s == "0")
	fmt.Println(produceString(test))
	fmt.Println(numDecodings("17191861111984"))
}
