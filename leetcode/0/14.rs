use std::cmp;
use std::usize;

pub fn longest_common_prefix(strs: Vec<String>) -> String {
    if strs.len() == 0 {
        return "".to_string();
    } 

    let gauge = strs[0].clone();
    let gauge_len = gauge.len();
    let mut res = usize::MAX;

    for s in &strs{
        let inx = cmp::min(gauge_len, s.len());
        res = cmp::min(res, inx);


        if res == 0 {
            break;
        }


        for i in 0..inx{
            if s.as_bytes()[i] != gauge.as_bytes()[i] {
                res = cmp::min(res, i);
                break;
            }
        }


        if res == 0 {
            break;
        }
    }
    // println!("{}", res);
    gauge[0..res].to_string()
}

pub fn main() {
    let strs = vec!["aaa".to_string(), "aa".to_string(), "aaa".to_string()];
    // let strs = vec!["a".to_string()];
    println!("{}", longest_common_prefix(strs));
}
