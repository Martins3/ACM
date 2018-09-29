package main

import "fmt"

func maximalSquare(matrix [][]byte) int {
	dp := make([][]byte, len(matrix))

	for i := 0; i < len(matrix); i++ {
		dp[i] = make([]byte, len(matrix[i]))
		copy(dp[i], matrix[i])
	}
	return 1
}

func main() {
	var matrix [][]int = [][]int{{1, 1, 1}, {1, 1, 0}}
	fmt.Println(matrix)
}
