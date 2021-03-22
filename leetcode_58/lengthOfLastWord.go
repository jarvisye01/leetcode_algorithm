package main

import "fmt"

func lengthOfLastWord(s string) int {
	count := 0
	N := len(s)
	start := N - 1
	for i := N - 1; i >= 0; i-- {
		if s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z' {
			start = i
			break
		}
	}
	for i := start; i >= 0; i-- {
		if s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z' {
			count++
		} else {
			break
		}
	}
	return count
}

func main() {
	fmt.Println(lengthOfLastWord("Hello, world!"))
}
