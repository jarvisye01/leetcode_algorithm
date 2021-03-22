package main

func searchMatrix(matrix [][]int, target int) bool {
	r := len(matrix)
	c := len(matrix[0])
	i := r - 1
	j := 0
	for i >= 0 && j < c {
		if target == matrix[i][j] {
			return true
		}
		if target > matrix[i][j] {
			j++
		} else {
			i--
		}
	}
	return false
}

func bSearchMatrix(matrix [][]int, target int) bool {
	M := len(matrix)
	if M == 0 {
		return false
	}
	N := len(matrix[0])
	left := 0
	right := M * N - 1

	for left <= right {
		mid := left + (right - left) / 2
		if matrix[mid / N][mid % N] == target {
			return true
		} else if matrix[mid / N][mid % N] < target {
			left = mid + 1
		} else {
			right = mid - 1
		}
	}
	return false
}

func main() {

}
