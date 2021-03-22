package main

import "fmt"

func isInterleave(s1 string, s2 string, s3 string) bool {
	L1 := len(s1)
	L2 := len(s2)
	L3 := len(s3)

	if L1 + L2 != L3 {
		return false
	}

	var i int
	var j int
	var k int

	for ; k < L3; k++ {
		if i < L1 && j < L2 {
			if s3[k] == s1[i] {
				i++
			} else if s3[k] == s2[j] {
				j++
			} else {
				return false
			}
		} else if i < L1 {
			if s3[k] == s1[i] {
				i++
			} else {
				return false
			}
		} else if j < L2 {
			if s3[k] == s2[j] {
				j++
			} else {
				return false
			}
		}
	}
	return true
}

func main() {
	//fmt.Println(solution())
	//res, min := test()
	//fmt.Printf("%d %d\n", min, len(res))
	//for i := 0; i < len(res); i++ {
	//	if i != len(res) - 1 {
	//		fmt.Printf("[%d,%d] ", res[i][0], res[i][1])
	//	} else {
	//		fmt.Printf("[%d,%d]\n", res[i][0], res[i][1])
	//	}
	//}
	fmt.Println(isInterleave("aabcc", "dbbca", "aadbbcbcac"))
}

//func getMax(a, b int) int {
//	if a > b {
//		return a
//	}
//	return b
//}
//
//func solution() int {
//	N := 0
//	fmt.Scan(&N)
//	if N == 0 {
//		return 0
//	}
//	arr := make([]int, N)
//	for i := 0; i < N; i++ {
//		fmt.Scan(&arr[i])
//	}
//	sum1 := 0
//	sum2 := 0
//	var entrance int = 0
//	var first int
//	var back int
//	for i := 0; i < N; i++ {
//		if arr[i] > arr[entrance] {
//			entrance = i
//		}
//	}
//	sum1 += arr[entrance]
//	first = (entrance + N - 1) % N
//	back = (entrance + 1) % N
//
//	flag := true
//	t := N - 1
//	for t > 0 {
//		if flag {
//			if arr[first] > arr[back] {
//				sum2 += arr[first]
//				first = (first + N - 1) % N
//			} else {
//				sum2 += arr[back]
//				back = (back + 1) % N
//			}
//		} else {
//			if arr[first] > arr[back] {
//				sum1 += arr[first]
//				first = (first + N - 1) % N
//			} else {
//				sum1 += arr[back]
//				back = (back + 1) % N
//			}
//		}
//		t--
//		flag = !flag
//	}
//
//	if sum1 > sum2 {
//		return sum1 - sum2
//	} else {
//		return sum2 - sum1
//	}
//}
//
//func test() ([][]int, int) {
//	res := make([][]int, 0)
//
//	N := 0
//	fmt.Scan(&N)
//	m := map[int]bool{}
//	tm := map[int]int{}
//	arr := make([]int, N)
//	for i := 0; i < N; i++ {
//		fmt.Scan(&arr[i])
//		m[arr[i]] = true
//	}
//	slow := 0
//	fast := 0
//	for len(m) > 0 {
//		tm[arr[fast]]++
//		if m[arr[fast]] {
//			delete(m, arr[fast])
//			if len(m) == 0 {
//				break
//			}
//		}
//		for slow < fast && tm[arr[slow]] > 1 {
//			tm[arr[slow]]--
//			slow++
//		}
//		fast++
//	}
//	res = append(res, []int{slow + 1, fast + 1})
//	min := fast - slow + 1
//
//	target := arr[slow]
//	tm[arr[slow]]--
//	slow++
//	fast++
//	for fast < N {
//		if arr[fast] != target {
//			tm[arr[fast]]++
//			fast++
//			for slow < fast && tm[arr[slow]] > 1 {
//				tm[arr[slow]]--
//				slow++
//			}
//		} else {
//			if fast - slow + 1 == min {
//				res = append(res, []int{slow + 1, fast + 1})
//			} else if fast - slow + 1 < min {
//				min = fast - slow + 1
//				res = make([][]int, 0)
//				res = append(res, []int{slow + 1, fast + 1})
//			}
//			target = arr[slow]
//			tm[arr[slow]]--
//			slow++
//			fast++
//		}
//	}
//	return res, min
//}


//20
//6 1 1 8 1 6 1 1 6 7 1 6 1 1 8 6 7 1 6 1
