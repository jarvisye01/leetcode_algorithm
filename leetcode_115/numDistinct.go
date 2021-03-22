package main

import "fmt"

func dfs(s string, t string, start int, res *int, depth int) {
	if depth == len(t) {
		*res++
		return
	}

	for i := start; i < len(s); i++ {
		if s[i] == t[depth] {
			dfs(s, t, i + 1, res, depth + 1)
		}
	}
}

func dynamic(s string, t string) int {
	M := len(t) + 1
	N := len(s) + 1
	match := make([][]int, M, M)
	for i := 0; i < M; i++ {
		match[i] = make([]int, N, N)
	}
	match[0][0] = 1
	for i := 1; i < M || i < N; i++ {
		if i < M {
			match[i][0] = 0
		}
		if i < N {
			match[0][i] = 1
		}
	}
	for i := 1; i < M; i++ {
		for j := 1; j < N; j++ {
			if t[i - 1] == s[j - 1] {
				match[i][j] = match[i - 1][j - 1] + match[i][j - 1]
			} else {
				match[i][j] = match[i][j - 1]
			}
		}
	}
	return match[M - 1][N - 1]
}

func numDistinct(s string, t string) int {
	//res := 0
	//dfs(s, t, 0, &res, 0)
	//return res
	return dynamic(s, t)
}

func main() {
	S := "adbdadeecadeadeccaeaabdabdbcdabddddabcaaadbabaaedeeddeaeebcdeabcaaaeeaeeabcddcebddebeebedaecccbdcbcedbdaeaedcdebeecdaaedaacadbdccabddaddacdddc"
	T := "bcddceeeebecbc"
	//S := "babgbag"
	//T := "bag"
	fmt.Println(numDistinct(S, T))
}
