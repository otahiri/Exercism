
/// Check a Luhn checksum.
pub fn is_valid(code: &str) -> bool {
    let mut number: Vec<char> = code.replace(" ", "").chars().collect();
    for x in &number {
        if !x.is_digit(10) {
            return false;
        }
    }
    number.reverse();

    if number.len() <= 1 {
        return false;
    }
    for j in 0..number.len() {
        if j % 2 == 1 {
                let res: u32 = number[j].to_digit(10).unwrap() * 2;
                number[j] = if res > 9 {std::char::from_digit(res - 9, 10).unwrap()} else {std::char::from_digit(res, 10).unwrap()};
           }
        };
    number.iter().filter_map(|n| n.to_digit(10)).sum::<u32>() % 10 == 0
}

