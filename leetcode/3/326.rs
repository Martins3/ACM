pub fn is_power_of_three(n: i32) -> bool {
    let mut n = n;
    if n<=0 {
            return false;
        }
        while n>1 {
            if n%3!=0 {
                return false;
            }
            n  = n / 3;
        }
        return true;
}
