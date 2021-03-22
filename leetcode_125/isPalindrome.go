package main

import "fmt"

func uniteStyle(c uint8) uint8 {
	if c >= 'A' && c <= 'Z' {
		return c + ('a' - 'A')
	}
	return c
}

func filter(c uint8) bool {
	if (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') {
		return true
	}
	return false
}

func isPalindrome(s string) bool {
	res := true
	start := 0
	end := len(s) - 1
	for start < end {
		for start < end && !filter(s[start]) {
			start++
		}
		for start < end && !filter(s[end]) {
			end--
		}
		if uniteStyle(s[start]) != uniteStyle(s[end]) {
			res = false
			break
		}
		start++
		end--
	}
	return res
}

func main() {
	fmt.Println(isPalindrome("A man, a plan, a canal: Panama"))
}
