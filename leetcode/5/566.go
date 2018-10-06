package main

import "fmt"

func main() {
	a := [][]int{{1, 2, 3, 4}}
	fmt.Println(matrixReshape(a, 2, 2))
}

func matrixReshape(nums [][]int, r int, c int) [][]int {
	row := len(nums)
	col := len(nums[0])

	if row*col != r*c {
		return nums
	}

	a := make([][]int, r)

	for i := range a {
		a[i] = make([]int, c)
	}

	for i := 0; i < r*c; i++ {
		// fmt.Println(r, row)
		a[i/c][i%c] = nums[i/col][i%col]
	}

	return a
}
