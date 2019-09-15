impl Solution {
  
         fn find_min_help(nums: Vec<i32>) -> i32 {
        // mountain with only one number ?
        let mut l = 0;
        let mut r = nums.len() - 1;

        while l + 1 < r {
            let m = (l + r) / 2;
            if nums[m] >= nums[l] {
                if nums[m + 1] > nums[l] {
                    l = m + 1;
                }else {
                    return nums[m + 1];
                }
            }else{
                r = m;
            }
        }
        nums[r]
    }

    pub fn find_min(nums: Vec<i32>) -> i32 {
        // mountain with only one number ?
        if nums.len() == 0 as usize {
            -1
        } else if nums.len() ==1 as usize{
            nums[0]
        }else if nums[0] < nums[nums.len() - 1 as usize] {
            nums[0]
        }else{
            Self::find_min_help(nums)
        }
    }


}
