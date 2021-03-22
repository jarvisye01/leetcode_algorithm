package main

import "fmt"

func convertToTitle(n int) string {
    convertMap := map[int]byte {
        1: 'A',
        2: 'B',
        3: 'C',
        4: 'D',
        5: 'E',
        6: 'F',
        7: 'G',
        8: 'H',
        9: 'I',
        10: 'J',
        11: 'K',
        12: 'L',
        13: 'M',
        14: 'N',
        15: 'O',
        16: 'P',
        17: 'Q',
        18: 'R',
        19: 'S',
        20: 'T',
        21: 'U',
        22: 'V',
        23: 'W',
        24: 'X',
        25: 'Y',
        26: 'Z',
    }

    t := n
    res := ""
    for t > 0 {
        tt := t % 26
        if tt == 0 {
            res = string(convertMap[26]) + res
            t = t / 26 - 1
        } else {
            res = string(convertMap[tt]) + res
            t = t / 26
        }
    }
    return res
}

func main() {
    for i := 1; i <= 1000; i++ {
        fmt.Println(i, "->", convertToTitle(i))
    }
}