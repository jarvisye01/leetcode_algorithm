package main

func myMerge(A []int, m int, B []int, n int)  {
	i := m -1
	j := n - 1
	tail := len(A) - 1
	for i >= 0 && j >= 0 {
		if A[i] > B[j] {
			A[tail] = A[i]
			i--
		} else {
			A[tail] = B[j]
			j--
		}
		tail--
	}

	for j >= 0 {
		A[tail] = B[j]
		j--
		tail--
	}
}

func merge(nums1 []int, m int, nums2 []int, n int)  {
	myMerge(nums1, m, nums2, n)
}

func main() {

}
