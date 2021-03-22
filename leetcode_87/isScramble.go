package main

import (
    "fmt"
    "strings"
    "time"
)

func recurse(str []string, target string) bool {
    if len(str) == 1 {
        return str[0] == target
    }

    var flag1 bool
    var flag2 bool
    for i := 0; i < len(str) - 1; i++ {
        ts_1 := str[i] + str[i + 1]
        ts_2 := str[i + 1] + str[i]
        flag1 = strings.Contains(target, ts_1)
        flag2 = strings.Contains(target, ts_2)
        if flag1 || flag2 {
            break
        }
    }

    if !flag1 && !flag2 {
        return false
    }

    for i := 0; i < len(str) - 1; i++ {
        ts_1 := str[i] + str[i + 1]
        ts_2 := str[i + 1] + str[i]
        f1 := strings.Contains(target, ts_1)
        f2 := strings.Contains(target, ts_2)

        if !f1 && !f2 {
            continue
        }

        nstr := make([]string, len(str) - 1)

        for j := 0; j < i; j++ {
            nstr[j] = str[j]
        }

        for j := i + 1; j < len(str) - 1; j++ {
            nstr[j] = str[j + 1]
        }

        if f1 {
            nstr[i] = ts_1
            if recurse(nstr, target) {
                return true
            }
            if len(ts_1) > 2 {
                return false
            }
        }
        if f2 {
            nstr[i] = ts_2
            if recurse(nstr, target) {
                return true
            }
            if len(ts_2) > 2 {
                return false
            }
        }
    }
    return false
}

func isScramble(s1 string, s2 string) bool {
    str := []string{}

    for i := 0; i < len(s2); i++ {
        str = append(str, s2[i : i + 1])
    }

    return recurse(str, s1)
}

func main() {
    //fmt.Println(isScramble( "abcea", "abace"))
    fmt.Println(time.Now())
    //fmt.Println(isScramble( "abcdefghijklmnopq", "efghijklmnoopcadb"))
    fmt.Println(isScramble( "ccabcbabcbabbbbcbb", "bbbbabccccbbbabcba"))
    //fmt.Println(isScramble( "abc", "bac"))
    fmt.Println(time.Now())
}
