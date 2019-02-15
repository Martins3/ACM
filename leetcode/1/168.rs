const NUM: i32 = 26;
pub fn convert_to_title(n: i32) -> String {
    let mut v = Vec::new();
    let mut n = n;
    loop {
        v.push(n % NUM);
        n = n / NUM;
        if n == 0 {
            break;
        }
    }

    let len = v.len();
    println!("{:?}", v);
    for i in 0..len{
        if v[i] <= 0 {
            if i != len - 1 {
                v[i] += 26;
                v[i + 1] = v[i + 1] - 1;
            }else if v[i] < 0 {
                panic!("I am annoyed!");
            }
        }
    }
    println!("{:?}", v);
    let mut s = String::new();
    
    while v[v.len() - 1] == 0 {
        v.pop();
    }
    println!("{:?}", v);

    for i in (0..v.len()).rev(){
        if v[i] == 0 {
            panic!("Fuck, why need so much time !");
        }
        s.push((v[i] as u8 + b'A' - 1) as char);
    }
    println!("{:?}", s);
    s
}

fn main() {
    println!("{}", convert_to_title(27));
}

