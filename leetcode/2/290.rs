use std::collections::HashMap;

pub fn word_pattern(pattern: String, s: String) -> bool {
    let mut m: HashMap<u8, &str> = HashMap::new();
    let mut rm: HashMap<&str, u8> = HashMap::new();

    let split = s.split(" ");
    let vec: Vec<&str> = split.collect();
    let bytes = pattern.as_bytes();
    let len = bytes.len();

    if len != vec.len() {
        return false;
    }

    for i in 0..len {
        match m.get(&bytes[i]).cloned() {
            Some(s) => {
                if s != vec[i]{
                  return false;
                }
            },
            None => {
                m.insert(bytes[i], vec[i]);
            }
        };

        match rm.get(&vec[i]).cloned() {
            Some(s) => {
                if s != bytes[i]{
                  return false;
                }
            },
            None => {
                rm.insert(vec[i], bytes[i]);
            }
        };

    }
    return true;
}

pub fn main() {
    println!(
        "{}",
        word_pattern("abba".to_string(), "dog dog dog dog".to_string())
    );
}
