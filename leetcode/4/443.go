package main

type stack []int

func (s stack) Push(v int) stack {
	return append(s, v)
}

func (s stack) Pop() int {
	l := len(s)
	t := s[l-1]
	s = s[:l-1]
	return t
}

func (s stack) empty() bool {
	return len(s) == 0
}

func compress(chars []byte) int {
	if len(chars) == 1 {
		return 1
	}

	last := chars[0]
	res := 0
	acc := 1
	index := 0

	chars = append(chars, chars[len(chars)-1]+1)

	for i := 1; i < len(chars); i++ {
		if chars[i] != last {
			digitLen := 0
			chars[index] = last

			if acc == 1 {
				index++
			} else {

				s := make(stack, 0)
				for acc != 0 {
					s.Push(acc % 10)
					acc = acc / 10
					digitLen++
				}

				for !(s.empty()) {
					chars[index] = s.Pop()
					index++
				}

				if digitLen == 1 {
					digitLen = 0
				}
			}

			res += (1 + digitLen)
			acc = 1
			last = chars[i]
			continue
		} else {
			acc++
		}
	}
	return res
}
func main() {

}
