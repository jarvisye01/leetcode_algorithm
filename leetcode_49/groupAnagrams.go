package main

import "fmt"

func hash(str string) int {
	hash := len(str)
	mul := 1
	for i := 0; i < len(str); i++ {
		hash += int(str[i])
		mul *= int(str[i])
	}
	return hash + mul
}

func groupAnagrams(strs []string) [][]string {
	res := make([][]string, 0, 0)
	m := map[int][]string{}
	for i := 0; i < len(strs); i++ {
		h := hash(strs[i])
		m[h] = append(m[h], strs[i])
	}
	for _, v := range m {
		res = append(res, v)
	}
	return res
}

func main() {
	a := []string{"cab","tin","pew","duh","may","ill","buy","bar","max","doc"}
	fmt.Println(groupAnagrams(a))
}
