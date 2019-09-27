impl Solution {
    pub fn find_number_of_lis(nums: Vec<i32>) -> i32 {
        let len = nums.len();

        if len == 1 {
            1
        } else {
            // len & quantity end with me !
            // 1. last != best
            // 2. alone
            let mut me: Vec<(i32, i32)> = vec![(1, 1); len];

            for i in 1..len {

                for j in 0..i {
                    if nums[i] > nums[j] {
                        if me[i].0 < me[j].0 + 1 {
                            me[i].0 = me[j].0 + 1;
                            me[i].1 = me[j].1;
                        } else if me[i].0 == me[j].0 + 1 {
                            me[i].1 += me[j].1;
                        }
                    }
                }
            }

            let mut m = 0;
            for i in 0..len {
                m = std::cmp::max(m, me[i].0);
            }

    println!("{:?}", me);
            
            let mut res = 0;
            for i in 0..len {
                if m == me[i].0 {
                    res += me[i].1;
                }
            }
            res
        }
    }
}


pub struct Solution {}

fn main() {
    let s = vec![1,3,5,4,7];
    let s = Solution::find_number_of_lis(s);
    println!("{}", s);
}
