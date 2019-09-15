pub struct Solution {}

impl Solution {
    // lower_bound's meaning : first one equal or bigger
    fn lower_bound(num :& Vec<i32> , target : i32) -> i32{
        // init
        let mut left = 0;
        let mut right = num.len(); // right is open
        
        // leave the loop
        while left < right {
            let mid = (left + right ) / 2;

            // assign 
            if num[mid] >= target  {
                right = mid;
            } else{
                left = mid + 1;
            }
        }

        
        // TODO last compare ?
        left as i32
    }

    // first one bigger 
    fn uppper_bound(num : & Vec<i32> , target : i32 ) -> i32{
        let mut left = 0;
        let mut right = num.len() ;
        
        // leave the loop
        while left < right {
            let mid = (left + right ) / 2;

            // assign 
            if num[mid] > target  {
                right = mid;
            } else{
                left = mid + 1;
            }
        }
        left as i32
    }

    pub fn search_range(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut res = vec![];
        let len = nums.len() as i32;
        let l = Self::lower_bound(&nums , target);
        if l == len  || nums[l as usize] != target{
            res.push(-1);
            res.push(-1);
            return res;
        }

        res.push(l);
        res.push(Self::uppper_bound(&nums , target) -1);
        res
    }
}

fn main() {
    let me = vec![5,7,7,8,8,10];
    let target = 6;
    
    let s =  Solution::search_range(me, target);
    println!("{:?}", s);
}
