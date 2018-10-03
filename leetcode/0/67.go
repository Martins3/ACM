package main

import "fmt"

func addBinary(a string, b string) string {
	A := reverse(a)
	B := reverse(b)
	if len(A) < len(B) {
		swap(&A, &B)
	}
	carry := false

	var res string

	for i := 0; i < len(A); i++ {
		sum := 0
		if A[i] == '1' {
			sum++
		}

		if i < len(B) && B[i] == '1' {
			sum++
		}

		if carry {
			sum++
		}

		switch sum {
		case 0:
			res += string('0')
			carry = false
		case 1:
			res += string('1')
			carry = false
		case 2:
			res += string('0')
			carry = true
		case 3:
			res += string('1')
			carry = true
		}
	}

	if carry {
		res += string('1')
	}

	return reverse(res)
}

func swap(str1, str2 *string) {
	*str1, *str2 = *str2, *str1
}

func reverse(s string) string {
	r := []rune(s)
	for i, j := 0, len(r)-1; i < len(r)/2; i, j = i+1, j-1 {
		r[i], r[j] = r[j], r[i]
	}
	return string(r)
}

func main() {
	a := "111101"
	b := "100001"
	fmt.Println(addBinary(a, b))
}
