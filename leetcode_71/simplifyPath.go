package main

import "fmt"
func resize(str []string, l int, capacity int) []string {
	copy := make([]string, capacity, capacity)
	for i := 0; i < l; i++ {
		copy[i] = str[i]
	}
	return copy
}

//显然除了括号问题，对于路径问题来说，栈也是十分有效处理方式
//栈可以处理的问题的特点就是新出现的元素只对上一个元素有影响
func simplifyPath(path string) string {
	res := ""
	N := len(path)
	if N == 0 {
		return res
	}
	paths := make([]string, 1, 1)
	top := 0

	for i := 0; i < N; i++ {
		if path[i] != '/' {
			var j int
			for j = i; j < N; j++ {
				if path[j] == '/' {
					break
				}
			}
			p := path[i : j]
			if p == ".." {
				if top > 0 {
					if top == len(paths) / 4 {
						paths = resize(paths, top, len(paths) / 4)
					}
					top--
				}
			} else if p != "." {
				if top == len(paths) {
					paths = resize(paths, top, len(paths) * 2)
				}
				paths[top] = p
				top++
			}
			i = j
		}
	}
	if top == 0 {
		return "/"
	}
	for i := 0; i < top; i++ {
		res += "/" + paths[i]
	}
	return res
}


func main() {
	fmt.Println(simplifyPath("/home/of/foo/../../bar/../../is/./here/."))
}
