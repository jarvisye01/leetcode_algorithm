package main

import "fmt"

func exp2(n int) int {
	if n == 0 {
		return 1
	}
	res := 1
	for i := 0; i < n; i++ {
		res *= 2
	}
	return res
}

func recursive(n int, depth int, start int, end int, res []int, direct int) {
	if depth == n {
		return
	}
	mid := start + (end - start) / 2
	var t1  int
	var t2  int
	if direct == 1 {
		t1 = 1
	} else {
		t2 = 1
	}
	for i := start; i <= mid; i++ {
		res[i] = res[i] * 2 + t1
	}
	for i := mid + 1; i <= end; i++ {
		res[i] = res[i] * 2 + t2
	}
	recursive(n, depth + 1, start, mid, res, 0)
	recursive(n, depth + 1, mid + 1, end, res, 1)
}

func grayCode(n int) []int {
	res := make([]int, exp2(n))
	recursive(n, 0, 0, exp2(n) - 1, res, 0)
	return res
}

func main() {
	fmt.Println(exp2(3))
	fmt.Println(exp2(4))
	for i := 0; i < 10; i++ {
		fmt.Println(grayCode(i))
	}
}
