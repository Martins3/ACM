package main

import (
	"fmt"
	"sort"
)

func findUnsortedSubarray(nums []int) int {
	c := make([]int, len(nums))
	copy(c, nums)
	sort.Ints(c)
	i := 0
	for ; i < len(nums); i++ {
		if c[i] != nums[i] {
			break
		}
	}

	j := len(nums) - 1
	for ; j >= i; j-- {
		if c[j] != nums[j] {
			break
		}
	}

	return j - i + 1
}

func main() {
	a := []int{2, 6, 4, 8, 10, 9, 15}
	fmt.Println(findunsortedsubarray(a))
}
