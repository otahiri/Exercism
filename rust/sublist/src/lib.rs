#[derive(Debug, PartialEq, Eq)]
pub enum Comparison {
    Equal,
    Sublist,
    Superlist,
    Unequal,
}

pub fn sublist(first_list: &[i32], second_list: &[i32]) -> Comparison {
    if first_list == second_list{
        return Comparison::Equal
    }
    if first_list.len() == 0 || second_list.len() == 0{
        if first_list.len() == second_list.len() {
            return Comparison::Unequal
        } else {
            if first_list.len() == 0{
                return Comparison::Sublist
            }
            else if second_list.len() == 0 {
                return Comparison::Superlist
            }
        }
    }
    let (bigger, smaller, sup) = if first_list.len() > second_list.len() {
        (first_list, second_list, true)
    } else{
        (second_list, first_list, false)
    };
    for list in bigger.windows(smaller.len()){
        if list == smaller {
            if sup {
                return Comparison::Superlist

            } else {
                return Comparison::Sublist
            }

        }
    }
    Comparison::Unequal
}
