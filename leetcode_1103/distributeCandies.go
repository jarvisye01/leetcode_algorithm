package main

import "fmt"

func distributeCandies(candies int, num_people int) []int {
	res := make([]int, num_people)
	candy := 1
	for candies > 0 {
		for i := 1; i <= num_people; i++ {
			if candies >= candy {
				candies -= candy
				res[i - 1] += candy
				candy++
			} else {
				res[i - 1] += candies
				candies = 0
			}
		}
	}
	return res
}

func main() {
	fmt.Println(distributeCandies(20, 4))
}
