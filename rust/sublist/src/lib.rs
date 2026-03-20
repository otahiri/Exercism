#[derive(Debug, PartialEq, Eq)]
pub enum Comparison {
    Equal,
    Sublist,
    Superlist,
    Unequal,
}

pub fn sublist(first_list: &[i32], second_list: &[i32]) -> Comparison {
    let bigger:&[i32];
    let smaller:&[i32];
    let sup: bool;

    let (bigger, smaller, sup) = if first_list.len() > second_list.len(){
        (first_list, second_list, true);
    } else{
        (second_list, first_list, false);
    };
    return
}
