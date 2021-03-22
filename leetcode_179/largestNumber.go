package main

import "fmt"

// reverse 反转一个数组
func reverse(num []int) {
    i := 0
    j := len(num) - 1
    for i < j {
        num[i], num[j] = num[j], num[i]
        i++
        j--
    }
}

// split 将数字转为数组
func split(num int) []int {
    if num == 0 {
        return []int{0}
    }
    res := make([]int, 0)
    for num > 0 {
        res = append(res, num % 10)
        num /= 10
    }
    reverse(res)
    return res
}

// 比较两个数组的大小，0 < empty < 1 < 2 < 3 < 4 < 5 < 6 < 7 < 8 < 9
func less_arr(a []int, b []int) bool {
    total_len := len(a) + len(b)
    for i := 0; i < total_len; i++ {
        var t1, t2 int
        if i < len(a) {
            t1 = a[i]
        } else {
            t1 = b[i - len(a)]
        }
        if i < len(b) {
            t2 = b[i]
        } else {
            t2 = a[i - len(b)]
        }
        if t1 < t2 {
            return true
        }
        if t1 > t2 {
            return false
        }
    }
    return false
}

// to_string []int转为string
func to_string(nums []int) string {
    if len(nums) == 0 {
        return ""
    }
    str := make([]byte, len(nums))
    for i := 0; i < len(nums); i++ {
        str[i] = byte('0' + nums[i])
    }
    return string(str)
}

func partition(a [][]int, l int, h int) int {
    if l >= h {
        return l
    }
    i := l + 1
    j := h
    p := l
    for i < j {
        for i <= h && !less_arr(a[p], a[i]) {
            i++
        }
        for j > l && !less_arr(a[j], a[p]) {
            j--
        }
        if i < j {
            a[i], a[j] = a[j], a[i]
        }
        if i >= j {
            break
        }
    }

    if less_arr(a[j], a[p]) {
        a[p], a[j] = a[j], a[p]
    }
    return j
}

func quickSort(a [][]int, s int, e int) {
    if s >= e {
        return
    }
    p := partition(a, s, e)

    quickSort(a, s, p-1)
    quickSort(a, p+1, e)
}

func Quick(a [][]int) {
    quickSort(a, 0, len(a)-1)
}

func largestNumber(nums []int) string {
    res := ""
    if len(nums) == 0 {
        return res
    }
    tnums := make([][]int, 0)
    for i := 0; i < len(nums); i++ {
        tnums = append(tnums, split(nums[i]))
    }
    Quick(tnums)
    for i := len(tnums) - 1; i >= 0; i-- {
        res += to_string(tnums[i])
    }
    if res[0] == '0' {
        return "0"
    }
    return res
}

func main() {
    t1 := []int{111311, 1113}
    t2 := []int{3, 30}
    fmt.Println(largestNumber(t1))
    fmt.Println(largestNumber(t2))
}
