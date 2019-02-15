fn main() {}

pub fn read_binary_watch(num: i32) -> Vec<String> {
    let mut r: Vec<String> = vec![];
    if num < 0 || num > 10 {
        return r;
    }

    r
}

fn find_out() {}

fn get_string(h: i32, m: i32) -> String {
    assert!(h >= 0 && h <= 11);
    assert!(m >= 0 && h <= 59);
    let mut bytes = vec![];
    if h == 11 {
        bytes.push(b'0' + 1);
        bytes.push(b'0' + 1);
    } else {
        bytes.push(b'0' + h as u8);
    }
    bytes.push(b':');

    if m < 10 {
        bytes.push(b'0');
    } else {
        bytes.push(b'0' + (m / 10) as u8)
    }
    bytes.push(b'0' + (m % 10) as u8);

    let s = String::from_utf8(bytes).expect("Found invalid UTF-8");

    println!("{}", s);
    s
}
