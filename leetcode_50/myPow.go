package main

import "fmt"

/**
* 获取绝对值
* @author jarvisye
* @param x
* @return float64
*/
func abs(x int) int {
	if x >= 0 {
		return x
	}
	return -x
}

/**
* 实现pow函数
* @param x 底数
* @param n 指数
* @return float64
*/
func myPow(x float64, n int) float64 {
	if n == 0 {
		return 1
	}
	n_abs := abs(n)
	res := x
	t := 1
	for t * 2 <= n_abs {
		res *= res
		t *= 2
	}
	for t = t + 1; t <= n_abs; t++ {
		res *= x
	}
	if n > 0 {
		return res
	}
	return 1 / res
}

func main() {
	fmt.Println(myPow(-1.000000, -2147483648))
}