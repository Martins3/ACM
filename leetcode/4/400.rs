fn main() {
    // for i in 0..=100 {
    // if i % 10 == 0 {
    // println!();
    // }
    // print!("[{}] ", find_nth_digit(i));
    // }
    print!("[{}] ", find_nth_digit(2147483647));
    print!("[{}] ", find_nth_digit(999999999));
}

pub fn find_nth_digit(n: i32) -> i32 {
    if n == 0 {
        return n;
    }

    let gauge: Vec<i32> = vec![
        10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000,
    ];
    let length: Vec<i32> = vec![1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
    // n --> len
    let mut n = n;
    let mut sum = 0;
    for i in 0..10 {
        if i == 8 || n < (gauge[i] - sum) * length[i] {
            // find out it
            let len = i as i32 + 1;
            let mut num = n / len;
            let index = n % len;
            // if index != 0 {
            // num = num + 1;
            // }

            if i != 0 {
                // rethink here
                num = num + gauge[i - 1];
            }

            let mut stack: Vec<i32> = vec![];
            // println!("{}", num);

            while num != 0 {
                stack.push(num % 10);
                num = num / 10;
            }

            // println!("{:?}", stack);
            // 0 is the end
            stack.reverse();
            return stack[index as usize];
        } else {
            n = n - (gauge[i] - sum) * length[i];
            // rethink here
            sum = gauge[i];
        }
    }
    panic!("what's wrong with your head !");
}
