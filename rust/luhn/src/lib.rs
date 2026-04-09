/// Check a Luhn checksum.
pub fn is_valid(code: &str) -> bool {
    if code.len() == 0 {
        return false;
    }
    let mut number: Vec<Vec<char>> = code.split(' ').map(|s| s.chars().collect()).collect();
    for i in 0..number.len() {
        for j in 0..number[i].len() {
            if j % 2 == 1 {
                let res: u32 = number[i][i].to_digit(10).expect("bitch ass") ;
                number[i][j] = if res > 9 {std::char::from_u32(res - 9).expect("bitch ass")} else {std::char::from_u32(res).expect("hell no")};
           }
        }
    };
    number.iter().flatten().filter_map(|n| n.to_digit(10)).sum::<u32>() % 10 == 0

}
