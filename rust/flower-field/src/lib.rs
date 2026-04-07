macro_rules! count {
    ($garden:expr, $i:expr, $j:expr) => {{
        let mut total = 0;
        let max_height: i32 = $garden.len() as i32;
        let max_width: i32 = $garden[0].len() as i32;
        let row: String = $garden[$i].to_owned();
        total += (($i  - 1) >= 0 && $garden[$i - 1][$j] == '*') as i32;
        total += (($j  - 1) >= 0 && row.chars().nth($j) == Some('*')) as i32;
        total += (($j  - 1) >= 0 && ($i - 1) >= 0 && row.chars().nth($j - 1) == Some('*')) as i32;
        total += (($i  + 1) < max_hight && $garden[$i + 1][$j] == '*') as i32;
        total += (($j  + 1) < max_width && $garden[$i][$j + 1] == '*') as i32;
        total += (($j  + 1) < max_width && ($i + 1) < max_hight && $garden[$i + 1][$j + 1] == '*') as i32;
        total += (($j  - 1) >= 0 && ($i + 1) < max_hight && $garden[$i + 1][$j + 1] == '*') as i32;
        total += (($i  - 1) >= 0 && ($j + 1) < max_width && $garden[$i - 1][$j + 1] == '*') as i32;
        total += (($j  - 1) >= 0 && ($i + 1) < max_height && $garden[$i + 1][$j - 1] == '*') as i32;
        total
    }};
}

pub fn annotate(garden: &[&str]) -> Vec<String> {
    let res: Vec<String>;
    for i in 0..garden.len() {
        let row: String = garden[i].to_owned();
        for j in 0..garden[0].len() {
            if row.chars().nth(j) == Some('*') {
                res[i].push('*')
            }
            else if row.chars().nth(j) == Some(' ') {
                res[i].push(count!(garden, i, j));
            }
        }
    }
    res
}
