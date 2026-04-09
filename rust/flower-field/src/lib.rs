
pub fn count_chars(garden: &Vec<Vec<char>>, y: isize, x: isize) -> usize {
    let directions: [(isize, isize); 8] = [(-1, -1), (1, 1), (1, -1), (-1, 1), (1, 0), (-1, 0), (0, 1), (0, -1), ];
    let width: isize = garden.len() as isize;
    let height: isize = garden[x as usize].len() as isize;
    let mut total: usize = 0;
    for (dy, dx) in directions {
        if 0 <= (dy + y) && (dy + y) < height && 0 <= (dx + x) && (dx + x) < width {
            if garden[(dx + x) as usize][(dy + y) as usize] == '*' {
            total += 1;
            }
        }
    }
    total
}

pub fn annotate(garden: &[&str]) -> Vec<String> {
    let mut s: Vec<Vec<char>> = garden.iter().map(|s| s.chars().collect()).collect();
    for i in 0..s.len() {
        for j in 0..s[0].len() {
             if s[i][j] == ' '  {
                 let res: u32 = count_chars(&s, j as isize, i as isize) as u32;
                s[i][j] = if res > 0 {char::from_digit(res as u32, 10).unwrap()} else {' '};
            }
        }
    }
    s.iter().map(|row| row.iter().collect::<String>()).collect()
}
