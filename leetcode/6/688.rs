impl Solution {
    pub fn knight_probability(n: i32, k: i32, r: i32, c: i32) -> f64 {
        let mut x_wei = vec![vec![0 as f64; n as usize]; n as usize];
        let mut y_wei = vec![vec![0 as f64; n as usize]; n as usize];

        x_wei[r as usize][c as usize] = 1f64;

        let clear = |v: &mut Vec<Vec<f64>>| {
            for i in 0..n as usize {
                for j in 0..n as usize {
                    v[i][j] = 0f64;
                }
            }
        };
        for i in 0..k {
            if i % 2 == 0 {
                clear(&mut y_wei); // here
                for a in 0..n {
                    for b in 0..n {
                        let di = |i: i32, j: i32| -> f64 {
                            let out = |x: i32, y: i32| {
                                if x < 0 || x >= n || y < 0 || y >= n {
                                    true
                                } else {
                                    false
                                }
                            };
                            if !out(a + i, b + j) {
                                x_wei[(a + i) as usize][(b + j) as usize] // here
                            } else {
                                0f64
                            }
                        };

                        let mut p = 0f64;
                        p += di(2, 1);
                        p += di(2, -1);
                        p += di(-2, 1);
                        p += di(-2, -1);

                        p += di(1, 2);
                        p += di(1, -2);
                        p += di(-1, 2);
                        p += di(-1, -2);

                        y_wei[a as usize][b as usize] = p / 8f64; // here
                    }
                }
            } else {
                clear(&mut x_wei); // here
                for a in 0..n {
                    for b in 0..n {
                        let di = |i: i32, j: i32| -> f64 {
                            let out = |x: i32, y: i32| {
                                if x < 0 || x >= n || y < 0 || y >= n {
                                    true
                                } else {
                                    false
                                }
                            };
                            if !out(a + i, b + j) {
                                y_wei[(a + i) as usize][(b + j) as usize] // here
                            } else {
                                0f64
                            }
                        };

                        let mut p = 0f64;
                        p += di(2, 1);
                        p += di(2, -1);
                        p += di(-2, 1);
                        p += di(-2, -1);

                        p += di(1, 2);
                        p += di(1, -2);
                        p += di(-1, 2);
                        p += di(-1, -2);
                        x_wei[a as usize][b as usize] = p / 8f64; // here
                    }
                }
            }
        }

        
        let mut p = 0f64;
        if k % 2 == 0 {
            for i in 0..n as usize {
                for j in 0..n as usize {
                    p += x_wei[i][j];
                }
            }
            p
        }else{
            for i in 0..n as usize {
                for j in 0..n as usize {
                    p += y_wei[i][j];
                }
            }
            p
        }
    }
}

pub struct Solution {}
// @bug 题目理解错误，本来以为是只要到达过就可以，实际上并不是，而是最终的位置才可以
// 以后至少首先吧测试样例分析过之后在开始思路
//
// 走错的可以回来吗 ? 不可以的
//

fn main() {
    // let s = vec![1, 3, 5, 4, 7];
    let s = Solution::knight_probability(8, 30, 6, 4);
    println!("{}", s);
}
