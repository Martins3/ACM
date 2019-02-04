/**
I             1
V             5
X             10
L             50
C             100
D             500
M             1000

I can be placed before V (5) and X (10) to make 4 and 9.
X can be placed before L (50) and C (100) to make 40 and 90.
C can be placed before D (500) and M (1000) to make 400 and 900.
*/

pub fn roman_to_int(s: String) -> i32 {
    let bytes = s.as_bytes();
    let mut res = 0;
    let len = bytes.len();
    let mut skip = false;

    for i in 0..len {
        if skip {
            skip = false;
            continue;
        }

        let item = bytes[i];
        match item {
            b'I' => {
                if i != len - 1 && bytes[i + 1] == b'V' {
                    skip = true;
                    res += 4;
                } else if i != len - 1 && bytes[i + 1] == b'X' {
                    skip = true;
                    res += 9;
                } else {
                    res += 1;
                }
            }
            b'V' => {
                res += 5;
            }

            b'X' => {
                if i != len - 1 && bytes[i + 1] == b'L' {
                    skip = true;
                    res += 40;
                } else if i != len - 1 && bytes[i + 1] == b'C' {
                    skip = true;
                    res += 90;
                } else {
                    res += 10;
                }
            }

            b'L' => res += 50,

            b'C' => {
                if i != len - 1 && bytes[i + 1] == b'D' {
                    skip = true;
                    res += 400;
                } else if i != len - 1 && bytes[i + 1] == b'M' {
                    skip = true;
                    res += 900;
                } else {
                    res += 100;
                }
            }
            b'D' => res += 500,

            b'M' => res += 1000,
            _ => panic!("Fuck, imposible!"),
        }
    }
    res
}

pub fn main() {
    let a = roman_to_int(String::from("MCMXCIV"));
    println!("{}", a);
}
