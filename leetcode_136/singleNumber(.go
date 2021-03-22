package main

func singleNumber(nums []int) int {
    m := map[int]bool{}
    for _, num := range nums {
        if m[num] {
            delete(m, num)
        } else {
            m[num] = true
        }
    }
    res := 0
    for k, _ := range m {
        res = k
    }
    return res
}

func main() {

}
