package main

import "sort"

func getRes(arr []int, target int, total int, start int, path []int, res *[][]int) {
    if total > target {
        return
    }
    if total == target {
        t := make([]int, len(path))
        copy(t, path)
        *res = append(*res, t)
        return
    }

    for i := start; i < len(arr); i++ {
        if total + arr[i] > target {
            continue
        }
        path = append(path, arr[i])
        getRes(arr, target, total + arr[i], i, path, res)
        path = path[ : len(path) - 1]
    }
}

// combinationSum: 重点是先进行一次排序，并且不回头查看
func combinationSum(candidates []int, target int) [][]int {
    res := make([][]int, 0)
    sort.Ints(candidates)
    getRes(candidates, target, 0, 0, []int{}, &res)
    return res
}
