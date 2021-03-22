package main

import (
    "fmt"
    "strings"
)

func atoi(s string) int {
    res := 0
    i := 0
    for ; i < len(s); i++ {
        if s[i] != '0' {
            break
        }
    }
    for ; i < len(s); i++ {
        res = res * 10 + int(s[i] - '0')
    }
    return res
}

func compareInt(a, b int) int {
    if a == b {
        return 0
    }
    if a > b {
        return 1
    }
    return -1
}

func compareVersion(version1 string, version2 string) int {
    strs_v1 := strings.Split(version1, ".")
    strs_v2 := strings.Split(version2, ".")

    length_v1 := len(strs_v1)
    length_v2 := len(strs_v2)
    i, j := 0, 0

    for ; i < length_v1 && j < length_v2 ; {
        t := compareInt(atoi(strs_v1[i]), atoi(strs_v2[j]))
        if t != 0 {
            return t
        }
        i++
        j++
    }

    for i < length_v1 {
        t := compareInt(atoi(strs_v1[i]), 0)
        if t != 0 {
            return t
        }
        i++
    }

    for j < length_v2 {
        t := compareInt(0, atoi(strs_v2[j]))
        if t != 0 {
            return t
        }
        j++
    }

    return 0
}

func main() {
    a, b := "0.1", "1.1"
    res := compareVersion(a, b)
    fmt.Println(res)
}