impl Solution {
    fn binary_search(nums: &Vec<i32>, target: i32, left: usize, right: usize) -> i32 {
        let mut l = left;
        let mut r = right;
        while l < r {
            let m = (l + r) / 2;
            if nums[m] >= target {
                r = m
            } else {
                l = m + 1
            }
        }

        if l == right || nums[l] != target {
            -1
        } else {
            l as i32
        }
    }

    fn find_min_help(nums: &Vec<i32>) -> usize {
        // mountain with only one number ?
        let mut l = 0;
        let mut r = nums.len() - 1;

        while l + 1 < r {
            let m = (l + r) / 2;
            if nums[m] >= nums[l] {
                if nums[m + 1] > nums[l] {
                    l = m + 1;
                } else {
                    return m + 1;
                }
            } else {
                r = m;
            }
        }
        r
    }

    pub fn search(nums: Vec<i32>, target: i32) -> i32 {
        // mountain with only one number ?
        if nums.len() == 0 as usize {
            -1
        } else if nums.len() == 1 as usize {
            if nums[0] == target {
                0
            } else {
                -1
            }
        } else if nums[0] < nums[nums.len() - 1 as usize] {
            Self::binary_search(&nums, target, 0, nums.len())
        } else {
            let l = Self::find_min_help(&nums);
            let a = Self::binary_search(&nums, target, 0, l);
            let b = Self::binary_search(&nums, target, l, nums.len());

            if a != -1 {
                a
            } else if b != -1 {
                b
            } else {
                -1
            }
        }
    }
}
