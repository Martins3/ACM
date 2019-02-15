pub fn two_sum(numbers: Vec<i32>, target: i32) -> Vec<i32> {
    let mut v: Vec<i32> = Vec::new();
    let mut l = 0;
    let mut r = numbers.len() - 1;
    while l < r {
        if numbers[l] + numbers[r] < target {
            l = l + 1;
        }

        else if numbers[l] + numbers[r] > target {
            r = r - 1;
        } 

        else {
            v.push(l as i32 + 1);
            v.push(r as i32 + 1);
            break;
        }
    }
    v
}
pub fn main() {
    let v: Vec<i32> = vec![2,7,11,15];
    println!("{:?}", two_sum(v, 9));
}
