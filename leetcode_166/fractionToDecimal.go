package main

import (
    "fmt"
    "strconv"
)

func abs(x int) int {
    if x >= 0 {
        return x
    }
    return -x
}

func fractionToDecimal(numerator int, denominator int) string {
    if numerator == 0 {
        return "0"
    }
    flag := ""
    if numerator * denominator < 0 {
        flag = "-"
    }
    numerator, denominator = abs(numerator), abs(denominator)

    intPart := numerator / denominator
    if intPart * denominator == numerator {
        return flag + strconv.Itoa(intPart)
    }

    floatPart := ""
    a := numerator - intPart * denominator
    b := denominator

    t := (a * 10) / b
    m := map[int]int{}
    pos := 0
    for {
        floatPart = floatPart + strconv.Itoa(t)
        if (a * 10) % b == 0 {
            break
        }
        m[pos] = (a * 10) % b
        pos++
        // 找到重复出现的数字，并且余数相等就是出现了循环
        number := floatPart[len(floatPart) - 1]
        for i := len(floatPart) - 2; i >= 0; i-- {
            if number == floatPart[i] && m[i] == m[pos - 1] {
                floatPart = floatPart[ : i] + "(" +floatPart[i : pos - 1] + ")"
                return flag + strconv.Itoa(intPart) + "." + floatPart
            }
        }
        a = (a * 10) - t * b
        t = (a * 10) / b
    }
    return flag + strconv.Itoa(intPart) + "." + floatPart
}

func main() {
    fmt.Println(1.0 / 17.0)
    t1 := fractionToDecimal(1, 2)
    t2 := fractionToDecimal(8, 7)
    t3 := fractionToDecimal(1, 17)
    fmt.Println(t1)
    fmt.Println(t2)
    fmt.Println(t3)
}
