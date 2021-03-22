package main

import (
    "fmt"
)

func getSpaces(n int) string {
    res := ""
    for i := 0; i < n; i++ {
        res += " "
    }
    return res
}

func getRow(s []string, w int, wl int) string {
    if len(s) == 1 {
        return s[0] + getSpaces(w - len(s[0]))
    }

    N := len(s) - 1
    baseSpace := (w - wl) / N
    extraSpace := (w - wl) % N

    res := ""
    for i := 0; i < len(s) - 1; i++ {
        if i < extraSpace {
            res += s[i] + getSpaces(baseSpace + 1)
        } else {
            res += s[i] + getSpaces(baseSpace)
        }
    }
    if len(s) > 1 {
        res += s[len(s) - 1]
    }
    return res
}

func fullJustify(words []string, maxWidth int) []string {
    res := []string{}

    tl := 0
    row := []string{}
    for i := 0; i < len(words); i++ {
        if tl + len(words[i]) + len(row) <= maxWidth {
            tl += len(words[i])
            row = append(row, words[i])
        } else {
            res = append(res, getRow(row, maxWidth, tl))
            tl = len(words[i])
            row = []string{words[i]}
        }
    }

    if len(row) > 0 {
        last := ""
        for idx, item := range row {
            if idx < len(row) - 1 {
                last += item + " "
            } else {
                last += item
            }
        }
        res = append(res, last + getSpaces(maxWidth - len(last)))
    }
    return res
}


func main() {
    fmt.Println(getRow([]string{"test", "ok", "adasda"}, 20, 12))
    //res := fullJustify([]string{"Science","is","what","we","understand","well","enough","to","explain", "to","a","computer.","Art","is","everything","else","we","do"}, 20)
    res := fullJustify([]string{"What","must","be","acknowledgment","shall","be"}, 16)
    for _, item := range res {
        fmt.Println(len(item))
    }
    fmt.Println(len("do                  "))
}
