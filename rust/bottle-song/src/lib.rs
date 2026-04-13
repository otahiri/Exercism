pub fn num_to_name(num: u32) -> String {
    match num {
        10 => "Ten".to_string(),
        9 => "Nine".to_string(),
        8 => "Eight".to_string(),
        7 => "Seven".to_string(),
        6 => "Six".to_string(),
        5 => "Five".to_string(),
        4 => "Four".to_string(),
        3 => "Three".to_string(),
        2 => "Two".to_string(),
        1 => "One".to_string(),
        _ => "not a digit".to_string(),
    }
}

macro_rules!  first_line{
    ($val:expr) => {{
        let s = if $val > 1 {"s"} else { ""};
        let res: String = format!("{} green bottle{} hanging on the wall,\n", num_to_name($val), s);
        res
        }};
}

macro_rules!  last_line{
    ($val:expr) => {{
        *$val -= 1;
        let s = if *$val > 1 {"s"} else { ""};
        let res: String;
        res = if *$val > 0 {format!("There'll be {} green bottle{} hanging on the wall.\n", num_to_name(*$val).to_lowercase(), s)} else { "There'll be no green bottles hanging on the wall.\n".to_string()};
        res
        }};
}
pub fn recite(start_bottles: u32, take_down: u32) -> String {
    let mut res:Vec<String> = Vec::new();
    let mut num: u32 = start_bottles;
    for _ in 0..take_down {
        res.push(first_line!(num));
        res.push(first_line!(num));
        res.push("And if one green bottle should accidentally fall,\n".to_string());
        res.push(last_line!(&mut num));
        res.push("\n".to_string());
    }
    res.join("")
}
