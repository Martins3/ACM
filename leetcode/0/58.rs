/**
 * 1. add one space at the end
 * 2. multiple space act like just one
 *
 */

pub fn length_of_last_word(s: String) -> i32 {
    let bytes = s.as_bytes();
    let mut l = 0;
    let mut r = 0;
    let mut len = 0;
    let mut last_is_space = true;

    for &item in bytes.iter() {
        if item == b' ' {
            if !last_is_space {
                last_is_space = true;
                len = r - l;
                l = r;
            }
            l = l + 1;
            r = r + 1;
        } else {
            last_is_space = false;
            r = r + 1;
        }
    }

    if r - l != 0{
        r - l
    }else{
        len
    }
}

pub fn main() {
    println!("{}", length_of_last_word("a".to_string()));
}
