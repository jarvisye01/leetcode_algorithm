package main

import "fmt"

func plusOne(digits []int) []int {
	carry := 1
	N := len(digits)

	for i := N - 1; i >= 0; i-- {
		carry = digits[i] + carry
		digits[i] = carry % 10
		carry = carry / 10
		if carry == 0 {
			return digits
		}
	}
	if carry > 0 {
		digits = append([]int{carry}, digits...)
	}
	return digits
}

func main() {
	fmt.Println(plusOne([]int{1, 2, 3, 4}))
}
