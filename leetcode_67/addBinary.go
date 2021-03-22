package main

import (
	"fmt"
	"strconv"
)

func simpleAdd(num1 string, num2 string, R int) string {
	r := ""
	carry := 0
	i := len(num1) - 1
	j := len(num2) - 1
	for i >= 0 && j >= 0 {
		x, _ := strconv.Atoi(num1[i : i + 1])
		y, _ := strconv.Atoi(num2[j : j + 1])
		carry = x + y + carry
		r = strconv.Itoa(carry % R) + r
		carry /= R
		i--
		j--
	}
	for i >= 0 {
		x, _ := strconv.Atoi(num1[i : i + 1])
		carry = x + carry
		r = strconv.Itoa(carry % R) + r
		carry /= R
		i--
		if carry == 0 {
			break
		}
	}
	for j >= 0 {
		x, _ := strconv.Atoi(num2[j : j + 1])
		carry = x + carry
		r = strconv.Itoa(carry % R) + r
		carry /= R
		j--
		if carry == 0 {
			break
		}
	}

	if i >= 0 {
		r = num1[ : i + 1] + r
	}

	if j >= 0 {
		r = num2[ : j + 1] + r
	}

	if carry > 0 {
		r = strconv.Itoa(carry) + r
	}
	return r
}

func addBinary(a string, b string) string {
	return simpleAdd(a, b, 2)
}

func main() {
	fmt.Println(addBinary("11", "1"))
}




