package main

import (
	"fmt"
	"sort"
)

func buddyStrings(A string, B string) bool {
	if len(A) != len(B) {
		return false
	}

	L := len(A)

	if L < 2 {
		return false
	}

	index := []int{0, 0}
	counter := 0
	for i := 0; i < L; i++ {
		if A[i] != B[i] {
			if counter == 2 {
				return false
			}
			index[counter] = i
			counter++
		}
	}

	if counter == 1 {
		return false
	} else if counter == 0 {
		A = SortStringByCharacter(A)
		for i := 1; i < L; i++ {
			if A[i] == A[i-1] {
				return true
			}
		}

		return false
	} else {
		if A[index[0]] != B[index[1]] || A[index[1]] != B[index[0]] {
			return false
		}
		return true
	}

}
func StringToRuneSlice(s string) []rune {
	var r []rune
	for _, runeValue := range s {
		r = append(r, runeValue)
	}
	return r
}

func SortStringByCharacter(s string) string {
	r := StringToRuneSlice(s)
	sort.Slice(r, func(i, j int) bool {
		return r[i] < r[j]
	})
	return string(r)
}

func main() {
	a := "ab"
	b := "ab"
	c := buddyStrings(a, b)
	fmt.Println(c)
}
