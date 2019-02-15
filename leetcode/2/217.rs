use std::collections::HashMap;

pub fn contains_duplicate(nums: Vec<i32>) -> bool {
    let mut m = HashMap::new();

    for i in &nums {
        match m.get(i).cloned() {
            Some(x) => m.insert(*i, x + 1),
            None => m.insert(*i, 1),
        };
    }

    // print!("{:?}", m);

    for (_, value) in m {
        if value > 1 {
            return true;
        }
    }

    return false;
}

pub fn main() {
    let v = vec![1, 2, 3, 1];
    print!("{}", contains_duplicate(v));
}
