package main

import "fmt"

/**
* 定义一个矩形类
*/
type rec struct {
	length int
	width int
}

// 获取较大的int
func getMax(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// 获取较小的int
func getMin(a, b int) int {
	if a < b {
		return a
	}
	return b
}

/**
* 求最大举行的面积
* @param [][]byte byte数组
* @return int max area
 */
func maximalRectangle(matrix [][]byte) int {
	M := len(matrix)
	if M == 0 {
		return 0
	}
	N := len(matrix[0])
	max_area := 0
	area := make([][]rec, M + 1)
	for i := 0; i < M + 1; i++ {
		area[i] = make([]rec, N + 1)
	}
	zero_rec := rec{0, 0}

	for i := 1; i < M + 1; i++ {
		for j := 1; j < N + 1; j++ {
			if matrix[i - 1][j - 1] == '1' {
				area[i][j] = rec{area[i][j - 1].length + 1, area[i - 1][j].width + 1}
				minWidth := area[i][j].width
				k := j
				for ; k >= 1; k-- {
					if matrix[i - 1][k - 1] == '0' {
						break
					}
					minWidth = getMin(minWidth, area[i][k].width)
					l := 0
					for ; l < minWidth; l++ {
						if area[i - l][j].length < j - k + 1 {
							break
						}
						max_area = getMax(max_area, (l + 1) * (j - k + 1))
					}
				}
			} else {
				area[i][j] = zero_rec
			}
		}
	}
	return max_area
}

func main() {
	//test := [][]byte{
	//	{'1','0','1','0','0'},
	//	{'1','0','1','1','1'},
	//	{'1','1','1','1','1'},
	//	{'1','0','0','1','0'},
	//}

	test := [][]byte{
		{'1'},
		{'1'},
	}

	fmt.Println(maximalRectangle(test))
}
