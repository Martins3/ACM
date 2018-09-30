package main

import (
	"container/heap"
	"fmt"
	"sort"
)

type IntHeap []int

func (h IntHeap) Len() int           { return len(h) }
func (h IntHeap) Less(i, j int) bool { return h[i] > h[j] }
func (h IntHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }
func (h *IntHeap) Peek() int         { return (*h)[0] }

func (h *IntHeap) Push(x interface{}) {
	*h = append(*h, x.(int))
}

func (h *IntHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

func main() {
	k := 3
	nums := []int{1, 2, 10, 6}

	obj := Constructor(k, nums)
	param_1 := obj.Add(5)
	fmt.Println(param_1)
}

type KthLargest struct {
	a *IntHeap
}

func Constructor(k int, nums []int) KthLargest {
	sort.Slice(nums, func(i, j int) bool {
		return nums[i] < nums[j]
	})
	// fmt.Println(nums)
	h := &IntHeap{}
	for i := 0; i < k; i++ {
		heap.Push(h, nums[i])
	}
	// for h.Len() > 0 {
	// fmt.Printf("%d ", heap.Pop(h))
	// }
	return KthLargest{h}
}

func (this *KthLargest) Add(val int) int {
	top := this.a.Peek()
	if val >= top {
		return top
	} else {
		this.a.Push(val)
		this.a.Pop()
		return this.a.Peek()
	}
}

/**
 * Your KthLargest object will be instantiated and called as such:
 */
