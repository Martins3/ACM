use std::collections::BTreeMap;

// lost control of reference
pub fn majority_element(nums: Vec<i32>) -> i32 {
    // why should use divide and conquer
    let threshold = nums.len() as i32 / 2;
    let mut scores = BTreeMap::new();
    for i in &nums {
        match scores.get(i).cloned() {
            Some(x) => scores.insert(*i, x + 1),
            None => scores.insert(*i, 1),
        };
    }

    println!("{:?}", scores);

    for (key, value) in &scores {
        // println!("{}: {}", key, value);
        if *value > threshold {
            return *key;
        }
    }
    panic!("You make sure !");
}

fn main() {
    let v = vec![2, 3, 2, 3, 3];
    println!("{}", majority_element(v));
}
