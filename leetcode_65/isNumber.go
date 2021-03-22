package main

import "fmt"

var numbers = map[int32]bool{
	'0': true,
	'1': true,
	'2': true,
	'3': true,
	'4': true,
	'5': true,
	'6': true,
	'7': true,
	'8': true,
	'9': true,
}

func isNumbers(s string) bool {
	for i := 0; i < len(s); i++ {
		if !numbers[int32(s[i])] {
			return false
		}
	}
	return true
}

func isInteger(s string) bool {
	//l := len(s)
	//if l == 0 {
	//	return  false
	//} else if l == 1 {
	//	if numbers[int32(s[0])] {
	//		return true
	//	} else {
	//		return false
	//	}
	//}
	//if int32(s[0]) == '0' {
	//	return false
	//}
	//return isNumbers(s[1 : ])
	return isNumbers(s)
}

func isFloat(s string) bool {
	dotIdx, err := findDotIndex(s)
	if err {
		return false
	}
	if dotIdx == -1 {
		return false
	}
	if dotIdx == 0 && len(s) == 1 {
		return false
	}
	tmp := isNumbers(s[dotIdx + 1 : ])
	if dotIdx == 0 {
		return tmp
	}
	if isInteger(s[ : dotIdx]) && tmp {
		return true
	}
	return false
}

func trim(s string) string {
	start := 0
	end := len(s) - 1

	for start < end {
		if s[start] == ' ' {
			start++
		}
		if s[end] == ' ' {
			end--
		}
		if s[start] != ' ' && s[end] != ' ' {
			break
		}
	}

	if start > end {
		return ""
	}
	return s[start : end + 1]
}

func trimSign(s string) string {
	if len(s) == 0 {
		return s
	}
	if s[0] == '+' || s[0] == '-' {
		return s[1 : ]
	}
	return s
}

func findDotIndex(s string) (int, bool) {
	d_num := 0
	idx := -1
	for i := 0; i < len(s); i++ {
		if s[i] == '.' {
			idx = i
			d_num++
		}
	}
	if d_num == 0 {
		return -1, false
	} else if d_num == 1 {
		return idx, false
	}
	return -1, true
}

func findEIndex(s string) (int, bool) {
	e_num := 0
	idx := -1
	for i := 0; i < len(s); i++ {
		if s[i] == 'e' {
			idx = i
			e_num++
		}
	}
	if e_num == 0 {
		return -1, false
	} else if e_num == 1 {
		return idx, false
	}
	return -1, true
}

func isNumber(s string) bool {
	s = trim(s)
	if len(s) == 0 {
		return false
	} else if len(s) == 1 {
		return isNumbers(s)
	}
	e_idx, err := findEIndex(s)
	if err {
		return false
	}
	if e_idx == -1 {
		d_idx, err := findDotIndex(s)
		if err {
			return false
		}
		s = trimSign(s)
		if len(trimSign(s)) == 0 {
			return false
		}
		if d_idx == -1 {
			return isInteger(s)
		}
		return isFloat(s)
	} else {
		s1 := s[ : e_idx]
		s2 := s[e_idx + 1 : ]
		s1 = trimSign(s1)
		s2 = trimSign(s2)
		if len(s1) == 0 || len(s2) == 0 {
			return false
		}
		return (isFloat(s1) || isInteger(s1)) && isInteger(s2)
	}
	return false
}

func main() {
	//fmt.Println(isInteger("123"))
	//fmt.Println(isInteger("0123"))
	//fmt.Println(isInteger("0"))
	//fmt.Println(isInteger("123 3"))
	//
	//fmt.Println(isFloat("123.3322", 3))
	//fmt.Println(isFloat("1.0", 1))
	//fmt.Println(isFloat("..321", 3))
	fmt.Println(isNumber("-.3e6"))
}
