package main

import "fmt"

func rotate(nums []int, k int) {
	L := len(nums)
	if L == 0 {
		return
	}

	k = k % L

	if k == 0 {
		return
	}

	sup := make([]int, k)
	copy(sup[:], nums[L-k:L])
	// fmt.Println(sup)

	for i := L - 1; i >= k; i-- {
		nums[i] = nums[i-k]
	}

	for i := 0; i < k; i++ {
		nums[i] = sup[i]
	}
}

func main() {
	nums := []int{1, 2, 3, 4, 5, 6, 7}
	fmt.Println(nums)
	rotate(nums, 3)
	fmt.Println(nums)
}
