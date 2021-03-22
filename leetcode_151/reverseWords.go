package main

import "fmt"

func reverseWords(s string) string {
    if len(s) == 0 {
        return s
    }
    res := ""
    i := 0
    j := 0
    for ; i < len(s); i++ {
        for i < len(s) && s[i] == ' ' {
            i++
        }
        for j = i; j < len(s) && s[j] != ' '; j++ {
        }
        if i >= len(s) {
            break
        }
        res = s[i : j] + " " + res
        i = j
    }
    if len(res) == 0 {
        return res
    }
    return res[ : len(res) - 1]
}

func main() {
    res := reverseWords("the sky is blue")
    fmt.Println(res)
}
