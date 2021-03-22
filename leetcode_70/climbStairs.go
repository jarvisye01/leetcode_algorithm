package main

import "fmt"

func climbStairs(n int) int {
	if n <= 2 {
		return n
	}
	previous1 := 1
	previous2 := 2

	var total int
	for i := 3; i <= n; i++ {
		total = previous1 + previous2
		previous1, previous2 = previous2, total
	}
	return total
}

func main() {
	for i := 0; i < 30; i++ {
		fmt.Println(climbStairs(i))
	}
}
