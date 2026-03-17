use std::collections::HashSet;
macro_rules! s_sort {
    ($s:expr) => {
        {
        let mut v: Vec<char> = $s.chars().collect();
        v.sort_unstable();
        v
        }
    };
}

pub fn anagrams_for<'a>(word: &str, possible_anagrams: &[&'a str]) -> HashSet<&'a str> {
    let mut set: HashSet<&'a str> = HashSet::new();
    for w in possible_anagrams
    {
        if s_sort!(w) == s_sort!(word)
        {
            set.insert(w);
        }
    }
    set
}
