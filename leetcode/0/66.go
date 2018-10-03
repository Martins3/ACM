package main

func plusOne(digits []int) []int {
	var carry bool = true
	for i := len(digits) - 1; i >= 0; i-- {
		if carry {
			if digits[i] == 9 {
				carry = true
				digits[i] = 0
			} else {
				digits[i] = digits[i] + 1
				carry = false
			}
		}
	}

	if carry {
		digits = append([]int{1}, digits...)
	}
	return digits
}

func main() {

}
