package main

import (
	"fmt"
	"strconv"
)

//显然添加一个基数R参数，亦可以处理其他进制的数字
func simpleAdd(num1 string, num2 string) string {
	r := ""
	carry := 0
	i := len(num1) - 1
	j := len(num2) - 1
	for i >= 0 && j >= 0 {
		x, _ := strconv.Atoi(num1[i : i + 1])
		y, _ := strconv.Atoi(num2[j : j + 1])
		carry = x + y + carry
		r = strconv.Itoa(carry % 10) + r
		carry /= 10
		i--
		j--
	}
	for i >= 0 {
		x, _ := strconv.Atoi(num1[i : i + 1])
		carry = x + carry
		r = strconv.Itoa(carry % 10) + r
		carry /= 10
		i--
		if carry == 0 {
			break
		}
	}
	for j >= 0 {
		x, _ := strconv.Atoi(num2[j : j + 1])
		carry = x + carry
		r = strconv.Itoa(carry % 10) + r
		carry /= 10
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

func simpleMul(num1 string, num2 string) string {
	if num1 == "0" {
		return "0"
	}
	r := ""
	x, _ := strconv.Atoi(num1)
	carry := 0
	for i := len(num2) - 1; i >= 0; i-- {
		y, _ := strconv.Atoi(num2[i : i + 1])
		y = x * y + carry
		carry = y / 10
		r = strconv.Itoa(y % 10) + r
	}
	if carry > 0 {
		r = strconv.Itoa(carry) + r
	}
	return r
}

func suffix(n int) string {
	r := ""
	for i := 0; i < n; i++ {
		r += "0"
	}
	return r
}

func multiply(num1 string, num2 string) string {
	r := "0"
	k := 0
	for i := len(num1) - 1; i >= 0; i-- {
		t := simpleMul(num1[i : i + 1], num2)
		if t != "0" {
			r = simpleAdd(r, t + suffix(k))
		}
		k++
	}
	return r
}

func main() {
	t := "4"
	fmt.Println(strconv.Itoa(8))
	fmt.Println(strconv.Atoi(t))

	fmt.Println(simpleMul("2", "3321"))
	fmt.Println(simpleAdd("123213", "123"))
	fmt.Println(multiply("20", "52"))
	//fmt.Println("1234"[3 : 4])
}
