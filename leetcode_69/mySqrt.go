package main

import (
	"fmt"
	"math"
)

func mySqrt(x int) int {
	res := int(math.Floor(math.Sqrt(float64(x))))
	return res
}

func sqrt(x int) int {
	for i := 0; i <= x; i++ {
		if i * i == x {
			return i
		}
		if i * i < x && (i + 1) * (i + 1) > x {
			return i
		}
	}
	return -1
}

func sqrt2(x int) int {
	lo := 0
	hi := x
	for lo <= hi {
		mid := lo + (hi - lo) / 2
		if mid * mid == x {
			return mid
		} else if mid * mid < x {
			lo = mid + 1
		} else {
			hi = mid - 1
		}
	}
	return lo - 1
}

func main() {
	fmt.Println(mySqrt(8))
	for i := 0; i < 100; i++ {
		fmt.Printf("right: %d   test: %d\n", mySqrt(i), sqrt2(i))
	}
}
