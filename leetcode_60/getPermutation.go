package main

import (
	"fmt"
	"strconv"
)

func factorial(n int) int {
	r := 1
	for i := n; i > 0; i-- {
		r *= i;
	}
	return r
}

func getALetter(n int, k int, nums []int) string {
	if n == 1 {
		return strconv.Itoa(nums[0])
	}
	//N := factorial(n)
	M := factorial(n - 1)
	t := (k - 1) / M + 1
	curs := strconv.Itoa(nums[t - 1])
	newNums := append(nums[ : t - 1], nums[t : ]...)
	return curs + getALetter(n - 1, k - M * (t - 1), newNums)
}

func getPermutation(n int, k int) string {
	nums := make([]int, n, n)
	for i := 1; i <= n; i++ {
		nums[i - 1] = i
	}
	res := ""
	res = getALetter(n, k, nums)
	return res
}

func main() {
	for i := 1; i <= 6; i++ {
		fmt.Println(getPermutation(3, i))
	}
	fmt.Println(getPermutation(3, 1))
	fmt.Println(getPermutation(3, 2))
	fmt.Println(getPermutation(3, 3))

	for i := 1; i <= 10; i++ {
		fmt.Println(factorial(i))
	}
}
