 pub fn title_to_number(s: String) -> i32 {
     let bytes = s.as_bytes();
     let len = s.len();
     let v:Vec<i32> = vec![1, 26, 676, 17576, 456976, 11881376,308915776];
     
     let mut res = 0;
     for i in 0..len {
         res = res + v[len - i - 1] * (bytes[i] - b'A' + 1) as i32 ;
     }
     res
    }
pub fn main() {
    println!("{}", title_to_number("AB".to_string()));
}
