package main

import "fmt"

/**
* 从s这个字符串中得到字符和字符个数的映射
* @param string
* @return map[uint8]int
*/
func getSet(s string) map[uint8]int {
	m := map[uint8]int{}
	N := len(s)
	for i := 0; i < N ; i++ {
		m[s[i]]++
	}
	return m
}

/**
* 判断m这个map是不是ch_set的超集
* @param map[uint8]int
* @param map[uint8]int
* @return bool
*/
func isFull(m map[uint8]int, ch_set map[uint8]int) bool {
	for k, v := range ch_set {
		if m[k] < v {
			return false
		}
	}
	return true
}

/**
* 从s中获取包含t的最小子串的封装
* @param string
* @param string
* @param map[uint8]int t中的字符与字符个数的映射
* @return string
*/
func getMinWindow(s string, t string, ch_set map[uint8]int) string {
	var i, j int
	N := len(s)
	m := map[uint8]int{}
	m_t := map[uint8]int{}
	res := ""

	for ; j < N; j++ {
		if _, ok := ch_set[s[j]]; ok {
			m[s[j]] = m[s[j]] + 1
			if m[s[j]] >= ch_set[s[j]] {
				m_t[s[j]] = m[s[j]]
			}
			for ;  i <= j && len(m_t) == len(ch_set); i++ {
				if _, ok := ch_set[s[i]]; ok {
					if j - i < len(res) || res == "" {
						res = s[i : j + 1]
					}
					m[s[i]] = m[s[i]] - 1
					if m[s[i]] < ch_set[s[i]] {
						delete(m_t, s[i])
					}
				}
			}
		}
	}
	return res
}

/**
* 从s中获取包含t的最小子串
* @param string
* @param string
* @return string
 */
func minWindow(s string, t string) string {
	ch_set := getSet(t)
	return getMinWindow(s, t, ch_set)
}

func main() {
	fmt.Println(minWindow("aa", "aa"))
}