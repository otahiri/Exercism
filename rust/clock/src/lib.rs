use std::fmt;
#[derive(PartialEq)]
pub struct Clock
{
    pub hours: i32,
    pub minutes: i32,
}

impl Clock {
    pub fn new(hours: i32, minutes: i32) -> Self {
        let temp: i32 = minutes + (hours * 60);
        let rolled_minute = ((temp % 1440) + 1440) % 1440;
        let minute = rolled_minute % 60;
        let hour = rolled_minute / 60;
        Clock {hours: hour, minutes: minute}
    }

    pub fn add_minutes(&self, minutes: i32) -> Self {
        let mut temp: i32 = (self.minutes * 60) + self.minutes;
        temp += minutes;
        let rolled_minute = ((temp % 1440) + 1440) % 1440;
        let minute = rolled_minute % 60;
        let hour = rolled_minute / 60;
        Clock {hours: hour, minutes: minute}
    }

           }
