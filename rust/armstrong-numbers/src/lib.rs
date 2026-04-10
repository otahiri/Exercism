pub fn is_armstrong_number(num: u32) -> bool {
    let mut n: Vec<char> = num.to_string().chars().collect();
    n.reverse();
    let mut sum: u32 = 0;
    for i in 0..n.len() {
        sum += u32::pow(n[i].to_digit(10).unwrap(), n.len() as u32);
    }
    sum == num
}
