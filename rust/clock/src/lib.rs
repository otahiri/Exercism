use std::fmt;
#[derive(Debug, PartialEq, Eq)]
pub struct Clock
{
    hours: i32,
    minutes:i32,
}

impl Clock {
    pub fn new(hours: i32, minutes: i32) -> Self {
        let mut total: i32 = (hours * 60) + minutes;
        total %= 1440;
        total = total.rem_euclid(1440);
        Clock { hours: total / 60,
        minutes: total % 60,
        }
    }

    pub fn add_minutes(&self, minutes: i32) -> Self {
        let mut total: i32 = (self.hours * 60) + self.minutes + minutes;
        total %= 1440;
        total = total.rem_euclid(1440);
        Clock { hours: total / 60,
        minutes: total % 60,
        }
    }
}

impl fmt::Display for Clock {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result
    {
        write!(f, "{:02}:{:02}", self.hours, self.minutes)
    }
}

